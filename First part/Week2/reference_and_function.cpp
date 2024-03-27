#include <iostream>
#include <string>
#include <vector>

// 1.8 Functions
namespace functions
{
    // Declaration
    void foo();

    // Definition
    void foo() { std::cout << "foo()" << std::endl; }

    // Overloading
    void foo(int elem)
    {
        std::cout << "foo(int)"
                  << " int = " << elem << std::endl;
    }

    // Overloading
    void foo(char elem)
    {
        std::cout << "foo(char)"
                  << " char = " << elem << std::endl;
    }

    // Def argument
    // If u don't pass 2 arg, It will be 0
    void foo(double elem, int defElem = 0)
    {
        std::cout << "foo(double, int)"
                  << " defElem = " << defElem << std::endl;
    }

    int funcVar = 5;
}

// new address to str, passing with copy
void printStringCopy(std::string str)
{
    std::cout << "address " << str << " " << str << std::endl;
}

// same address to str, passing with ref
void printStringRef(std::string& str)
{
    std::cout << "address " << str << " " << str << std::endl;
}

// BAD!!!
// std::string - OK
std::string& createString()
{
    // create object in this scope
    std::string str = {"createString"};
    // reference to local variable returned, bad ref
    return str;
}

int main()
{
    // Let's create a scope
    {
        // using all namespace only there
        using namespace functions;

        foo();
        foo(2);
        foo('a');
        foo(2.0);
        foo(2.0, 1);
    }

    {
        std::string str = "abc";
        std::cout << "address " << &str << std::endl;
        printStringCopy(str);
        printStringRef(str);
    }
}
