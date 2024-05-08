#include "TestCaseTest.h"

TestCaseTest::TestCaseTest(std::string name) : TestCase(name), result(name) {}

void TestCaseTest::setUp()
{
    result = new TestResult();
}

void TestCaseTest::testTemplateMethod()
{
    WasRun test("testMethod");
    test.run(*result);
    assert("setUp testMethod tearDown " == test.log);
}

void TestCaseTest::testResult()
{
    WasRun test("testMethod");
    test.run(*result);
    assert("1 run, 0 failed" == result->summary());
}

void TestCaseTest::testFailedResult()
{
    WasRun test("testBrokenMethod");
    test.run(*result);
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
    suite.add(new WasRun("testMethod"));
    suite.add(new WasRun("testBrokenMethod"));
    suite.run(*result);
    assert("2 run, 1 failed" == result->summary());
}
