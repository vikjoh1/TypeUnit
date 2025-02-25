#include "TestCase.h"

void TestCase::setUp()
{
    // Implementation for setUp
}

void TestCase::tearDown()
{
    // Implementation for tearDown
}

void TestCase::run(TestResult &result)
{
    result.testStarted();
    setUp();
    try
    {
        runTestMethod();
    }
    catch (const std::exception &e)
    {
        result.testFailed();
    }
    tearDown();
}