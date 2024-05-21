#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <string>
#include <sstream>
#include <vector>

class TestResult
{
public:
  struct TestInfo
  {
    std::string testName;
    bool passed;
    std::string message;
  };
  int runCount = 0;
  int errorCount = 0;
  std::vector<std::string> errorMessages;
  std::vector<TestInfo> tests;

  void addTestResult(const std::string &name, bool passed, const std::string &message = "");

  void testStarted();
  void testFailed(const std::string &message);

  bool hasFailed() const;

  std::string summary() const;
};

#endif // TESTRESULT_H