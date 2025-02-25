/*--------------------------------------------------------------------------
 * File:  sys_xtuml.cpp
 *
 * Description:
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "TypeUnit_sys_types.h"


/*
 * Supply a unique integer ID.
 */
Escher_UniqueID_t
Escher_ID_factory( void )
{
  static Escher_UniqueID_t Escher_ID_factory = 1;
  return Escher_ID_factory++;
}

/*
 * Detect empty handles in expressions.
 */
void * xtUML_detect_empty_handle( void * h, const char * s1, const char * s2 )
{
  if ( 0 == h ) {
    XTUML_EMPTY_HANDLE_TRACE( s1, s2 );
  }
  return h;
}

/*
 * Initialize the node1 instances by linking them into a collection.
 * These containoids will be collected into a null-terminated,
 * singly linked list (slist).
 * This needs to be called during architecture initialization.
 */
void
sys_sets::Escher_SetFactoryInit( const i_t n1_size )
{
  Escher_size_t i;
  node1_FreeList.head = &node1s[ 0 ];
  /* Build the collection (linked list) of node1 instances.  */
  for ( i = 0; ( i + 1 ) < n1_size; i++ ) {
    node1s[ i ].next = &node1s[ i + 1 ];
    node1s[ i ].object = 0;
  }
  node1s[ n1_size - 1 ].next = 0;
}

/*
 * This will copy all of the elements from one set into another
 * set.  If the target set is not empty, it will be cleared
 * before the copy operation occurs freeing any nodes in that set.
 * The new set will use containoids from the free list.
 */
void 
sys_sets::Escher_CopySet( Escher_ObjectSet_s * to_set,
                const Escher_ObjectSet_s * const from_set )
{
  const Escher_SetElement_s * slot;

  /* May be copying into an existing set, release target collection nodes.  */
  Escher_ClearSet( to_set );

  for ( slot = from_set->head; ( slot != 0 ); slot = slot->next ) {
    Escher_SetInsertElement( to_set, slot->object ); 
  }
}

/*
 * Release all nodes in the given set back to the free pool.
 */
void
sys_sets::Escher_ClearSet( Escher_ObjectSet_s * set )
{
  if ( set->head != 0 ) {                                    /* empty set  */
    Escher_SetElement_s * slot;
    for ( slot = set->head; ( slot->next != 0 ); slot = slot->next ); /* Find end.  */
    slot->next = node1_FreeList.head;     /* Tie string to free list.      */
    node1_FreeList.head = set->head;      /* Point free list to head.      */
    Escher_InitSet( set );                /* Zero set out.  */
  }
}

/*
 * Take the union of set1 and set2 and return to_set
 */
Escher_ObjectSet_s *
sys_sets::( Escher_ObjectSet_s * const to_set, void * const set1, void * const set2, int flags )
{
  if ( 0 != to_set ) {
    /* Assure that the result set starts empty */
    Escher_ClearSet( to_set );
    /* Copy set1 to the result set */
    if ( 0 != set1 ) {
      if ( flags & ESCHER_SET_LHS_IS_INSTANCE ) {
        Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), set1 );
      }
      else {
        sys_sets::Escher_CopySet( to_set, set1 );
      }
    }
    /* Add any elements from set2 which are not already in the result set */
    if ( 0 != set2 ) {
      if ( flags & ESCHER_SET_RHS_IS_INSTANCE ) {
        if ( !sys_sets::Escher_SetContains( to_set, set2 ) ) Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), set2 );
      }
      else {
        Escher_SetElement_s * slot;
        for ( slot = ((Escher_ObjectSet_s*)set2)->head; ( slot != 0 ); slot = slot->next ) {
          if ( !sys_sets::Escher_SetContains( to_set, slot->object ) ) {
            Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), slot->object );
          }
        }
      }
    }
  }
  return to_set;
}

/*
 * Take the intersection of set1 and set2 and return to_set
 */
