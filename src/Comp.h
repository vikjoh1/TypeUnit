/*----------------------------------------------------------------------------
 * File:  Comp.h
 *
 * UML Component (Module) Declaration (Operations and Signals)
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef COMP_H
#define COMP_H

class Comp; // forward reference
#include "TypeUnit_sys_types.h"
class Comp : public xtuml_module {
  public:
  Comp( xtuml_module_name name ) : xtuml_module( name ) {
  }
};


#endif  /* COMP_H */
