#include <iostream>

// refs, good C++ style
void swap(int& a, int& b)
{
    const int c = a;
    a = b;
    b = c;
}

// pointers, bad C style
void swap(int* p_a, int* p_b)
{
    const int c = *p_a;
    *p_a = *p_b;
    *p_b = c;
}

int main()
{
    int a = 2;
    int b = 3;
    swap(&a, &b);
    swap(a, b);
    std::cout << a << ' ' << b << std::endl;
}