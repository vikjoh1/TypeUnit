#ifndef FIBONACCITEST_H
#define FIBONACCITEST_H

#include "TestCase.h"
#include <cassert>
#include "fibonacci.cpp"

class FibonacciTest : public TestCase
{
public:
  FibonacciTest(const std::string &name) : TestCase(name, [this]()
                                                    { this->testMethod(); }) {}

protected:
  void execute() override
  {
    testMethod();
  }

  void testMethod()
  {
    assert(fibonacci(0) == 0 && "Fibonacci of 0 should be 0");
    assert(fibonacci(1) == 1 && "Fibonacci of 1 should be 1");

    // Test recursive calculation
    assert(fibonacci(5) == 5 && "Fibonacci of 5 should be 5");
    assert(fibonacci(10) == 55 && "Fibonacci of 10 should be 55");

    // Test negative input
    try
    {
      fibonacci(-1);
      assert(false && "Fibonacci of negative number did not throw");
    }
    catch (const std::invalid_argument &e)
    {
      // Expected path
      assert(std::string(e.what()) == "Index cannot be negative" && "Expected specific exception message");
    }
    catch (...)
    {
      assert(false && "Fibonacci of negative number threw unexpected exception type");
    }
  }
};

#endif // FIBONACCI_H