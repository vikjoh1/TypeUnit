#include "TestResult.h"
#include <sstream>

std::string TestResult::summary() const
{
  std::stringstream ss;
  ss << runCount << " run, " << errorCount << " failed\n";
  for (const auto &message : errorMessages)
  {
    ss << "Error: " << message << "\n";
  }
  return ss.str();
}

void TestResult::testStarted()
{
  runCount++;
}

void TestResult::testFailed(const std::string &message)
{
  errorCount++;
  errorMessages.push_back(message);
}

bool TestResult::hasFailed() const
{
  return errorCount > 0;
}