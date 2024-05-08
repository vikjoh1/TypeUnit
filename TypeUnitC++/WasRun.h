#include "TestCase.h"
#include <stdexcept>

class WasRun : public TestCase
{
private:
    bool wasRun;
    bool wasSetUp;
    std::string log;

public:
    WasRun(std::string name) : TestCase(name), wasRun(false) {}
    void run();
    void testMethod();
    void setUp() override;
    void tearDown() override;
    void testBrokenMethod();
};
