#include <iostream>
#include <fstream>
#include <limits>

// istream input
// ostream output
// iostream input/outputs

// ifstream чтение
// ofstream запись
// fstream чтение и запись

int main()
{
    // cin
    {
        int i;
        std::cin >> i; // console input >>
        std::cout << i + 5 << std::endl; // console output <<
    }

    // getline
    {
        std::ifstream stream("hello.txt");
        std::string input;

        if (stream)
        {
            while(std::getline(stream, input))
            {
                std::cout << input << std::endl;
            }
        }
        else
        {
            std::cout << "File doesnt exist or smth went wrong" << std::endl;
        }
    }
}
