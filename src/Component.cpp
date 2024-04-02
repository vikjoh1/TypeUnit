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
  Component_TestCase * v_tc;
  /* CREATE OBJECT INSTANCE tc OF TestCase */
  XTUML_OAL_STMT_TRACE( 1, "CREATE OBJECT INSTANCE tc OF TestCase" );
  v_tc = (Component_TestCase *) thismodule->Escher_CreateInstance( Component_DOMAIN_ID, Component_TestCase_CLASS_NUMBER );
  /* ASSIGN tc.name = temp */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN tc.name = temp" );
  thismodule->Escher_strcpy( ((Component_TestCase *)xtUML_detect_empty_handle( v_tc, "TestCase", "tc.name" ))->name, "temp" );
}

/*
 * Domain Function:  run
 */
void
Component::Component_run()
{
  Component * thismodule = this;
  Component_WasRun * v_wr=0;
  /* SELECT any wr FROM INSTANCES OF WasRun */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any wr FROM INSTANCES OF WasRun" );
  v_wr = (Component_WasRun *) Escher_SetGetAny( &pG_Component_WasRun_extent.active );
  /* GENERATE WasRun2:run() TO wr */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE WasRun2:run() TO wr" );
  { Escher_xtUMLEvent_t * e = thismodule->Escher_NewxtUMLEvent( v_wr, &Component_WasRunevent2c );
    thismodule->Escher_SendEvent( e );
  }
  /* ASSIGN wr.wasRun = TRUE */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN wr.wasRun = TRUE" );
  ((Component_WasRun *)xtUML_detect_empty_handle( v_wr, "WasRun", "wr.wasRun" ))->wasRun = TRUE;
}

/*
 * Domain Function:  wasRun
 */
void
Component::Component_wasRun( c_t p_name[ESCHER_SYS_MAX_STRING_LEN] )
{
  Component * thismodule = this;
  Component_WasRun * v_wr;
  /* CREATE OBJECT INSTANCE wr OF WasRun */
  XTUML_OAL_STMT_TRACE( 1, "CREATE OBJECT INSTANCE wr OF WasRun" );
  v_wr = (Component_WasRun *) thismodule->Escher_CreateInstance( Component_DOMAIN_ID, Component_WasRun_CLASS_NUMBER );
  /* ASSIGN wr.name = temp */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN wr.name = temp" );
  thismodule->Escher_strcpy( ((Component_WasRun *)xtUML_detect_empty_handle( v_wr, "WasRun", "wr.name" ))->name, "temp" );
  /* ASSIGN wr.wasRun = FALSE */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN wr.wasRun = FALSE" );
  ((Component_WasRun *)xtUML_detect_empty_handle( v_wr, "WasRun", "wr.wasRun" ))->wasRun = FALSE;
}
/* xtUML class info (collections, sizes, etc.) */
sys_sets::Escher_Extent_t * const Component::Component_class_info[ Component_MAX_CLASS_NUMBERS ] = {
  &pG_Component_WasRun_extent,
  &pG_Component_TestCase_extent,
  &pG_Component_TestCaseTest_extent
};


