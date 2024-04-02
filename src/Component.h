/*----------------------------------------------------------------------------
 * File:  Component.h
 *
 * UML Component (Module) Declaration (Operations and Signals)
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef COMPONENT_H
#define COMPONENT_H

class Component; // forward reference
#include "TypeUnit_sys_types.h"

#define Component_STATE_MODELS 2
#define Component_DOMAIN_ID 0
/* Define constants to map to class numbers.  */
#define Component_WasRun_CLASS_NUMBER 0
#define Component_TestCase_CLASS_NUMBER 1
#define Component_TestCaseTest_CLASS_NUMBER 2
#define Component_MAX_CLASS_NUMBERS 3

/* Provide a map of classes to task numbers.  */
#define Component_TASK_NUMBERS  0, 0

#define Component_class_dispatchers\
  Component_WasRun_Dispatch,\
  Component_TestCase_Dispatch

/* Provide definitions of the shapes of the class structures.  */

typedef class Component_WasRun Component_WasRun;
typedef class Component_TestCase Component_TestCase;
typedef class Component_TestCaseTest Component_TestCaseTest;

/* union of class declarations so we may derive largest class size */
#define Component_CLASS_U \
  char Component_dummy;\



#include "Component_WasRun_class.h"
#include "Component_TestCase_class.h"
#include "Component_TestCaseTest_class.h"
class Component : public xtuml_module, public sys_factory, public sys_events {
  public:
  Component( xtuml_module_name name ) : xtuml_module( name ), sys_factory(SYS_MAX_CONTAINERS), sys_events(sizeof(0), ESCHER_SYS_MAX_XTUML_EVENTS, NUM_OF_XTUML_CLASS_THREADS)  {
    for ( int cn=0; cn < Component_MAX_CLASS_NUMBERS; ++cn ) {
      Escher_ClassFactoryInit( 0, cn );
    }
  }
  void Component_refineTest( void );
  void Component_run( void );
  void Component_wasRun( c_t[ESCHER_SYS_MAX_STRING_LEN] );

  public:
    virtual Escher_Extent_t * Escher_GetDCI( const Escher_ClassNumber_t cn ) { return Component_class_info[cn]; }
    virtual EventTaker_t * Escher_GetEventDispatcher( void ) { return Component_EventDispatcher; }

  private:
    static Escher_Extent_t * const Component_class_info[];
    static EventTaker_t Component_EventDispatcher[];
};


#endif  /* COMPONENT_H */
