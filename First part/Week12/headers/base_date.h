#pragma once

#include "date.h"

#include <iostream>

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
 * @brief Абстрактный класс даты
 */
class BaseDate
{
public:
    // Добавим возможность хранить день недели в дате
    // по дефолту заполним неизвестным значением
    explicit BaseDate(const Date& date, const WEEKDAY wd = WEEKDAY::UNKNOWN);

    // оператор для сравнения базовых дат
    bool operator<(const BaseDate& other) const;

    /**
     * @brief pure vitrual метод для перегрузки в классах наследниках
     * @return std::string
     */
    virtual std::string TimeToStr() const = 0;

    /**
     * @brief Получить объект даты
     * @return дата
     */
    const Date& GetDate() const;

    /**
     * @brief Получить текущий день недели
     * @return день недели
     */
    WEEKDAY GetWeekday() const;

private:
    const Date m_date;
    WEEKDAY m_weekday;
};
