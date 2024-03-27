#include <iostream>
#include <fstream>
#include <limits>

int main()
{
    // getline
    {
        std::ifstream stream("date.txt");
        if (!stream)
        {
            std::cout << "Smth went wrong" << std::endl;
        }
        else
        {
            std::string day, month, year;
            std::getline(stream, day, '-');
            std::getline(stream, month, '-');
            std::getline(stream, year);
            std::cout << day << ' ' << month << ' ' << year << std::endl;
        }
    }

    // >> input
    {
        std::ifstream stream("date.txt");
        if (!stream)
        {
            std::cout << "Smth went wrong" << std::endl;
        }
        else
        {
            int day = 0;
            int month = 0;
            int year = 0;
            stream >> day;
            //
            if (stream.get() != '-')
            {
                // smth wrong with format
                std::cout << "wrong format " << std::endl;
            }
            stream.ignore(1);
            stream >> month;
            //
            stream.ignore(1);
            stream >> year;
            std::cout << day << ' ' << month << ' ' << year << std::endl;
        }
    }

    // << output/write
    {

    }
}
