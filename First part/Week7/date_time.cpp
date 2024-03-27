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

/**
 * @brief структура даты для удобства работы, позволяет не хранить три поля внутри класса
 */
struct Date
{
    int m_year = -1;
    int m_month = -1;
    int m_day = -1;
};

/**
 * @brief оператор < для работы с датами
 * @param lhs дата слева
 * @param rhs дата справа
 * @return true дата слева меньше даты справа
 * @return false дата слева больше или равно даты справа
 */
bool operator<(const Date& lhs, const Date& rhs)
{
    return std::vector<int>{lhs.m_year, lhs.m_month, lhs.m_day} < 
        std::vector<int>{rhs.m_year, rhs.m_month, rhs.m_day};
}

/**
 * @brief Абстрактный класс даты
 */
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

    // оператор для сравнения базовых дат
    bool operator<(const BaseDate& other) const
    {
        return m_date < other.m_date;
    }

    /**
     * @brief pure vitrual метод для перегрузки в классах наследниках
     * @return std::string
     */
    virtual std::string TimeToStr() const = 0;

    /**
     * @brief Получить объект даты
     * @return дата
     */
    const Date& GetDate() const
    {
        return m_date;
    }

    /**
     * @brief Получить текущий день недели
     * @return день недели
     */
    WEEKDAY GetWeekday() const
    {
        return m_weekday;
    }

private:
    const Date m_date;
    WEEKDAY m_weekday;
};

/**
 * @brief Структура, оборачивающая UTC время
 */
struct Time
{
    int m_hours = -1;
    int m_mins = -1;
    int m_secs = -1;
};

bool operator<(const Time& lhs, const Time& rhs)
{
    return std::vector<int>{lhs.m_hours, lhs.m_mins, lhs.m_secs} < std::vector<int>{rhs.m_hours, rhs.m_mins, rhs.m_secs};
}

/**
 * @brief класс для работы с UTC временем
 */
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

    /**
     * @brief перегруженный метод базового класса, возвращает дату в формате UTC
     * @return дата в формате UTC
     */
    std::string TimeToStr() const final
    {
        const Date& date = BaseDate::GetDate();
        return std::string("UTCTime " + std::to_string(date.m_year) + '.' + std::to_string(date.m_month) + '.' +
            std::to_string(date.m_day) + ' ' + std::to_string(m_time.m_hours) + ':' + std::to_string(m_time.m_mins) +
            ':' + std::to_string(m_time.m_secs));
    }

private:
    const Time m_time;
};

/**
 * @brief класс для работы с UNIX временем
 */
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

    /**
     * @brief перегруженный метод базового класса, возвращает дату в формате UNIX
     * @return дата в формате UNIX
     */
    std::string TimeToStr() const final
    {
        const Date& date = BaseDate::GetDate();
        return std::string("UNIXTime " + std::to_string(date.m_year) + '.' + std::to_string(date.m_month) + '.' +
            std::to_string(date.m_day) + ' ' + std::to_string(m_secs));
    }

private:
    const int m_secs;
};

// Создать журнал, в котором будет время - запись (имя)
// Вставка новой записи (время), удаление записи (время), получение записи (время)
// log (N)
// Контейнер std::map<BaseDate, std::string>

// Логгер, который пишет информацию о командах в формате время + команда
// получить журнал записей
// Контейнер std::vector<Log>

// Время - BaseDate

/**
 * @brief виды команд для обработки в журнале
 */
enum class LOG_COMMANDS
{
    LC_CREATE = 0,
    LC_ERASE,
    LC_GET,
    LC_PRINT
};

/**
 * @brief контейнер для ассоциации команда - строка
 */
static const std::map<LOG_COMMANDS, std::string> LOG_COMMANDS_TO_STR = {
    {LOG_COMMANDS::LC_CREATE, "CREATE"},
    {LOG_COMMANDS::LC_ERASE, "ERASE"},
    {LOG_COMMANDS::LC_GET, "GET"},
    {LOG_COMMANDS::LC_PRINT, "PRINT"}
};

/**
 * @brief структура, оборачивающая лог
 */
struct Log
{
    std::string m_date;
    LOG_COMMANDS m_cmd;
};

/**
 * @brief класс для работы с логами
 */
class Logger
{
public:
    Logger() = default;

    void AddLog(const Log& log)
    {
        m_logs.push_back(log);
    }

    void PrintLogs() const
    {
        for (const auto& [time, cmd] : m_logs)
        {
            //
            std::cout << time << " " << LOG_COMMANDS_TO_STR.at(cmd) << std::endl;
            //std::cout << LOG_COMMANDS_TO_STR.at(cmd) << " " << time->TimeToStr() << std::endl;
        }
    }
private:
    std::vector<Log> m_logs;
};

// одиночка логгер для всей программы
static Logger LOGGER;

// алиасы на std::shared_ptr (чтобы не писать каждый раз длинное название)
using t_utc = std::shared_ptr<UTCTime>;
using t_unix = std::shared_ptr<UNIXTime>;
using t_baseDate = std::shared_ptr<BaseDate>;

// перегружаем оператор < для шаред_птр даты
bool operator<(const t_baseDate& lhs, const t_baseDate& rhs)
{
    // BaseDate lhs < BaseDate rhs
    return *lhs < *rhs;
}

/**
 * @brief класс журнала, хранит время + запись
 */
class Journal
{
public:
    Journal() = default;

    // создать заявку
    void CreateReq(const t_baseDate& time, const std::string& name)
    {
        LOGGER.AddLog(Log{.m_date = time->TimeToStr(), .m_cmd = LOG_COMMANDS::LC_CREATE});
        m_reqs[time] = name;
    }

    // удаление заявки
    void EraseReq(const t_baseDate& time)
    {
        LOGGER.AddLog(Log{.m_date = time->TimeToStr(), .m_cmd = LOG_COMMANDS::LC_ERASE});
        m_reqs.erase(time);
    }

    // получение заявки
    std::string GetReq(const t_baseDate& time) const
    {
        LOGGER.AddLog(Log{.m_date = time->TimeToStr(), .m_cmd = LOG_COMMANDS::LC_GET});
        if(m_reqs.contains(time))
        {
            return m_reqs.at(time);
        }
        return std::string();
    }

    // печать всех заявок
    void PrintDates() const
    {
        LOGGER.AddLog(Log{.m_date = "Cur time", .m_cmd = LOG_COMMANDS::LC_PRINT});
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
        // контейнер входящих дат
        std::vector<t_baseDate> inputDates {std::make_shared<UNIXTime>(Date{.m_year = 2023, .m_month = 10, .m_day = 25}, 1232365),
            std::make_shared<UTCTime>(Date{.m_year = 2023, .m_month = 10, .m_day = 24}, Time{.m_hours = 17, .m_mins = 10, .m_secs = 30})};
        journal.CreateReq(inputDates[0], "Sharik1");
        journal.CreateReq(inputDates[1], "Sharik2");
        journal.PrintDates();
        std::cout << journal.GetReq(inputDates[0]) << std::endl;
        LOGGER.PrintLogs();
    }
}
