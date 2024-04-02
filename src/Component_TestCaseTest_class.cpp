/*----------------------------------------------------------------------------
 * File:  Component_TestCaseTest_class.cpp
 *
 * Class:       TestCaseTest  (TestCaseTest)
 * Component:   Component
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "TypeUnit_sys_types.h"
#include "Component.h"

/*
 * instance operation:  testRunning
 */
void
Component_TestCaseTest::Component_TestCaseTest_op_testRunning( Component_TestCaseTest * self, Component * thismodule)
{

}


/*----------------------------------------------------------------------------
 * Operation action methods implementation for the following class:
 *
 * Class:      TestCaseTest  (TestCaseTest)
 * Component:  Component
 *--------------------------------------------------------------------------*/
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static sys_sets::Escher_SetElement_s Component_TestCaseTest_container[ Component_TestCaseTest_MAX_EXTENT_SIZE ];
static Component_TestCaseTest Component_TestCaseTest_instances[ Component_TestCaseTest_MAX_EXTENT_SIZE ];
sys_sets::Escher_Extent_t pG_Component_TestCaseTest_extent = {
  {0}, {0}, &Component_TestCaseTest_container[ 0 ],
  (Escher_iHandle_t) &Component_TestCaseTest_instances,
  sizeof( Component_TestCaseTest ), 0, Component_TestCaseTest_MAX_EXTENT_SIZE
  };

