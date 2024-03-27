#include <iostream>

int main()
{
    int a = 3;
    std::cout << "stack: " << &a << std::endl;
    {
        int* p_a = new int(3);
        std::cout << "heap: " << p_a << " " << *p_a << std::endl;
        delete p_a;
        std::cout << *p_a << std::endl;

        int* p_b = new int[100];
        delete[] p_b;
    }
}
