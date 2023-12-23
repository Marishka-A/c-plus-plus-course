#include <iostream>
#include <exception>

// 

class Bar
{
public:
    Bar()
    {
        std::cout << "Bar" << std::endl;
        throw std::runtime_error("Bar");
    }

    ~Bar()
    {
        std::cout << "~Bar" << std::endl;
        //throw std::runtime_error("~Bar");
    }
private:
// some fields
int i;
};

//
//

class Foo
{
public:
    ~Foo()
    {
        std::cout << "~Foo" << std::endl;
        //throw std::out_of_range("Foo");
    }
private:
    Bar bar;
};

// noexcept foo
void foo() noexcept
{
}

int main()
{
    Foo foo;
    try
    {
        Foo foo;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // check exception
    {
    }

    // strong, basic
    {
        
    }
}
