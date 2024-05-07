#include "TestCase.h"

class TestResult : public TestCase
{
private:
    int runCount;
    int errorCount;

public:
    TestResult(std::string name);
    std::string summary();
    void testStarted();
    void testFailed();
};