Escher_ObjectSet_s *
sys_sets::( Escher_ObjectSet_s * const to_set, void * const set1, void * const set2, int flags )
{
  if ( 0 != to_set ) {
    /* Assure that the result set starts empty */
    Escher_ClearSet( to_set );
    if ( 0 != set1 && 0 != set2) {
      /* If both sets are single instances, only add to the result set if they are the same instance */
      if ( ( flags & ESCHER_SET_LHS_IS_INSTANCE ) && ( flags & ESCHER_SET_RHS_IS_INSTANCE ) ) {
        if ( set1 == set2 ) Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), set1 );
      }
      /* If set1 is a single instance, add it to the result set if it is contained in set2 */
      else if ( flags & ESCHER_SET_LHS_IS_INSTANCE ) {
        if ( sys_sets::Escher_SetContains( set2, set1 ) ) Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), set1 );
      }
      /* If set2 is a single instance, add it to the result set if it is contained in set1 */
      else if ( flags & ESCHER_SET_RHS_IS_INSTANCE ) {
        if ( sys_sets::Escher_SetContains( set1, set2 ) ) Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), set2 );
      }
      /* For each instance in set1, add it to the result set if it is contained in set2 */
      else {
        Escher_SetElement_s * slot;
        for ( slot = ((Escher_ObjectSet_s*)set1)->head; ( slot != 0 ); slot = slot->next ) {
          if ( sys_sets::Escher_SetContains( set2, slot->object ) ) {
            Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), slot->object );
          }
        }
      }
    }
  }
  return to_set;
}

/*
 * Subtract set2 from set1 and return to_set
 */
Escher_ObjectSet_s *
sys_sets::( Escher_ObjectSet_s * const to_set, void * const set1, void * const set2, int flags )
{
  if ( 0 != to_set ) {
    /* Assure that the result set starts empty */
    Escher_ClearSet( to_set );
    if ( 0 != set1 ) {
      if ( flags & ESCHER_SET_LHS_IS_INSTANCE ) {
        /* If both sets are single instances, only add set1 to the result set if they are not the same instance */
        if ( flags & ESCHER_SET_RHS_IS_INSTANCE ) {
          if ( set1 != set2 ) Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), set1 );
        }
        /* If set1 is a single instance, only add it to the result set if it is not contained in set2 */
        else {
          if ( 0 != set2 && !sys_sets::Escher_SetContains( set2, set1 ) ) Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), set1 );
        }
      }
      else {
        /* For each element in set1, check if it is also in set2 */
        Escher_SetElement_s * slot;
        for ( slot = ((Escher_ObjectSet_s*)set1)->head; ( slot != 0 ); slot = slot->next ) {
          /* If set2 is a single instance, add the the set1 instance to the result set only if they are not the same instance */
          if ( flags & ESCHER_SET_RHS_IS_INSTANCE ) {
            if ( slot->object != set2 ) Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), slot->object );
          }
          /* Only add the set1 instance to the result set if it is not contained in set2 */
          else {
            if ( 0 != set2 && !sys_sets::Escher_SetContains( set2, slot->object ) ) Escher_SetInsertElement( ((Escher_ObjectSet_s*)to_set), slot->object );
          }
        }
      }
    }
  }
  return to_set;
}

/*
 * Take the symmetric difference of set1 and set2 and return to_set
 */
Escher_ObjectSet_s *
sys_sets::( Escher_ObjectSet_s * const to_set, void * const set1, void * const set2, int flags )
{
  /* Symmetric difference is the difference of the union and the intersection */
  sys_sets::Escher_ObjectSet_s union_set={0};
  sys_sets::Escher_ObjectSet_s intersection_set={0};
  sys_sets::( to_set, sys_sets::( &union_set, set1, set2, flags ), sys_sets::( &intersection_set, set1, set2, flags ), 0 );
  thismodule->Escher_ClearSet( &union_set );
  thismodule->Escher_ClearSet( &intersection_set );
  return to_set;
}

/*
 * Insert a single element into the set in no particular order.
 * The element is a data item.  A container node will be allocated
 * to link in the element.
 */
void
sys_sets::Escher_SetInsertElement(
  Escher_ObjectSet_s * set,
  void * const substance
)
{
  Escher_SetElement_s * slot;
  if ( 0 == node1_FreeList.head ) {
    UserNodeListEmptyCallout(); /* Bad news!  No more nodes.         */
  }
  slot = node1_FreeList.head; /* Extract node from free list head. */
  node1_FreeList.head = node1_FreeList.head->next;
  slot->object = substance;
  slot->next = set->head;     /* Insert substance at list front.   */
  set->head = slot;
}

