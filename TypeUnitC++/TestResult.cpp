#include "TestResult.h"

std::string TestResult::summary()
{
    return std::to_string(runCount) + " run, " + std::to_string(errorCount) + " failed";
}

void TestResult::testStarted()
{
    runCount++;
}

void TestResult::testFailed()
{
    errorCount++;
}
