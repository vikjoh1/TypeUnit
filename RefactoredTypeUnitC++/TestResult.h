#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <string>
#include <sstream>
#include <vector>

class TestResult
{
public:
  int runCount = 0;
  int errorCount = 0;
  std::vector<std::string> errorMessages;

  void testStarted();
  void testFailed(const std::string &message);

  bool hasFailed() const;

  std::string summary() const;
};

#endif // TESTRESULT_H