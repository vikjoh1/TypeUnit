/*----------------------------------------------------------------------------
 * File:  Component.cpp
 *
 * UML Component as a SystemC Module
 * Component/Module Name:  Component
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "Component.h"

/*
 * UML Domain Functions (Synchronous Services)
 */

/*
 * Domain Function:  refineTest
 */
void
Component::Component_refineTest()
{
  Component * thismodule = this;

}

/*
 * Domain Function:  run
 */
void
Component::Component_run()
{
  Component * thismodule = this;

}

/*
 * Domain Function:  wasRun
 */
void
Component::Component_wasRun( c_t p_name[ESCHER_SYS_MAX_STRING_LEN] )
{
  Component * thismodule = this;

}
/* xtUML class info (collections, sizes, etc.) */
sys_sets::Escher_Extent_t * const Component::Component_class_info[ Component_MAX_CLASS_NUMBERS ] = {
  &pG_Component_WasRun_extent,
  &pG_Component_TestCase_extent,
  &pG_Component_TestCaseTest_extent
};


/*
 * Array of pointers to the class event dispatcher method.
 * Index is the (model compiler enumerated) number of the state model.
 */
EventTaker_t Component::Component_EventDispatcher[ Component_STATE_MODELS ] = {
  Component_class_dispatchers
};

