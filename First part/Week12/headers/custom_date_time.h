#pragma once

#include <vector>

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
    return std::vector<int>{lhs.m_hours, lhs.m_mins, lhs.m_secs} <
        std::vector<int>{rhs.m_hours, rhs.m_mins, rhs.m_secs};
}
