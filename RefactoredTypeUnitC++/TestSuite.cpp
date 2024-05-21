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
    bool passed = !test->result.hasFailed();
    std::string message = passed ? "" : test->result.errorMessages.empty() ? ""
                                                                           : test->result.errorMessages[0];
    result.addTestResult(test->name, passed, message);
  }
}