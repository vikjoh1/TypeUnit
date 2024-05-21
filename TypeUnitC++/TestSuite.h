#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <vector>
#include "TestCase.h"

class TestSuite
{
private:
    std::vector<TestCase *> tests;

public:
    void add(TestCase *test);
    void run(TestResult &result);
};

#endif // TESTSUITE_H