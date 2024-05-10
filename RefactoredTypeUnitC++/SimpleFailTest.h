#include "TestCase.h"

class SimpleFailTest : public TestCase
{
public:
  SimpleFailTest(const std::string &name) : TestCase(name, [this]
                                                     { execute(); }){};

protected:
  void execute() override
  {
    if (1 != 2)
    {
      throw std::runtime_error("Test failed: 1 should equal 2");
    }
  };
};