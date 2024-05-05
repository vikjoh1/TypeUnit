#include <string>
using namespace std;

class TestCase
{
public:
    string name;

    TestCase(string name1) // Constructor / init
    {
        name = name1;
    }

    void run() // Should run the Test
    {
    }

    void setUp()
    {
    }

    void tearDown()
    {
    }
};

/*
Public
Private
Protected
*/