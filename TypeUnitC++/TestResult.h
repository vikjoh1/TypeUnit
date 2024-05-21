#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <string>
#include <iostream>

class TestResult
{
private:
    int runCount;
    int errorCount;

public:
    TestResult() : runCount(0), errorCount(0){};
    std::string summary();
    void testStarted();
    void testFailed();
};

#endif // TESTRESULT_H