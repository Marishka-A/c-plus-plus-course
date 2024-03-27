#include <iostream>

void f(int x)
{
    std::cout << ++x << std::endl;
    f(x);
}

int main()
{
    f(0);
}
