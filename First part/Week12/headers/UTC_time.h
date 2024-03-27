#pragma once

#include "custom_date_time.h"
#include "base_date.h"

/**
 * @brief класс для работы с UTC временем
 */
class UTCTime : public BaseDate
{
public:
    UTCTime(const Date& date, const Time& time);

    bool operator<(const UTCTime& other) const;

    /**
     * @brief перегруженный метод базового класса, возвращает дату в формате UTC
     * @return дата в формате UTC
     */
    std::string TimeToStr() const final;

private:
    const Time m_time;
};
