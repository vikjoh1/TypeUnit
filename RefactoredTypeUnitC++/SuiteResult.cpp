#include <sstream>
#include "SuiteResult.h"

void SuiteResult::testStarted()
{
  testsRun++;
}

void SuiteResult::testFailed()
{
  testsFailed++;
}

std::string SuiteResult::summary() const
{
  std::stringstream ss;
  ss << testsRun << " tests run, " << testsFailed << " tests failed.";
  return ss.str();
}