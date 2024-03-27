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

Duration ReadDuration(std::istream& stream)
{
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    return Duration{.hours = h, .mins = m};
}

void Print(std::ostream& stream, const Duration duration)
{
    stream << std::setw(2) << std::setfill('0');
    stream << duration.hours << ':';
    stream << std::setw(2) << std::setfill('0');
    stream << duration.mins;
}

int main()
{
    // function input, stringstream
    {
        // "01:23"
        std::stringstream stream("01:03");
        Duration dur = ReadDuration(stream);
        Print(std::cout, dur);
        std::cout << std::endl;
    }
}
