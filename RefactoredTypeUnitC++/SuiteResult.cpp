#include <sstream>
#include "SuiteResult.h"

void SuiteResult::testStarted()
{
  runCount++;
}

void SuiteResult::testFailed(const std::string &message)
{
  errorCount++;
  errorMessages.push_back(message);
}

bool SuiteResult::hasFailed() const
{
  return errorCount > 0;
}

std::string SuiteResult::summary() const
{
  std::stringstream ss;
  ss << runCount << " tests run, " << errorCount << " tests failed\n";
  for (const auto test : tests)
  {
    if (test.passed)
    {
      ss << "\033[32m✔ " << test.testName << "\033[0m\n";
    }
    else
    {
      ss << "\033[31m✘ " << test.testName << " - " << test.message << "\033[0m\n";
    }
  }
  return ss.str();
}

void SuiteResult::addTestResult(const std::string &name, bool passed, const std::string &message = "")
{
  tests.push_back({name, passed, message});
  runCount++;
  if (!passed)
  {
    errorCount++;
  }
}