#include "TestCase.h"
#include "TestResult.h"
#include <exception>

void TestCase::run()
{
  wasRun = true;
  setUp();
  result.testStarted();
  try
  {
    if (testMethod)
      testMethod();
  }
  catch (const std::exception &e)
  {
    result.testFailed(e.what());
    log += "Test failed: " + std::string(e.what()) + "\n";
  }
  tearDown();
}

void TestCase::setUp()
{
  log = "setUp ";
}

void TestCase::tearDown()
{
  log += "tearDown ";
}