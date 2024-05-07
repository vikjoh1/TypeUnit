#include <string>

class TestCase
{
private:
    std::string name;

protected:
    virtual void setUp();
    virtual void tearDown();

public:
    TestCase(std::string name);
    virtual void run();
};
