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
    std::string log;

public:
    WasRun(const std::string &name) : TestCase(name), wasRun(false) {}
    std::function<void()> testMethod;
    void run();
    void setUp() override;
    void tearDown() override;
    void testBrokenMethod();
};

#endif // WASRUN_H