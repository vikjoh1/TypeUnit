/*----------------------------------------------------------------------------
 * File:  TypeUnitComponent.h
 *
 * UML Component (Module) Declaration (Operations and Signals)
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef TYPEUNITCOMPONENT_H
#define TYPEUNITCOMPONENT_H

class TypeUnitComponent; // forward reference
#include "TypeUnit_sys_types.h"
class TypeUnitComponent : public xtuml_module {
  public:
  TypeUnitComponent( xtuml_module_name name ) : xtuml_module( name ) {
  }
};


#endif  /* TYPEUNITCOMPONENT_H */
