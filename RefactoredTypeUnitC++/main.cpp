#include "TestSuite.h"
#include "TestResult.h"
#include "SimplePassTest.h"
#include "SimpleFailTest.h"
#include "SuiteResult.h"
#include <iostream>

int main()
{
  TestSuite suite;
  TestResult result;

  suite.add(new SimplePassTest("Pass Test"));
  suite.add(new SimpleFailTest("Fail Test"));

  suite.run();

  std::cout << suite.getResult().summary() << std::endl;

  return 0;
}