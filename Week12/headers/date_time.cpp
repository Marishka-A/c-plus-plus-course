#include "UNIX_time.h"
#include "UTC_time.h"

#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <memory>

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
