#include <iostream>
#include <vector>

void foo()
{
    int a = 2;
}

std::vector<int> make_vector()
{
    return {1, 2, 3};
}

int main()
{
    int a = 3;
    {
        int b = 3;
        std::vector<int> vec;
    }
    int c;
    std::cout << "Hello, world!" << c << std::endl;

    auto vec = make_vector();

    for (int i = 0; i < 100'000; ++i)
    {
        int a = 2;
    }
    std::cout << sizeof(int) << std::endl;
}
