#include <vector>
#include "TestCase.h"
#include "TestResult.h"

class TestSuite
{
private:
    std::vector<TestCase *> tests;

public:
    TestSuite();
    void add(TestCase *test);
    void run(TestResult &result);
};
