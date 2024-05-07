#include "TestCase.h"

class WasRun : public TestCase
{
private:
    bool wasRun;
    bool wasSetUp;
    std::string log;

public:
    WasRun(std::string name);
    void run() override;
    void testMethod();
};
