#include "TestCase.h"

void TestCase::setUp()
{
    // Implementation for setUp
}

void TestCase::tearDown()
{
    // Implementation for tearDown
}

TestCase::TestCase(std::string name) : name(name) {}

void TestCase::run(TestResult &result)
{
    result.testStarted();
    this->setUp();
    try
    {
        auto method = methods.at(name);
        (this->*method)();
    }
    catch (const std::exception &e)
    {
        result.testFailed();
    }
    this->tearDown();
}

void TestCase::registerTest(std::string name, Method method)
{
    methods[name] = method;
}