/*
 * Insert a block of objects into the given set in sequence.  Link the
 * data into the supplied containers.
 * Return a pointer to the linked set.
 */
sys_sets::Escher_SetElement_s *
sys_sets::Escher_SetInsertBlock( Escher_SetElement_s * container,
                       const u1_t * instance,
                       const Escher_size_t length,
                       Escher_size_t count )
{
  Escher_SetElement_s * head = ( count > 0 ) ? container : 0;
  while ( count > 0 ) {
    count--;
    container->object = (void *) instance;  /* Link in the object data.     */
    instance = instance + length;           /* Bump to next object image.   */
    /* String together or ground containoids.  */
    container->next = ( count > 0 ) ? container + 1 : 0;
    container++;
  }
  return head;
}

/*
 * Remove an instance from an instance collection.
 */
/* Signature:  void Escher_SetRemoveInstance( pextent, instance, slot, container, pool ) */

/*
 * Insert an instance onto an extent.
 */
/* Signature:  void Escher_SetInsertInstance( pextent, node ) */


/*
 * Remove a data item from the given set.  This requires searching
 * the set for the item, unlinking the item (if found) and returning
 * the pointer to the removed node.  SetRemoveNode is used
 * when some knowledge of the linking mechanism is required (as
 * in extent management).  SetRemoveElement is used whenever
 * possible.
 */
sys_sets::Escher_SetElement_s *
sys_sets::Escher_SetRemoveNode(
  Escher_ObjectSet_s * set,
  const void * const d
)
{
  Escher_SetElement_s * t = set->head; /* Start with first node.           */
  Escher_SetElement_s * t_old = t;
  /* Find node containing data and unlink from list.                 */
  if ( t->object == d ) {        /* Element found at head.           */
    set->head = t->next;         /* Unlink it from the list.         */
  } else {
    do {                         /* Search for data element.         */
      t_old = t;
      t = t->next;
      if ( t == 0 ) { return 0; } /* absent       */
    } while ( t->object != d );
    t_old->next = t->next;      /* Unlink element from the list.     */
  }
  return t;
}

/*
 * This interface is used more often to remove an element.  This is
 * used when maximum anonymity is required.  Escher_SetRemoveNode is
 * used when some knowledge of the linking mechanism is required (as
 * in extent management).
 */
void
sys_sets::Escher_SetRemoveElement(
  Escher_ObjectSet_s * set,
  const void * const d
)
{
  Escher_SetElement_s * t;
  if ( set->head != 0 ) {                     /* empty set */
    t = Escher_SetRemoveNode( set, d );
    /* Return node to architecture collection (free list).             */
    if ( t != 0 ) {
      t->next = node1_FreeList.head;
      node1_FreeList.head = t;
    }
  }
}

/*
 * Return a pointer to the found element when the set contains the 
 * given data element.
 */
const void *
sys_sets::Escher_SetContains(
  const Escher_ObjectSet_s * const set,
  const void * const element
)
{
  const Escher_SetElement_s * node = set->head;
  while ( node != 0 ) {
    if ( node->object == element ) { return node; }  /* found  */
    node = node->next;
  }
  if ( 0 == element ) return ( const void * ) 1; /* every set contains null */
  return 0;                                      /* absent */
}

/*
 * Count the elements in the set.  Return that count.
 * This routine counts nodes.
 */
Escher_size_t
sys_sets::Escher_SetCardinality( const Escher_ObjectSet_s * const set )
{
  Escher_size_t result = 0;
  const Escher_SetElement_s * node = set->head;
  while ( node != 0 ) {
    result++;
    node = node->next;
  }
  return result;
}

/*
 * Return true when the left and right set are equivalent.
 * The left set is equal to the right set if and only if
 * the left set contains all elements of the right set AND
 * the right set contains all elements of the left set.
 */
