#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

// file manip
#include <iomanip>

void Print(const std::string& path)
{
    std::ifstream stream(path);
    if (!stream)
    {
        std::cout << "Bad path" << std::endl;
    }
    else
    {
        std::string input;
        while (std::getline(stream, input))
        {
            std::cout << input << std::endl;
        }
        
    }
}

void PrintTable(const std::vector<std::string>& names, const std::vector<double>& values,
    const int width)
{
    std::cout << std::setfill('x');
    for (const auto& n : names)
    {
        std::cout << std::setw(width) << n << std::setw(width) << ' ';
    }
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    for (const auto& v : values)
    {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    // << output/write
    {
        const std::string path = "output.txt";
        // для дозаписи флаг std::ios::app
        std::ofstream stream(path);
        if (!stream)
        {
            std::cout << "Bad file path" << std::endl;
        }
        else
        {
            stream << "Hello" << '\n';
            Print(path);
        }
    }

    // Formating
    {
        // std::fixed
        // далее нужно выводить на экран с фиксированной точностью
        // std::setprecision
        // сколько символов после запятой нужно вывести
        // std::setw
        // обозначает ширину поля, которое резервируется для вывода
        // std::setfill
        // указывает каким символом заполнить пустые места
        // std::left/std::right
        // выровнять по левому краю/выровнять по правому краю
        std::vector<std::string> names = {"a", "b", "c"};
        std::vector<double> values = {5, 0.01, 0.000005};
        PrintTable(names, values, 4);
    }
}
