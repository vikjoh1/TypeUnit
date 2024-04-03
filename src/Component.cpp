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
 * Domain Function:  createTestCase
 */
void
Component::Component_createTestCase()
{
  Component * thismodule = this;
  Component_TestCase * v_tc;
  /* CREATE OBJECT INSTANCE tc OF TestCase */
  XTUML_OAL_STMT_TRACE( 1, "CREATE OBJECT INSTANCE tc OF TestCase" );
  v_tc = (Component_TestCase *) thismodule->Escher_CreateInstance( Component_DOMAIN_ID, Component_TestCase_CLASS_NUMBER );
  /* ASSIGN tc.name = testMethod */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN tc.name = testMethod" );
  thismodule->Escher_strcpy( ((Component_TestCase *)xtUML_detect_empty_handle( v_tc, "TestCase", "tc.name" ))->name, "testMethod" );
  /* tc.setUp() */
  XTUML_OAL_STMT_TRACE( 1, "tc.setUp()" );
  v_tc->Component_TestCase_op_setUp( v_tc,  thismodule);
}

/*
 * Domain Function:  createWasRun
 */
void
Component::Component_createWasRun()
{
  Component * thismodule = this;
  Component_WasRun * v_wr;
  /* CREATE OBJECT INSTANCE wr OF WasRun */
  XTUML_OAL_STMT_TRACE( 1, "CREATE OBJECT INSTANCE wr OF WasRun" );
  v_wr = (Component_WasRun *) thismodule->Escher_CreateInstance( Component_DOMAIN_ID, Component_WasRun_CLASS_NUMBER );
  /* ASSIGN wr.name = temp */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN wr.name = temp" );
  thismodule->Escher_strcpy( ((Component_WasRun *)xtUML_detect_empty_handle( v_wr, "WasRun", "wr.name" ))->name, "temp" );
  /* wr.setUp() */
  XTUML_OAL_STMT_TRACE( 1, "wr.setUp()" );
  v_wr->Component_WasRun_op_setUp( v_wr,  thismodule);
  /* wr.run() */
  XTUML_OAL_STMT_TRACE( 1, "wr.run()" );
  v_wr->Component_WasRun_op_run( v_wr,  thismodule);
}
/* xtUML class info (collections, sizes, etc.) */
sys_sets::Escher_Extent_t * const Component::Component_class_info[ Component_MAX_CLASS_NUMBERS ] = {
  &pG_Component_WasRun_extent,
  &pG_Component_TestCase_extent,
  &pG_Component_TestCaseTest_extent
};