bool
sys_sets::Escher_SetEquality( Escher_ObjectSet_s * const left_set,
                    Escher_ObjectSet_s * const right_set )
{
  bool rc = true;
  /* Assure the right set contains all elements in the left set */
  const Escher_SetElement_s * node = left_set->head;
  while ( 0 != node ) {
    if ( 0 == right_set || !sys_sets::Escher_SetContains( right_set, node->object ) ) {
      rc = false;
      break;
    }
    node = node->next;
  }
  if ( rc ) {
    /* Assure the left set contains all elements in the right set */
    node = right_set->head;
    while ( 0 != node ) {
      if ( 0 == left_set || !sys_sets::Escher_SetContains( left_set, node->object ) ) {
        rc = false;
        break;
      }
      node = node->next;
    }
  }
  return rc;
}

/*
 * Initialize a set variable.
 */
/* Signature:  void Escher_InitSet( Escher_ObjectSet_s * set ) */

/*
 * Get any element (1st) from a collection.
 */
/* Signature:  void * Escher_SetGetAny( Escher_ObjectSet_s * const set ) */

/*
 * Return true if set is empty.
 */
/* Signature:  bool Escher_SetIsEmpty( const Escher_ObjectSet_s * const set ) */

/*
 * Use this method to reset the cursor.
 */
/* Signature:  void Escher_IteratorReset( Escher_Iterator_s * const iterator,
 *                                        Escher_ObjectSet_s * const set )
 */

/*
 * Interate to the next element and return it.
 */
void *
sys_sets::Escher_IteratorNext( Escher_Iterator_s * const iter )
{
  void * element = 0;
  if ( iter->cursor != 0 ) {
    element = iter->cursor->object;
    iter->cursor = iter->cursor->next;
  }
  return element;
}

/*
 * Set memory bytes to value at destination.
 */
void
sys_sets::Escher_memset( void * const dst, const u1_t val, Escher_size_t len )
{
  u1_t * d = (u1_t *) dst;
  while ( len > 0 ) {
    len--;
    *d++ = val;
  }
}

/*
 * Move memory bytes from source to destination.
 */
void
sys_sets::Escher_memmove( void * const dst, const void * const src, Escher_size_t len )
{
  u1_t * s = (u1_t *) src;
  u1_t * d = (u1_t *) dst;
  while ( len > 0 ) {
    len--;
    *d++ = *s++;
  }
}

/*
 * Copy characters and be paranoid about null delimiter.
 */
c_t *
sys_sets::Escher_strcpy( c_t * dst, const c_t * src )
{
  c_t * s = dst;
  if ( ( 0 != src ) && ( 0 != dst ) ) {
    Escher_size_t i = ESCHER_SYS_MAX_STRING_LEN - 1;
    while ( ( i > 0 ) && ( *src != '\0' ) ) {
      --i;
      *dst++ = *src++;
    }
    *dst = '\0';  /* Ensure delimiter.  */
  }
  return s;
}

/*
 * Add two strings.  Allocate a temporary memory variable to return the value.
 */
c_t *
sys_sets::Escher_stradd( const c_t * left, const c_t * right )
{
  Escher_size_t i = ESCHER_SYS_MAX_STRING_LEN - 1;
  c_t * s = sys_sets::Escher_strget();
  c_t * dst = s;
  if ( 0 == left ) left = "";
  if ( 0 == right ) right = "";
  while ( ( i > 0 ) && ( *left != '\0' ) ) {
    --i;
    *dst++ = *left++;
  }
  while ( ( i > 0 ) && ( *right != '\0' ) ) {
    --i;
    *dst++ = *right++;
  }
  *dst = '\0';  /* Ensure delimiter.  */
  return s;
}

/*
 * Compare two strings.
 * Return negative number if s1 < s2.
 * Return zero if s1 == s2.
 * Return postive number if s1 > s2.
 */
c_t
sys_sets::Escher_strcmp( const c_t *p1, const c_t *p2 )
{
  const c_t *s1 = p1;
  const c_t *s2 = p2;
  c_t c1, c2;
  i_t i = ESCHER_SYS_MAX_STRING_LEN;
  do {
    c1 = *s1++;
    c2 = *s2++;
    if ( c1 == 0 ) { break; }
    --i;
  } while ( ( c1 == c2 ) && ( i >= 0 ) );
  return ( c1 - c2 );
}

