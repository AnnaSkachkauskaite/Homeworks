#include <QCoreApplication>
#include <iostream>

using namespace std;

class ExampleClass
{
public:
    ~ExampleClass()
    {
        cout << "ExampleClass is destroyed\n";
    }
};

class Exeption
{
public:
    ~Exeption()
    {
        cout << "Exeption is destroyed\n";
    }
};

int main()
{
    try
    {
        ExampleClass ex;
        throw Exeption();
    }
    catch(...)
    {
        cout << "Catched\n";
    }
    return 0;
}

