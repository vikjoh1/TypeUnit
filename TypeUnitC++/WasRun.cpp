#include "WasRun.h"

void WasRun::setUp()
{
    log = "setUp ";
}

void WasRun::tearDown()
{
    log += "tearDown ";
}

void WasRun::testMethod()
{
    log += "testMethod ";
}

void WasRun::testBrokenMethod()
{
    throw std::runtime_error("Exception occurred in testBrokenMethod");
}

void WasRun::run()
{
    if (name == "testMethod")
    {
        testMethod();
    }
    else if (name == "testBrokenMethod")
    {
        testBrokenMethod();
    }
}

void WasRun::runTestMethod()
{
    this->run();
}