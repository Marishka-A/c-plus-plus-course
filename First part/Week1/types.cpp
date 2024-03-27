#include <array>
#include <iostream>
#include <limits>
#include <vector>

int main()
{
    // 1. Types

    // 1.1 Integral types
    int _int;
    std::cout << sizeof(int) << std::endl;
    long _long;
    std::cout << sizeof(long) << std::endl;
    long long _longLong; // equals to long
    short _short;
    std::cout << sizeof(short) << std::endl;

    int first = 2'140'000'000;
    int second = 2'140'000'000;
    // int third = first + second; UB, переполнение int

    unsigned long _longFirst = -1; // OK, _longFirst - максимальное значение,
                                   // которое может храниться в unsigned long
    std::cout << _longFirst << std::endl;
    // можем убедиться с помощью специального синтаксиса
    std::cout << (std::numeric_limits<unsigned long>::max() == (unsigned long)(-1)) << std::endl;

    size_t _size_t; // специальный беззнаковый целочисленный тип для индексов
    std::cout << sizeof(size_t) << std::endl;

    char _char;      // ASCII Char
    wchar_t _w_char; // Windows char (unicode)
    std::cout << sizeof(wchar_t) << std::endl;
    bool _bool; // 1,0
    std::cout << sizeof(bool) << std::endl;

    // 1.2 Floating types
    float _float;
    double _double = 2.2;
    long double _longDouble;
    int _intDouble = 2.2;
    std::cout << _intDouble << std::endl;

    // 1.3 Compound types

    // 1.3.1 String
    std::string _string = "abc"; // "abc" != std::string
    std::cout << _string << std::endl;
    std::cout << _string[0] << _string[3]
              << std::endl; // [0] = a, [3] = '\0' (null terminate)
    //<< _string.at(3) << std::endl; exсeption std::out_of_range

    std::string _stringSecond = "bcd";
    _stringSecond += _string;                // no extra copy
    _stringSecond = _stringSecond + _string; // copy
    std::cout << _stringSecond << std::endl;

    _string.push_back('A');
    std::cout << _string << std::endl;
    _string.pop_back();
    std::cout << _string << std::endl;

    _string.insert(0, "Hello World! ");
    std::cout << _string << std::endl;
    std::cout << _string.front() << " " << _string.back() << std::endl;

    // 1.3.2 Vector
    std::vector<int> vec {1, 2, 3}; // Init list, since C++11
    std::cout << vec[2] << vec.at(2) << std::endl;
    vec.push_back(4); // 1, 2, 3, 4
    vec.pop_back();   // 1, 2, 3

    // Range based for, since C++ 11
    for (int v : vec)
    {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
    // Equals to
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << vec.front() << " " << vec.back() << std::endl; // 1, 3

    std::vector<int> secondVec;
    secondVec.reserve(10);                      // allocate new RAW mem
    std::cout << secondVec.size() << std::endl; // vec.size() == 0
    secondVec.resize(10);                       // allocate mem and CONSTRUCT elems, vec.size() == 10
    std::cout << secondVec.size() << std::endl;
    secondVec.clear(); // destruct elems, vec.size() == 10, but mem == 10
    std::cout << secondVec.size() << " " << secondVec.capacity() << std::endl;

    // 1.4 C-style array
    int _intMass = 5;
    int mass[10];
    std::cout << mass[-1] << std::endl; // UB

    // 1.4.1 Array (also compound type)
    std::array<int, 5> _array{1, 2, 3, 4, 5};
    std::cout << _array[0] << " " << _array.at(4) << std::endl;
    std::cout << _array.front() << " " << _array.back() << std::endl;
    std::cout << _array.size() << std::endl;

    // 1.5 Literals and literal suffixes
    // 5(int), 0.2(double)
    // 'A' (char)
    // "abc" (const char*)

    unsigned _intLit = 5u;
    float _floatLit = 0.2f;
    int _int16Num = 0xff; // 16 ричная СС
    int _int8Num = 0123; // 8 ричная СС
    int _int8num = 0b101;


    // Extra cash, initialization methods, example with std::string
    // std::string _stringInit = "abc";
    // std::string _stringInit {"abc"};
    // std::string _stringInit("abc");
    // std::string _stringInit = std::string("abc");

    // return 0; можно не писать since C++11
}
