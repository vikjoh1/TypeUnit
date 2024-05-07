#include "TestResult.h"

TestResult::TestResult(std::string name) : TestCase(name), runCount(0), errorCount(0) {}

std::string TestResult::summary()
{
    return "Tests run: " + std::to_string(runCount) + "Tests failed: " + std::to_string(errorCount);
}

void TestResult::testStarted()
{
    this->runCount += 1;
}

void TestResult::testFailed()
{
    this->errorCount += 1;
}
