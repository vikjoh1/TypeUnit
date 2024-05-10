#include "TestSuite.h"

void TestSuite::add(Test *test)
{
  tests.push_back(test);
}

void TestSuite::run()
{
  for (auto &test : tests)
  {
    test->run();
    result.testStarted();
    if (test->result.hasFailed())
    {
      result.testFailed();
    }
  }
}