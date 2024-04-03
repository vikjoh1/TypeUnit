/*----------------------------------------------------------------------------
 * File:  Component_TestCase_class.cpp
 *
 * Class:       TestCase  (TestCase)
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
Component_TestCase::Component_TestCase_op_run( Component_TestCase * self, Component * thismodule,  p_result )
{
  /* self.setUp() */
  XTUML_OAL_STMT_TRACE( 1, "self.setUp()" );
  self->Component_TestCase_op_setUp( self,  thismodule);
  /* IF ( self.name == testMethod ) */
  XTUML_OAL_STMT_TRACE( 1, "IF ( self.name == testMethod )" );
  if ( thismodule->Escher_strcmp( ((Component_TestCase *)xtUML_detect_empty_handle( self, "TestCase", "self.name" ))->name, "testMethod" ) == 0 ) {
  }
  else if ( thismodule->Escher_strcmp( ((Component_TestCase *)xtUML_detect_empty_handle( self, "TestCase", "self.name" ))->name, "brokenTestMethod" ) == 0 ) {
  }
  /* self.tearDown() */
  XTUML_OAL_STMT_TRACE( 1, "self.tearDown()" );
  self->Component_TestCase_op_tearDown( self,  thismodule);
}

/*
 * instance operation:  setUp
 */
void
Component_TestCase::Component_TestCase_op_setUp( Component_TestCase * self, Component * thismodule)
{

}

/*
 * instance operation:  tearDown
 */
void
Component_TestCase::Component_TestCase_op_tearDown( Component_TestCase * self, Component * thismodule)
{

}


/*----------------------------------------------------------------------------
 * Operation action methods implementation for the following class:
 *
 * Class:      TestCase  (TestCase)
 * Component:  Component
 *--------------------------------------------------------------------------*/
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static sys_sets::Escher_SetElement_s Component_TestCase_container[ Component_TestCase_MAX_EXTENT_SIZE ];
static Component_TestCase Component_TestCase_instances[ Component_TestCase_MAX_EXTENT_SIZE ];
sys_sets::Escher_Extent_t pG_Component_TestCase_extent = {
  {0}, {0}, &Component_TestCase_container[ 0 ],
  (Escher_iHandle_t) &Component_TestCase_instances,
  sizeof( Component_TestCase ), Component_TestCase_STATE_1, Component_TestCase_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      TestCase  (TestCase)
 * Component:  Component
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [Idle]
 */
static void Component_TestCase_act1( Component_TestCase *, const Escher_xtUMLEvent_t * const );
static void
Component_TestCase_act1( Component_TestCase * self, const Escher_xtUMLEvent_t * const event )
{
  Component * thismodule = (Component *) event->thismodule;
}

/*
 * State 2:  [Running]
 */
static void Component_TestCase_act2( Component_TestCase *, const Escher_xtUMLEvent_t * const );
static void
Component_TestCase_act2( Component_TestCase * self, const Escher_xtUMLEvent_t * const event )
{
  Component * thismodule = (Component *) event->thismodule;
}

/*
 * State 3:  [Completed]
 */
static void Component_TestCase_act3( Component_TestCase *, const Escher_xtUMLEvent_t * const );
static void
Component_TestCase_act3( Component_TestCase * self, const Escher_xtUMLEvent_t * const event )
{
  Component * thismodule = (Component *) event->thismodule;
}





/*
 * State-Event Matrix (SEM)
 * Row index is object (MC enumerated) current state.
 * Row zero is the uninitialized state (e.g., for creation event transitions).
 * Column index is (MC enumerated) state machine events.
 */
static const Escher_SEMcell_t Component_TestCase_StateEventMatrix[ 3 + 1 ][ 0 ] = {
  /* row 0:  uninitialized state (for creation events) */
  {  },
  /* row 1:  Component_TestCase_STATE_1 (Idle) */
  {  },
  /* row 2:  Component_TestCase_STATE_2 (Running) */
  {  },
  /* row 3:  Component_TestCase_STATE_3 (Completed) */
  {  }
};

  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t Component_TestCase_acts[ 4 ] = {
    (StateAction_t) 0,
    (StateAction_t) Component_TestCase_act1,  /* Idle */
    (StateAction_t) Component_TestCase_act2,  /* Running */
    (StateAction_t) Component_TestCase_act3  /* Completed */
  };

  /*
   * Array of string names of the state machine names.
   * Index is the (MC enumerated) number of the state.
   */
  static const c_t * const state_name_strings[ 4 ] = {
    "",
    "Idle",
    "Running",
    "Completed"
  };

/*
 * instance state machine event dispatching
 */
void
Component_TestCase_Dispatch( Escher_xtUMLEvent_t * event )
{
  Component * thismodule = (Component *) event->thismodule;
  Escher_iHandle_t instance = GetEventTargetInstance( event );
  Escher_EventNumber_t event_number = GetOoaEventNumber( event );
  Escher_StateNumber_t current_state;
  Escher_StateNumber_t next_state;
  if ( 0 != instance ) {
    current_state = instance->current_state;
    if ( current_state > 3 ) {
      /* instance validation failure (object deleted while event in flight) */
      UserEventNoInstanceCallout( event_number );
    } else {
      next_state = Component_TestCase_StateEventMatrix[ current_state ][ event_number ];
      if ( next_state <= 3 ) {
        STATE_TXN_START_TRACE( "TestCase", current_state, state_name_strings[ current_state ] );
        /* Update the current state and execute the state action.  */
        instance->current_state = next_state;
        ( *Component_TestCase_acts[ next_state ] )( instance, event );
        STATE_TXN_END_TRACE( "TestCase", next_state, state_name_strings[ next_state ] );
      } else if ( next_state == EVENT_CANT_HAPPEN ) {
          /* event cant happen */
          UserEventCantHappenCallout( current_state, next_state, event_number );
          STATE_TXN_CH_TRACE( "TestCase", current_state );
      } else {
        /* empty else */
      }
    }
  }
}

