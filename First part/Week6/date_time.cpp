#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <memory>

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

bool operator<(const Date& lhs, const Date& rhs)
{
    return (lhs.m_year < rhs.m_year) && (lhs.m_month < rhs.m_year) && (lhs.m_day < rhs.m_day);
}

class BaseDate
{
public:
    // Добавим возможность хранить день недели в дате
    // по дефолту заполним неизвестным значением
    explicit BaseDate(const Date& date, const WEEKDAY wd = WEEKDAY::UNKNOWN) :
        m_date(date),
        m_weekday(wd)
    {
    }

    bool operator<(const BaseDate& other) const
    {
        return m_date < other.m_date;
    }

    virtual std::string TimeToStr() const = 0;

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

bool operator<(const Time& lhs, const Time& rhs)
{
    return (lhs.m_hours < rhs.m_hours) && (lhs.m_mins < rhs.m_mins) && (lhs.m_secs < rhs.m_secs);
}

class UTCTime : public BaseDate
{
public:
    UTCTime(const Date& date, const Time& time) :
        BaseDate(date),
        m_time(time)
    {
    }

bool operator<(const UTCTime& other) const
{
    return m_time < other.m_time;
}

virtual std::string TimeToStr() const override final
{
    const Date& date = BaseDate::GetDate();
    return std::string("UTCTime " + std::to_string(date.m_year) + '.' + std::to_string(date.m_month) + '.' +
        std::to_string(date.m_day) + ' ' + std::to_string(m_time.m_hours) + ':' + std::to_string(m_time.m_mins) +
        ':' + std::to_string(m_time.m_secs));
}

private:
    const Time m_time;
};

class UNIXTime : public BaseDate
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
        BaseDate(date),
        m_secs(secs)
    {
    }

    // напишем дефолтный конструктор,
    // который будет создавать объект с невалидным временем
    UNIXTime() :
        BaseDate({.m_year = -1, .m_month = -1, .m_day = -1}),
        m_secs(static_cast<int>(UNIX_LIMITS::UL_MAX))
    {}

    bool operator<(const UNIXTime& other) const
    {
        return m_secs < other.m_secs;
    }

    virtual std::string TimeToStr() const override final
    {
        const Date& date = BaseDate::GetDate();
        return std::string("UNIXTime " + std::to_string(date.m_year) + '.' + std::to_string(date.m_month) + '.' +
            std::to_string(date.m_day) + ' ' + std::to_string(m_secs));
    }

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

// Создать журнал, в котором будет время - запись (имя)
// Вставка новой записи (время), удаление записи (время), получение записи (время)
// log (N)
// Контейнер std::map<BaseDate, std::string>

// Логгер, который пишет информацию о командах в формате время + команда
// получить журнал записей
// Контейнер std::vector<Log>

// Время - BaseDate

using t_utc = std::shared_ptr<UTCTime>;
using t_unix = std::shared_ptr<UNIXTime>;
using t_baseDate = std::shared_ptr<BaseDate>;

class Journal
{
public:
    Journal() = default;

    // создать заявку
    void CreateReq(const t_unix& time, const std::string& name)
    {
        m_reqs[time] = name;
    }

    void CreateReq(const t_utc& time, const std::string& name)
    {
        m_reqs[time] = name;
    }
    // удаление заявки
    void EraseReq(const t_baseDate& time)
    {
        m_reqs.erase(time);
    }
    // получение заявки
    std::string GetReq(const t_baseDate& time) const
    {
        if(m_reqs.contains(time))
        {
            std::cout << "Exist" << std::endl;
            return m_reqs.at(time);
        }
        return std::string();
    }

    void PrintDates() const
    {
        for (const auto& [time, name] : m_reqs)
        {
            std::cout << time->TimeToStr() << " " << name << std::endl;
        }
    }
private:
    std::map<t_baseDate, std::string> m_reqs;
};

int main()
{
    {
        Journal journal;
        journal.CreateReq(std::make_shared<UNIXTime>(Date{.m_year = 2023, .m_month = 10, .m_day = 25}, 1232365), "Sharik");
        journal.CreateReq(std::make_shared<UTCTime>(Date{.m_year = 2023, .m_month = 10, .m_day = 24}, Time{.m_hours = 17, .m_mins = 10, .m_secs = 30}), "Sharik");
        journal.PrintDates();
        std::cout << std::endl;
        journal.GetReq(std::make_shared<UNIXTime>(Date{.m_year = 2023, .m_month = 10, .m_day = 23}, 1232365));
        journal.PrintDates();
    }
    //BaseDate date({.m_year{2023}, .m_month{10}, .m_day{20}});
    //const auto& [year, month, day] = date.GetDate();
    //std::cout << year << " " << month << " " << day << std::endl;
}
