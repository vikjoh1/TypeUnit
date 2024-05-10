#ifndef TEST_H
#define TEST_H

#include "TestResult.h"
#include <string>

class Test
{
public:
  std::string name;
  bool wasRun = false;
  std::string log;
  TestResult result;

  Test(const std::string &name) : name(name) {}

  virtual ~Test() {}

  virtual void run();

protected:
  virtual void execute() = 0;
};

#endif // TEST_H