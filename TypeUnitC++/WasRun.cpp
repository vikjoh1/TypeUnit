#include "WasRun.h"

void WasRun::setUp()
{
    log = "setUp ";
}

void WasRun::tearDown()
{
    log += "tearDown ";
}

void WasRun::run()
{
    if (testMethod)
    {
        testMethod();
    }
}

void WasRun::testBrokenMethod()
{
    throw std::runtime_error("Exception occurred in testBrokenMethod");
}