/*
 * Return a string buffer.  Rotate through a pool.
 */
c_t *
sys_sets::Escher_strget( void )
{
  c_t * r;
  static u1_t i = 0;
  static c_t s[ 32 ][ ESCHER_SYS_MAX_STRING_LEN ];
  i = ( i + 1 ) % 32;
  r = &s[ i ][ 0 ];
  *r = 0;
  return ( r );
}



/*
 * Create an instance of the class numbered on the input.
 * Return the handle of the created instance.
 */
Escher_iHandle_t
sys_factory::Escher_CreateInstance(
  const Escher_DomainNumber_t domain_num,
  const Escher_ClassNumber_t class_num
)
{
  Escher_SetElement_s * node;
  Escher_iHandle_t instance;
  Escher_Extent_t * dci = Escher_GetDCI(class_num);
  node = dci->inactive.head;

  if ( 0 == node ) {
    UserObjectPoolEmptyCallout( domain_num, class_num );
  }

  dci->inactive.head = dci->inactive.head->next;
  instance = (Escher_iHandle_t) node->object;
  if ( 0 != dci->initial_state ) {
    instance->current_state = dci->initial_state;
  }
  Escher_SetInsertInstance( &dci->active, node );
  return instance;
}

/*
 * Delete an instance of the class passed and numbered on the input.
 */
void
sys_factory::Escher_DeleteInstance(
  Escher_iHandle_t instance,
  const Escher_DomainNumber_t domain_num,
  const Escher_ClassNumber_t class_num
)
{
  Escher_SetElement_s * node;
  Escher_Extent_t * dci = Escher_GetDCI(class_num);
  if ( 0 != instance ) {
    node = Escher_SetRemoveNode( &dci->active, instance );
    node->next = dci->inactive.head;
    dci->inactive.head = node;
    /* Initialize storage to zero.  */
    Escher_memset( instance, 0, dci->size );
    if ( ( 0 != dci->size ) && ( 0 != dci->initial_state ) ) {
      instance->current_state = -1; /* 0xff max for error detection */
    }
  }
}

/*
 * Initialize object factory services.
 * Initialize class instance storage free pool (inanimate list)
 * by linking the empty instances into a collection.
 */
void
sys_factory::Escher_ClassFactoryInit(
  const Escher_DomainNumber_t domain_num,
  const Escher_ClassNumber_t class_num )
{
  Escher_Extent_t * dci = Escher_GetDCI(class_num);
  if ( 0 != dci ) {
  dci->active.head = 0;
  dci->inactive.head = Escher_SetInsertBlock(
    dci->container,
    (const u1_t *) dci->pool,
    dci->size,
    dci->population );
  }
}
/*
 * Following provides the dispatcher loops for the xtUML event queues.
 */


/*
 * Link the event skeleton nodes together on the free list ready
 * for allocation.
 */
void
sys_events::InitializeOoaEventPool( i_t max_event_size, i_t event_pool_length )
{
  /* Pre-allocated memory pool for xtUML events.  */
  u2_t i;
  Escher_run_flag = true; /* Default running enabled.  */
  non_self_event_queue[ 0 ].head = 0; non_self_event_queue[ 0 ].tail = 0;
  /* String events together into a singly linked list. */
  free_event_list = (Escher_xtUMLEvent_t *) Escher_xtUML_event_pool;
  char * pool_head = (char *) Escher_xtUML_event_pool; // Use a byte-length pointer for the upcoming pointer math
  for ( i = 0; i < event_pool_length; i++ ) {
    ((Escher_systemxtUMLevents_t *) (pool_head + (i * max_event_size)))->mc_event_base.next =
      (Escher_xtUMLEvent_t *) (pool_head + ((i+1) * max_event_size));
  }
  ((Escher_systemxtUMLevents_t *) (pool_head + ((event_pool_length - 1) * max_event_size)))->mc_event_base.next = 0;
}

/*
 * Obtain an empty event from the free list.
 */
Escher_xtUMLEvent_t * sys_events::Escher_AllocatextUMLEvent( void )
{
  Escher_xtUMLEvent_t * event = 0;
  if ( 0 == free_event_list ) {
    UserEventFreeListEmptyCallout();   /* Bad news!  No more events.  */
  } else {
    event = free_event_list;       /* Grab front of the free list.  */
    free_event_list = event->next; /* Unlink from front of free list.  */
  }
  return event;
}

