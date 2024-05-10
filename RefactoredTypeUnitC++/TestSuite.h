#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <vector>
#include "Test.h"
#include "SuiteResult.h"

class TestSuite
{
private:
  std::vector<Test *> tests;
  SuiteResult result;

public:
  void add(Test *test);

  void run();

  const SuiteResult &getResult() const
  {
    return result;
  }
};

#endif // TESTSUITE_H