/*----------------------------------------------------------------------------
 * File:  Component_WasRun_class.h
 *
 * Class:       WasRun  (WasRun)
 * Component:   Component
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef COMPONENT_WASRUN_CLASS_H
#define COMPONENT_WASRUN_CLASS_H



class Component; // forward reference
/*
 * Structural representation of application analysis class:
 *   WasRun  (WasRun)
 */
class Component_WasRun {
  public:
  Escher_StateNumber_t current_state;
  /* application analysis class attributes */
  bool wasRun;  /* - wasRun */
  c_t name[ESCHER_SYS_MAX_STRING_LEN];  /* - name */
  /* relationship storage */
  /* Note:  No storage needed for WasRun->TestCase[R1] */
  void Component_WasRun_op_run( Component_WasRun *, Component *);
  void Component_WasRun_op_setUp( Component_WasRun *, Component *);
/* xtUML WARNING:  TestCase<-R1->WasRun never related!  */
/* Note:  TestCase<-R1->WasRun unrelate accessor not needed */
};

#define Component_WasRun_MAX_EXTENT_SIZE 10
extern sys_sets::Escher_Extent_t pG_Component_WasRun_extent;

/*
 * creation event:  WasRun1:'callConstructor'
 * warning:  Event is not used in application - no code generated.
 */
/*
 * instance event:  WasRun2:'run'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} Component_WasRunevent2;
extern const Escher_xtUMLEventConstant_t Component_WasRunevent2c;
/*
 * instance event:  WasRun3:'fail'
 * warning:  Event is not used in application - no code generated.
 */
/*
 * instance event:  WasRun4:'pass'
 * warning:  Event is not used in application - no code generated.
 */
/*
 * union of events targeted towards 'WasRun' state machine
 */
typedef union {
  Component_WasRunevent2 wasrun2_1;  
} Component_WasRun_Events_u;
/*
 * enumeration of state model states for class
 */
#define Component_WasRun_STATE_1 1  /* state [1]:  (NotRun) */
#define Component_WasRun_STATE_2 2  /* state [2]:  (Running) */
#define Component_WasRun_STATE_3 3  /* state [3]:  (Passed) */
#define Component_WasRun_STATE_4 4  /* state [4]:  (Failed) */
/*
 * enumeration of state model event numbers
 */
#define COMPONENT_WASRUNEVENT2NUM 0  /* WasRun2:'run' */
extern void Component_WasRun_Dispatch( Escher_xtUMLEvent_t * );



#endif  /* COMPONENT_WASRUN_CLASS_H */
