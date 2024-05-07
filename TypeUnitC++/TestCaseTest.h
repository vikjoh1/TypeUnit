#include "TestCase.h"
#include "TestResult.h"

class TestCaseTest : public TestCase
{
private:
    TestResult result;

public:
    TestCaseTest(std::string name);
    void testRunning();
    void testResult();
    void testFailedResult();
    void testFailedResultFormatting();
    void testSuite();
};
