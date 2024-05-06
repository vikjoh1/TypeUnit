#include <string>
using namespace std;

class TestCase
{
private:
    string name;

protected:
    virtual void setUp()
    {
    }

    virtual void tearDown()
    {
    }

public:
    TestCase(string name1) : name(name1) {}

    virtual void run() // Should run the Test
    {
    }
};

class WasRun : public TestCase
{
private:
    bool wasRun;
    bool wasSetUp;
    string log;

public:
    WasRun(string name1) : TestCase(name1) {}

    void run() // Should run the Test.
    {
        // Use override? or is it different implementations? We have to only consider the UML model and not Becks example here.
        // We get to decide how to implement the functions since our UML Model does not cover the implementation logic
    }

    void testMethod()
    {
    }
};

class TestResult : public TestCase
{
private:
    int runCount;
    int errorCount;

public:
    TestResult() : runCount(0), errorCount(0) {}

    string summary()
    {
        return "";
    }

    void testStarted()
    {
    }

    void testFailed()
    {
    }
};

class TestCaseTest : public TestCase
{
private:
    TestResult result;

public:
    TestCaseTest(string name1) : TestCase(name1)
    {
    }

    string summary()
    {
        return "";
    }

    void testRunning()
    {
    }

    void testResult()
    {
    }

    void testFailedResult()
    {
    }

    void testFailedResultFormatting()
    {
    }

    void testSuite()
    {
    }
};