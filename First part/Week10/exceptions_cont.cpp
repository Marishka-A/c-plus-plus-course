#include <iostream>
#include <exception>

// std::excpetion <- std::runtime_errors

void foo()
{
    throw std::runtime_error("Foo");
}

void bar()
{
    throw std::out_of_range("Bar");
}

int main()
{
    try
    {
        foo();
    }
    catch (const double e)
    {
        std::cout << e << std::endl;
    }
    catch (const unsigned int e)
    {
        std::cerr << e << '\n';
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
        throw;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
}