/*
 * Allocate the event and initialize the base attributes.
 */
Escher_xtUMLEvent_t *
sys_events::Escher_NewxtUMLEvent( const void * const destination,
                   const Escher_xtUMLEventConstant_t * const event_info )
{
  Escher_xtUMLEvent_t * event = Escher_AllocatextUMLEvent();
  SetEventTargetInstance( event, destination );
  SetEventDestDomainNumber( event, event_info->destination_domain_number );
  SetEventDestObjectNumber( event, event_info->destination_object_number );
  SetOoaEventNumber( event, event_info->event_number );
  SetOoaEventFlags( event, event_info->event_flags );
  event->thismodule = this;
  return event;
}

/*
 * Update the base attributes of an event for polymorphic processing.
 */
Escher_xtUMLEvent_t *
sys_events::Escher_ModifyxtUMLEvent( Escher_xtUMLEvent_t * event,
                            const Escher_xtUMLEventConstant_t * const event_info )
{
  SetEventDestDomainNumber( event, event_info->destination_domain_number );
  SetEventDestObjectNumber( event, event_info->destination_object_number );
  SetOoaEventNumber( event, event_info->event_number );
  SetOoaEventFlags( event, event_info->event_flags );
  event->thismodule = event_info->thismodule;
  return event;
}

/*
 * Delete an event by moving it onto the free list.
 */
void
sys_events::Escher_DeletextUMLEvent( Escher_xtUMLEvent_t * event )
{
  event->next = free_event_list;
  free_event_list = event;
}

/*
 * Send an event to the instance queue.  Use priority where applicable.
 *
 * The following table summarizes the construction of events
 * as expected in Escher.  For each type of object that
 * may be the source or target of an event, the expected
 * value of the source and destination handles in the event are
 * given.
 *
 *   object type | as event source     | as destination
 *   ------------+---------------------+----------------------
 *   instance    | handle              | handle
 *   class       | manufactured handle | 0
 *   creator     | manufactured handle | 0
 */
void
sys_events::Escher_SendEvent( Escher_xtUMLEvent_t * event )
{
  xtUMLEventQueue_t * q = &non_self_event_queue[ 0 ];
  event->next = 0;
  /* Append the event to the tail end of the queue.  */
  /* No need to maintain prev pointers when not prioritizing.  */
  if ( q->tail == 0 ) {
    q->head = event;
  } else {
    q->tail->next = event;
  }
  q->tail = event;
}

/*
 * Drag an event from the instance directed queue if there is one.  This
 * routine also serves as the IsQueueEmpty routine.  A null return code 
 * indicates that the queue is empty.  Otherwise the handle to the
 * event will be returned.
 */
Escher_xtUMLEvent_t * sys_events::DequeueOoaNonSelfEvent( void )
{
  Escher_xtUMLEvent_t * event;
  xtUMLEventQueue_t * q = &non_self_event_queue[ 0 ];
  /* Assign the event from the head of the queue.  */
  event = q->head;
  /* If the list is not empty, bump the head.  */
  if ( event != 0 ) {
    q->head = event->next;
    /* If empty, nullify tail.  Link prev pointers (if needed).  */
    if ( q->head == 0 ) {
      q->tail = 0;
    }
  } else {
    UserNonSelfEventQueueEmptyCallout();
  }
  return event;
}
/*
 * Loop on the event queues dispatching events for this thread.
 */
void sys_events::ooa_loop( void * thismodule )
{
  Escher_xtUMLEvent_t * event;
  /* Start consuming events and dispatching background processes.  */
  if ( true == Escher_run_flag ) {
    event = DequeueOoaNonSelfEvent(); /* Instance next.  */
    if ( 0 != event ) {
      event->thismodule = thismodule;
      ( *( Escher_GetEventDispatcher() )[ GetEventDestObjectNumber( event ) ] )( event );
      Escher_DeletextUMLEvent( event );
    } else {
      /* event queues empty */
    }
    UserBackgroundProcessingCallout();
  }
}

