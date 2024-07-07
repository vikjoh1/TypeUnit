#ifndef WASRUN_H
#define WASRUN_H

#include "TestCase.h"
#include <string>
#include <stdexcept>

class WasRun : public TestCase
{
private:
    bool wasRun;
    bool wasSetUp;

public:
    std::string log;
    WasRun(const std::string &name) : TestCase(name), wasRun(false), wasSetUp(false) {}
    void testMethod();
    void run();
    void setUp() override;
    void tearDown() override;
    void testBrokenMethod();

protected:
    void runTestMethod() override;
};

#endif // WASRUN_H