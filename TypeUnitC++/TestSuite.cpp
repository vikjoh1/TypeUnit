#include "TestSuite.h"

TestSuite::TestSuite() {}

void TestSuite::add(TestCase *test)
{
    tests.push_back(test);
}

void TestSuite::run(TestResult &result)
{
    for (auto test : tests)
    {
        test->run(result);
    }
}
