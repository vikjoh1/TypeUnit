#include "TestCaseTest.h"

void TestCaseTest::setUp()
{
    result = new TestResult();
}

void TestCaseTest::tearDown()
{
    delete result;
    result = nullptr;
}

void TestCaseTest::testTemplateMethod()
{
    WasRun test("testMethod");
    test.run();
    assert("setUp testMethod tearDown " == test.log);
}

void TestCaseTest::testResult()
{
    WasRun test("testMethod");
    test.run();
    assert("1 run, 0 failed" == result->summary());
}

void TestCaseTest::testFailedResult()
{
    WasRun test("testBrokenMethod");
    test.run();
    assert("1 run, 1 failed" == result->summary());
}

void TestCaseTest::testFailedResultFormatting()
{
    result->testStarted();
    result->testFailed();
    assert("1 run, 1 failed" == result->summary());
}

void TestCaseTest::testSuite()
{
    TestSuite suite;
    WasRun test1("testMethod");
    WasRun test2("testBrokenMethod");
    suite.add(&test1);
    suite.add(&test2);
    suite.run(*result);
    assert("2 run, 1 failed" == result->summary());
}
