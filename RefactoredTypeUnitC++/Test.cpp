#include "Test.h"

void Test::run()
{
  wasRun = true;
  result.testStarted();
  try
  {
    execute();
  }
  catch (const std::exception &e)
  {
    result.testFailed(e.what());
    log += std::string("Test failed: ") + e.what() + "\n";
  }
}