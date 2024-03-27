#include <algorithm>
#include <iostream>
#include <vector>

// 2.4 Lambda and std::algorithm

struct Date
{
    int m_day = -1;
    int m_month = -1;
    int m_year = -1;
};

void PrintDate(const Date& date)
{
    std::cout << date.m_day << ' ' << date.m_month << ' ' << date.m_year << std::endl;
}

Date CreateDate(const int day = -1, const int month = -1, const int year = -1)
{
    //return {day, month, year};
    //return Date{day, month, year};
    return {.m_day{day}, .m_month{month},.m_year{year}};
}

void PrintDates(const std::vector<Date>& dates)
{
    //for (const auto& d : dates)
    //{
    //    PrintDate(d);
    //}
    // Since C++20
    for (const auto& [day, month, year] : dates)
    {
        std::cout << day << ' ' << month << ' ' << year << std::endl;
    }
}

bool CompareDates(const Date& lhs, const Date& rhs)
{
    return lhs.m_year < rhs.m_year;
}

void SortDates(std::vector<Date>& dates)
{
    //   1 2 3  x
    // begin   end
    // begin = 1, end = x
    const auto beg = dates.begin(); // dates[0]
    const std::vector<Date>::iterator end = dates.end(); // dates[size()]

    //std::sort(dates.begin(), dates.end(), CompareDates);

    // Lambda since C++11, update C++14, C++17, C++20
    // [](pararms){body}
    std::sort(dates.begin(), dates.end(), [](const Date& lhs, const Date& rhs){
        return lhs.m_year < rhs.m_year;
    });
}

bool operator==(const Date& lhs, const Date& rhs)
{
    return lhs.m_day == rhs.m_day && lhs.m_month == rhs.m_month && lhs.m_year == rhs.m_year;
}

size_t CountDate(const std::vector<Date>& dates, const Date& date = {-1, -1, -1})
{
    return std::count(dates.begin(), dates.end(), date);
}

struct DataBase
{

    void AddDate(const Date& date)
    {
        m_dates.push_back(date);
    }
    void AddDate(const int day, const int month, const int year)
    {
        m_dates.push_back({.m_day{day}, .m_month{month},.m_year{year}});
    }

    void PrintDates() const
    {
        for (const auto& [day, month, year] : m_dates)
        {
            std::cout << day << ' ' << month << ' ' << year << std::endl;
        }
        //m_dates.push_back({-1, 0, 0});
        const size_t s = m_dates.size();
    }

    void SortDates()
    {
        std::sort(m_dates.begin(), m_dates.end(), [](const Date& lhs, const Date& rhs){
            return lhs.m_day < rhs.m_day;
        });
    }

    size_t CountDates(const Date& date)
    {
        return std::count(m_dates.begin(), m_dates.end(), date);
    }

    // BAD!!!
    void EraseDate(const Date& date)
    {
        const auto it = std::find(m_dates.begin(), m_dates.end(), date); // O(N), N = size()
        if (it != m_dates.end())
        {
            m_dates.erase(it); // O(N) N = size()
        }
        // O(N^2)
    }

private:
    std::vector<Date> m_dates;
};

int main()
{
    {
        std::cout << "Single Date: ";
        Date date {.m_day{6}, .m_month{10}, .m_year{2023}};
        PrintDate(date);
        PrintDate(CreateDate());
    }
    {
        std::cout << "Vector dates: ";
        std::vector<Date> dates;
        dates.push_back({.m_day{3}, .m_month{4}, .m_year{2020}});
        dates.push_back(CreateDate(2, 10, 2019));
        dates.push_back(Date{});
        SortDates(dates);
        PrintDates(dates);
        std::cout << "Count dates= " << CountDate(dates, {1, 10, 2019}) << std::endl;
    }
    {
        std::cout << "Data base: ";
        DataBase dataBase;
        dataBase.AddDate({.m_day{3}, .m_month{4}, .m_year{2020}});
        dataBase.AddDate(CreateDate(2, 10, 2019));
        dataBase.AddDate(-1, -1, -1);
        dataBase.PrintDates();
        dataBase.SortDates();
        dataBase.PrintDates();
        std::cout << dataBase.CountDates({3, 4, 2020}) << std::endl;
        dataBase.EraseDate({3, 4, 2020});
    }
}
