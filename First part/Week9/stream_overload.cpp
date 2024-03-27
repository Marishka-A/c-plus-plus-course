#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct Duration
{
    int hours;
    int mins;
};

// ReadDuration + create, PrintDuration

// output
std::ostream& operator<<(std::ostream& stream, const Duration& duration)
{
    stream << std::setw(2) << std::setfill('0');
    stream << duration.hours << ':';
    stream << std::setw(2) << std::setfill('0');
    stream << duration.mins;

    return stream;
}

std::istream& operator>>(std::istream& stream, Duration& duration)
{
    stream >> duration.hours;
    stream.ignore(1);
    stream >> duration.mins;

    return stream;
}

Duration ReadDuration(std::istream& stream)
{
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;

    return Duration{.hours = h, .mins = m};
}

void PrintDuration(std::ostream& stream, const Duration duration)
{
    stream << std::setw(2) << std::setfill('0');
    stream << duration.hours << ':';
    stream << std::setw(2) << std::setfill('0');
    stream << duration.mins;
}

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& vec)
{
    for (const auto& v : vec)
    {
        stream << v << ' ';
    }

    return stream;
}

int main()
{
    // function input, stringstream
    {
        // "01:23"
        std::stringstream stream("01:03");
        Duration dur = ReadDuration(stream);
        PrintDuration(std::cout, dur);
        std::cout << std::endl;
    }
    // operators >>/ <<
    {
        std::stringstream stream("01:03");
        Duration duration;
        std::cin >> duration;
        std::cout << duration << std::endl;
    }
    // << for std::vector
    {
        std::vector<int> vec = {1, 2, 3};
        std::cout << vec << std::endl;
    }
}
