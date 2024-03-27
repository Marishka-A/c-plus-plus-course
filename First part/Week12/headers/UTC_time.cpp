#include "UTC_time.h"

UTCTime::UTCTime(const Date& date, const Time& time) :
    BaseDate(date),
    m_time(time)
{
}

bool UTCTime::operator<(const UTCTime& other) const;


std::string UTCTime::TimeToStr() const final
{
    const Date& date = BaseDate::GetDate();
    return std::string("UTCTime " + std::to_string(date.m_year) + '.' + std::to_string(date.m_month) + '.' +
        std::to_string(date.m_day) + ' ' + std::to_string(m_time.m_hours) + ':' + std::to_string(m_time.m_mins) +
        ':' + std::to_string(m_time.m_secs));
}