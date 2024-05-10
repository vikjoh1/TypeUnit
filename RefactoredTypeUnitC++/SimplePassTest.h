#include "TestCase.h"
#include "TestResult.h"

class SimplePassTest : public TestCase
{
public:
  SimplePassTest(const std::string &name) : TestCase(name, [this]
                                                     { execute(); }) {}

protected:
  void execute() override
  {
    if (1 != 1)
    {
      throw std::runtime_error("Test failed: 1 should equal 1");
    }
  };
};