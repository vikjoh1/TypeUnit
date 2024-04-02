/*----------------------------------------------------------------------------
 * File:  Component_WasRun_class.cpp
 *
 * Class:       WasRun  (WasRun)
 * Component:   Component
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "TypeUnit_sys_types.h"
#include "Component.h"

/*
 * instance operation:  run
 */
void
Component_WasRun::Component_WasRun_op_run( Component_WasRun * self, Component * thismodule)
{
  Component_WasRun * v_Test;
  /* CREATE OBJECT INSTANCE Test OF WasRun */
  XTUML_OAL_STMT_TRACE( 1, "CREATE OBJECT INSTANCE Test OF WasRun" );
  v_Test = (Component_WasRun *) thismodule->Escher_CreateInstance( Component_DOMAIN_ID, Component_WasRun_CLASS_NUMBER );
}

/*
 * instance operation:  setUp
 */
void
Component_WasRun::Component_WasRun_op_setUp( Component_WasRun * self, Component * thismodule)
{

}


/*----------------------------------------------------------------------------
 * Operation action methods implementation for the following class:
 *
 * Class:      WasRun  (WasRun)
 * Component:  Component
 *--------------------------------------------------------------------------*/
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static sys_sets::Escher_SetElement_s Component_WasRun_container[ Component_WasRun_MAX_EXTENT_SIZE ];
static Component_WasRun Component_WasRun_instances[ Component_WasRun_MAX_EXTENT_SIZE ];
sys_sets::Escher_Extent_t pG_Component_WasRun_extent = {
  {0}, {0}, &Component_WasRun_container[ 0 ],
  (Escher_iHandle_t) &Component_WasRun_instances,
  sizeof( Component_WasRun ), Component_WasRun_STATE_1, Component_WasRun_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      WasRun  (WasRun)
 * Component:  Component
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [NotRun]
 */
static void Component_WasRun_act1( Component_WasRun *, const Escher_xtUMLEvent_t * const );
static void
Component_WasRun_act1( Component_WasRun * self, const Escher_xtUMLEvent_t * const event )
{
  Component * thismodule = (Component *) event->thismodule;
}

/*
 * State 2:  [Running]
 */
static void Component_WasRun_act2( Component_WasRun *, const Escher_xtUMLEvent_t * const );
static void
Component_WasRun_act2( Component_WasRun * self, const Escher_xtUMLEvent_t * const event )
{
  Component * thismodule = (Component *) event->thismodule;
}

/*
 * State 3:  [Passed]
 */
static void Component_WasRun_act3( Component_WasRun *, const Escher_xtUMLEvent_t * const );
static void
Component_WasRun_act3( Component_WasRun * self, const Escher_xtUMLEvent_t * const event )
{
  Component * thismodule = (Component *) event->thismodule;
}

/*
 * State 4:  [Failed]
 */
static void Component_WasRun_act4( Component_WasRun *, const Escher_xtUMLEvent_t * const );
static void
Component_WasRun_act4( Component_WasRun * self, const Escher_xtUMLEvent_t * const event )
{
  Component * thismodule = (Component *) event->thismodule;
}


const Escher_xtUMLEventConstant_t Component_WasRunevent2c = {
  Component_DOMAIN_ID, Component_WasRun_CLASS_NUMBER, COMPONENT_WASRUNEVENT2NUM,
  ESCHER_IS_INSTANCE_EVENT, 0 };




/*
 * State-Event Matrix (SEM)
 * Row index is object (MC enumerated) current state.
 * Row zero is the uninitialized state (e.g., for creation event transitions).
 * Column index is (MC enumerated) state machine events.
 */
static const Escher_SEMcell_t Component_WasRun_StateEventMatrix[ 4 + 1 ][ 1 ] = {
  /* row 0:  uninitialized state (for creation events) */
  { EVENT_CANT_HAPPEN },
  /* row 1:  Component_WasRun_STATE_1 (NotRun) */
  { Component_WasRun_STATE_2 },
  /* row 2:  Component_WasRun_STATE_2 (Running) */
  { EVENT_CANT_HAPPEN },
  /* row 3:  Component_WasRun_STATE_3 (Passed) */
  { EVENT_CANT_HAPPEN },
  /* row 4:  Component_WasRun_STATE_4 (Failed) */
  { EVENT_CANT_HAPPEN }
};

  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t Component_WasRun_acts[ 5 ] = {
    (StateAction_t) 0,
    (StateAction_t) Component_WasRun_act1,  /* NotRun */
    (StateAction_t) Component_WasRun_act2,  /* Running */
    (StateAction_t) Component_WasRun_act3,  /* Passed */
    (StateAction_t) Component_WasRun_act4  /* Failed */
  };

  /*
   * Array of string names of the state machine names.
   * Index is the (MC enumerated) number of the state.
   */
  static const c_t * const state_name_strings[ 5 ] = {
    "",
    "NotRun",
    "Running",
    "Passed",
    "Failed"
  };

/*
 * instance state machine event dispatching
 */
void
Component_WasRun_Dispatch( Escher_xtUMLEvent_t * event )
{
  Component * thismodule = (Component *) event->thismodule;
  Escher_iHandle_t instance;
  Escher_EventNumber_t event_number = GetOoaEventNumber( event );
  Escher_StateNumber_t current_state;
  Escher_StateNumber_t next_state;
  if ( 0 != GetIsCreationEvent( event ) ) {
    instance = thismodule->Escher_CreateInstance( Component_DOMAIN_ID, Component_WasRun_CLASS_NUMBER );
    if ( 0 != instance ) {
      instance->current_state = UNINITIALIZED_STATE;
      SetEventTargetInstance( event, instance );
    } else {
      /* Instance allocation failure - USER RECOVERY LOGIC IS TBD */
      UserEventNoInstanceCallout( 0 );
    }
  } else {
    instance = GetEventTargetInstance( event );
  }
  if ( 0 != instance ) {
    current_state = instance->current_state;
    if ( current_state > 4 ) {
      /* instance validation failure (object deleted while event in flight) */
      UserEventNoInstanceCallout( event_number );
    } else {
      next_state = Component_WasRun_StateEventMatrix[ current_state ][ event_number ];
      if ( next_state <= 4 ) {
        STATE_TXN_START_TRACE( "WasRun", current_state, state_name_strings[ current_state ] );
        /* Update the current state and execute the state action.  */
        instance->current_state = next_state;
        ( *Component_WasRun_acts[ next_state ] )( instance, event );
        STATE_TXN_END_TRACE( "WasRun", next_state, state_name_strings[ next_state ] );

        /* Self deletion state transition? */
        if ( next_state == Component_WasRun_STATE_3 || next_state == Component_WasRun_STATE_4 ) {          thismodule->Escher_DeleteInstance( instance, Component_DOMAIN_ID, Component_WasRun_CLASS_NUMBER );
        }
      } else if ( next_state == EVENT_CANT_HAPPEN ) {
          /* event cant happen */
          UserEventCantHappenCallout( current_state, next_state, event_number );
          STATE_TXN_CH_TRACE( "WasRun", current_state );
      } else {
        /* empty else */
      }
    }
  }
}

