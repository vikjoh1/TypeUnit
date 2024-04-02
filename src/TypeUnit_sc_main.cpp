/*--------------------------------------------------------------------------
 * File:  TypeUnit_sc_main.cpp
 *
 * Description:  main, system initialization (and idle loop)
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "TypeUnit_sys_types.h"


/*
 *
 * main (although perhaps under a different name)
 *
 * Bring the system up and start the event dispatch loops.
 * Make invocations to the user hooks during the different phases
 * of bringup, run and shutdown.
 *
 */
int main ( int argc, char* argv[] )
{
  UserInitializationCallout();
  UserPreOoaInitializationCallout();
    UserPostOoaInitializationCallout();
  UserPreShutdownCallout();
  UserPostShutdownCallout();
    return 0;
}
