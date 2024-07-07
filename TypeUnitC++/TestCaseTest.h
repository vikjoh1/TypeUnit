#ifndef TESTCASETEST_H
#define TESTCASETEST_H

#include "TestCase.h"
#include "TestResult.h"
#include "TestSuite.h"
#include "WasRun.h"
#include <cassert>

class TestCaseTest : public TestCase
{
private:
    TestResult *result;

public:
    TestCaseTest(const std::string &name) : TestCase(name), result(nullptr) {}
    void setUp() override;
    void tearDown() override;
    void testResult();
    void testTemplateMethod();
    void testFailedResult();
    void testFailedResultFormatting();
    void testSuite();
};

#endif // TESTCASETEST_H