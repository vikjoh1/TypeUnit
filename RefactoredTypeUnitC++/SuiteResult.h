#ifndef SUITERESULT_H
#define SUITERESULT_H

#include <string>
#include <sstream>
#include <vector>

class SuiteResult
{
public:
  struct TestInfo
  {
    std::string testName;
    bool passed;
    std::string message;
  };
  int errorCount = 0;
  int runCount = 0;
  std::vector<std::string> errorMessages;
  std::vector<TestInfo> tests;

  void addTestResult(const std::string &name, bool passed, const std::string &message = "");

  void testStarted();
  void testFailed(const std::string &message);

  bool hasFailed() const;

  std::string summary() const;
};

#endif // SUITERESULT_H