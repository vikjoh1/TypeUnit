#include "TestResult.h"
#include <functional>
#include <string>
#include <unordered_map>

class TestCase
{

public:
    using Method = void (TestCase::*)();

    TestCase(std::string name);

    virtual void setUp();
    virtual void tearDown();

    void run(TestResult &result);
    void registerTest(std::string name, Method method);

protected:
    std::string name;
    std::unordered_map<std::string, Method> methods;
};
