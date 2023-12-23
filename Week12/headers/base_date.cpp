#include "base_date.h"

#include <iostream>

BaseDate::BaseDate(const Date& date, const WEEKDAY wd = WEEKDAY::UNKNOWN) :
        m_date(date),
        m_weekday(wd)
{
    std::cout << "BaseDate" << std::endl;
}

bool BaseDate::operator<(const BaseDate& other) const
{
    return m_date < other.m_date;
}

const Date& BaseDate::GetDate() const
{
    return m_date;
}

WEEKDAY BaseDate::GetWeekday() const
{
    return m_weekday;
}
