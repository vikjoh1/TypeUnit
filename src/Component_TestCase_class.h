/*----------------------------------------------------------------------------
 * File:  Component_TestCase_class.h
 *
 * Class:       TestCase  (TestCase)
 * Component:   Component
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef COMPONENT_TESTCASE_CLASS_H
#define COMPONENT_TESTCASE_CLASS_H



class Component; // forward reference
/*
 * Structural representation of application analysis class:
 *   TestCase  (TestCase)
 */
class Component_TestCase {
  public:
  Escher_StateNumber_t current_state;
  /* application analysis class attributes */
  c_t name[ESCHER_SYS_MAX_STRING_LEN];  /* - name */
  /* relationship storage */
  /* Note:  No storage needed for TestCase->WasRun[R1] */
  void Component_TestCase_op_run( Component_TestCase *, Component *,  );
  void Component_TestCase_op_setUp( Component_TestCase *, Component *);
  void Component_TestCase_op_tearDown( Component_TestCase *, Component *);

};

#define Component_TestCase_MAX_EXTENT_SIZE 10
extern sys_sets::Escher_Extent_t pG_Component_TestCase_extent;

/*
 * instance event:  TestCase1:'execute'
 * warning:  Event is not used in application - no code generated.
 */
/*
 * instance event:  TestCase2:'finish'
 * warning:  Event is not used in application - no code generated.
 */

/*
 * enumeration of state model states for class
 */
#define Component_TestCase_STATE_1 1  /* state [1]:  (Idle) */
#define Component_TestCase_STATE_2 2  /* state [2]:  (Running) */
#define Component_TestCase_STATE_3 3  /* state [3]:  (Completed) */
/*
 * enumeration of state model event numbers
 */
extern void Component_TestCase_Dispatch( Escher_xtUMLEvent_t * );



#endif  /* COMPONENT_TESTCASE_CLASS_H */
