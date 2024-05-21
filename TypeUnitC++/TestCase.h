#ifndef TESTCASE_H
#define TESTCASE_H

#include "TestResult.h"
#include <functional>
#include <string>

class TestCase
{

public:
    std::function<void()> testMethod;
    std::string name;

    TestCase(const std::string &name) : name(name){};

    void run(TestResult &result);

protected:
    virtual void setUp();
    virtual void tearDown();
};

#endif // TESTCASE_H