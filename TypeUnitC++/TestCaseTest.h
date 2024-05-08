#include "TestCase.h"
#include "TestResult.h"
#include "TestSuite.h"
#include "WasRun.h"

class TestCaseTest : public TestCase
{
private:
    TestResult result;

public:
    TestCaseTest(std::string name);
    void setUp() override;
    void testResult();
    void testTemplateMethod();
    void testFailedResult();
    void testFailedResultFormatting();
    void testSuite();
};
