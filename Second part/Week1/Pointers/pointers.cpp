#include <iostream>
#include <vector>

// Pointers, Compound Type

int main()
{
    int a = 3;
    int b = 5;
    std::cout << &a << std::endl; // &: T->T*
    int* p_a = &a; // pointer
    std::cout << *p_a << " " << p_a << std::endl; // *: T*->T
    // сложение
    std::cout << p_a + 1 << " " << &b << std::endl; // +: (T*, int) = T* + sizeof(T)
    int* p_b = &b;
    // вычитание
    std::cout << p_b - 1 << " " << &a << std::endl; // -: (T*, int) = T* - sizeof(T)
    // префиксный, постфиксный инкремент
    ++p_a; // p_a = p_a + 1
    p_a++; // p_a = p_a + 1
    // префиксный, постфиксный декремент
    --p_a; // p_a = p_a - 1
    p_a--; // p_a = p_a - 1

    std::vector<int> vec {1, 2, 3};
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;

    for (int* p = &vec[0]; p != (&vec[0] + vec.size()); ++p)
    {
        std::cout << p << ' ' << *p << ' ';
    }
    std::cout << std::endl;

    std::cout << &vec << " " << &vec[0] << std::endl;
    std::cout << &vec[0] - &vec[4] << std::endl;

    // размер указателя
    std::cout << sizeof(p_a) << std::endl;

    // void*, C-style
    void* v_a = &a;
    std::cout << v_a << std::endl; // OK
    // std::cout << *v_a << std::endl; // CE

    // NULL and nullptr
    int c = 0;
    int* p_c_n = NULL; // 0
    int* p_c_nptr = nullptr; // Нулевой указатель

    if (p_c_nptr == nullptr)
    {
        std::cout << "nullptr" << std::endl;
    }

    int mass[3];
    std::cout << mass[2]; // (mass[0] + 2)
    // 1 2 3 (UB)
    std::cout << *mass << ' ' << (mass[0]) << std::endl;

}
