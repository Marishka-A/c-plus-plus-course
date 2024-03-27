#include <iostream>

struct bar
{
    bar()
    {
        std::cout << "bar" << std::endl;
    }

    ~bar()
    {
        std::cout << "~bar" << std::endl;
    }
};

void b(int y)
{
    if (y == 0)
    {
        throw std::runtime_error("smth went wrong");
    }
}

struct raii
{
    raii(const int x) :
        m_pointer(new int(x))
    {
        std::cout << "raii" << std::endl;
    }

    ~raii()
    {
        std::cout << "~raii" << std::endl;
        delete m_pointer;
    }

    int* m_pointer = nullptr;
};

void foo(int x = 0)
{
    raii r(x);
    b(x);
}

int main()
{
    try
    {
        foo(0);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Hello, world" << std::endl;
}
