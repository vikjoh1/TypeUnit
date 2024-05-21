#include "TestSuite.h"
#include "WasRun.h"
#include "TestResult.h"
#include <iostream>

int main()
{
  TestResult result;
  TestSuite suite;
  suite.add(new WasRun("testMethod"));
  suite.run(result);

  std::cout << result.summary() << std::endl;
  return 0;
}