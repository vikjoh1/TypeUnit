#include "TestSuite.h"
#include "TestResult.h"
#include "SimplePassTest.h"
#include "SimpleFailTest.h"
#include "SuiteResult.h"
#include <iostream>
#include "FibonacciTest.h"

int main()
{
  TestSuite suite;

  // suite.add(new SimplePassTest("Pass Test"));
  // suite.add(new SimpleFailTest("Fail Test"));
  suite.add(new FibonacciTest("Test Fibonacci Base Cases"));
  suite.add(new FibonacciTest("Test Fibonacci Recursive Calculation"));
  suite.add(new FibonacciTest("Test Fibonacci Negative Input"));

  suite.run();

  std::cout << suite.getResult().summary() << std::endl;

  return 0;
}