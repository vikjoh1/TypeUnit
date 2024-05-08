#include "WasRun.h"

WasRun::WasRun(std::string name) : TestCase(name), wasRun(false) {}
void WasRun::testMethod()
{
    log += "testMethod ";
}

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
    Method method = methods.at(name);
    (this->*method)();
}



void WasRun::testBrokenMethod() {
    throw std::runtime_error("Exception occurred in testBrokenMethod");
}
