/*----------------------------------------------------------------------------
 * File:  Component_TestCaseTest_class.h
 *
 * Class:       TestCaseTest  (TestCaseTest)
 * Component:   Component
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef COMPONENT_TESTCASETEST_CLASS_H
#define COMPONENT_TESTCASETEST_CLASS_H



class Component; // forward reference
/*
 * Structural representation of application analysis class:
 *   TestCaseTest  (TestCaseTest)
 */
class Component_TestCaseTest {
  public:

  /* application analysis class attributes */
  void Component_TestCaseTest_op_testRunning( Component_TestCaseTest *, Component *);

};

#define Component_TestCaseTest_MAX_EXTENT_SIZE 10
extern sys_sets::Escher_Extent_t pG_Component_TestCaseTest_extent;



#endif  /* COMPONENT_TESTCASETEST_CLASS_H */
