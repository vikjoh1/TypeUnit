#ifndef SUITERESULT_H
#define SUITERESULT_H

#include <string>
#include <sstream>

class SuiteResult
{
public:
  int testsFailed = 0;
  int testsRun = 0;

  void testStarted();
  void testFailed();

  std::string summary() const;
};

#endif // SUITERESULT_H