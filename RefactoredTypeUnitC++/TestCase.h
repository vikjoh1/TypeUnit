#ifndef TESTCASE_H
#define TESTCASE_H

#include "Test.h"
#include <functional>

class TestCase : public Test
{
public:
  std::function<void()> testMethod;

  TestCase(const std::string &name, std::function<void()> method) : Test(name), testMethod(method) {}

  virtual void run() override;

protected:
  virtual void setUp();
  virtual void tearDown();
};

#endif // TESTCASE_H