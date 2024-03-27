#include <iostream>

// casts C++

void foo(const int a)
{
    std::cout << a << std::endl;
}

void bar(const int* p_i, const int& c_i)
{
    // pointer
    int* p;
    p = (int*)p_i;
    *p = 33;
    std::cout << *p << std::endl;

    // ref
    const_cast<int&>(c_i) = 30;
    std::cout << c_i << std::endl;
}

class A
{
};

class B : public A
{
};

int main()
{
    int a = 5000;
    double b = 23232.28923;
    foo(b);
    std::cout << a << std::endl;
    // C-style cast
    {
        double b = 28723823.2002;
        std::cout << (int)b << std::endl;
        void* v_ptr;
        int* int_ptr = new int(5);
        v_ptr = int_ptr;
        std::cout << *(double*)v_ptr << std::endl; // UB, potentional Segfault
    }
    // const_cast C++
    {
        const int c_i = 5;
        const int c_i2 = 7;
        bar(&c_i, c_i2);
    }
    // reinterpet_cast
    {
        int* i_ptr = new int(5);
        double* d_ptr = reinterpret_cast<double*>(i_ptr);
        std::cout << *d_ptr << std::endl; // UB, potentional Segfault
    }
    // static_cast
    {
        int a = 64;
        double d = 7;
        char c = 'a';
        int* p_i = &a;
        double* p_d = &d;
        c = static_cast<char>(*p_d);
        std::cout << c << std::endl;
    }
    // dynamic_cast
    {
        B* b = new B;
        A* a = dynamic_cast<A*>(b);
    }
}
