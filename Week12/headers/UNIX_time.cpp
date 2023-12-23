#include "UNIX_time.h"

UNIXTime::UNIXTime(const Date& date, const int secs) :
    BaseDate(date),
    m_secs(secs)
{
}

UNIXTime::UNIXTime() :
    BaseDate({.m_year = -1, .m_month = -1, .m_day = -1}),
    m_secs(static_cast<int>(UNIX_LIMITS::UL_MAX))
{}

bool UNIXTime::operator<(const UNIXTime& other) const
{
    return m_secs < other.m_secs;
}

std::string UNIXTime::TimeToStr() const final
{
    const Date& date = BaseDate::GetDate();
    return std::string("UNIXTime " + std::to_string(date.m_year) + '.' + std::to_string(date.m_month) + '.' +
        std::to_string(date.m_day) + ' ' + std::to_string(m_secs));
}
