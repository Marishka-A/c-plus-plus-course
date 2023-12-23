#include <iostream>

#include "header_2.hpp"
#include "header.hpp"

// main.cpp <- header2 -< header
// | <- header

#define MAGIC_NUMBER 12

#ifdef X_86
    const int a = 1;
#else
    const int a = 2;
#endif

int main()
{
    std::string abs;
    // comment
    std::cout << MAGIC_NUMBER << std::endl;
    std::cout << __LINE__ << std::endl;
    std::cout << "Hello world!" << std::endl;
}
