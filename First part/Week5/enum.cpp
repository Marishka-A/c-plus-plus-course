#include <iostream>
#include <limits>
#include <vector>
#include <map>

/*
    Пишем свою дату, применяя наследование и enum class
*/

enum class WEEKDAY
{
    MONDAY = 0,
    TUESDAY,
    WEDNESDAY,
    THRUSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    UNKNOWN
};

struct Date
{
    int m_year = -1;
    int m_month = -1;
    int m_day = -1;
};

class DateDate
{
public:
    // Добавим возможность хранить день недели в дате
    // по дефолту заполним неизвестным значением
    explicit DateDate(const Date& date, const WEEKDAY wd = WEEKDAY::UNKNOWN) :
        m_date(date),
        m_weekday(wd)
    {
    }

    const Date& GetDate() const
    {
        return m_date;
    }

    WEEKDAY GetWeekday() const
    {
        return m_weekday;
    }

private:
    const Date m_date;
    WEEKDAY m_weekday;
};

struct Time
{
    int m_hours = -1;
    int m_mins = -1;
    int m_secs = -1;
};

class UTCTime : public DateDate
{
public:
    UTCTime(const Date& date, const Time& time) :
        DateDate(date),
        m_time(time)
    {
    }

private:
    const Time m_time;
};

class UNIXTime : public DateDate
{
    /*
        Заключаем максимальное и минимальное время в enum class,
        чтобы повысить читаемость
    */
    enum class UNIX_LIMITS
    {
        UL_MIN = 0,
        UL_MAX = std::numeric_limits<int>::max()
    };
public:
    UNIXTime(const Date& date, const int secs) :
        DateDate(date),
        m_secs(secs)
    {
    }

    // напишем дефолтный конструктор,
    // который будет создавать объект с невалидным временем
    UNIXTime() :
        DateDate({.m_year = -1, .m_month = -1, .m_day = -1}),
        m_secs(static_cast<int>(UNIX_LIMITS::UL_MAX))
    {}

private:
    const int m_secs;
};

class DateTime
{
public:
    explicit DateTime(const Time& time) :
        m_time(time)
    {}

private:
    const Time m_time;
};

int main()
{
    DateDate date({.m_year{2023}, .m_month{10}, .m_day{20}});
    const auto& [year, month, day] = date.GetDate();
    std::cout << year << " " << month << " " << day << std::endl;
}
