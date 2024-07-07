#ifndef TESTCASE_H
#define TESTCASE_H

#include "TestResult.h"
#include <functional>
#include <string>

class TestCase
{

public:
    std::string name;

    TestCase(const std::string &name) : name(name){};

    void run(TestResult &result);

protected:
    virtual void setUp();
    virtual void tearDown();
    virtual void runTestMethod() = 0;
};

#endif // TESTCASE_H