#pragma once

#include "base_date.h"

#include <limits>

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
    UNIXTime(const Date& date, const int secs);

    // напишем дефолтный конструктор,
    // который будет создавать объект с невалидным временем
    UNIXTime();

    bool operator<(const UNIXTime& other) const;

    /**
     * @brief перегруженный метод базового класса, возвращает дату в формате UNIX
     * @return дата в формате UNIX
     */
    std::string TimeToStr() const final;

private:
    const int m_secs;
};