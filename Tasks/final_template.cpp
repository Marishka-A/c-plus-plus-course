#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>

class Date
{
public:
    Date(int year, int month, int day): m_year(year), m_month(month), m_day(day) {}
    int GetYear() const
    {
        return m_year;
    }
    int GetMonth() const
    {
        return m_month;
    }
    int GetDay() const
    {
        return m_day;
    }
private:
    int m_year, m_month, m_day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
           std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

Date ParsingDate(std::istringstream& is) {
    std::string date;
    is >> date;
    std::istringstream parsedate (date);
    int year, month, day, part;
    for (int i = 0; i < date.size(); i++)
    {
        parsedate >> part;
        if ((parsedate.peek() != '-' && i != 2) || (!parsedate.eof() && i == 2))
            throw std::runtime_error("Wrong date format: " + date);
        if (i == 0)
            year = part;
        else if (i == 1)
            month = part;
        else
            day = part;
    }
    if (month < 1 || month > 12)
        throw std::runtime_error("Month value is invalid: " + std::to_string(month));
    if (day < 1 || day > 31)
        throw std::runtime_error("Day value is invalid: " + std::to_string(day));
    return Date(year, month, day);
}

class Database
{
public:
  void AddEvent(const Date& date, const std::string& event)
  {
      m_database[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const std::string& event)
  {
      if (auto it = m_database.find(date); it != m_database.end())
      {
          return it->second.erase(event) != 0;
      }
      return false;
  }

  int  DeleteDate(const Date& date)
  {
      int count = m_database[date].size();
      m_database[date].clear();
      return count;
  }

    std::set<std::string> Find(const Date& date)
    {
        return m_database[date];
    }
  
  void Print() const
  {
      for (const auto& database : m_database)
          for (const auto& event : database.second)
          {
              std::cout << std::setw(4) << std::setfill('0')<<database.first.GetYear() << '-';
              std::cout << std::setw(2) << std::setfill('0')<<database.first.GetMonth() << '-';
              std::cout << std::setw(2) << std::setfill('0')<<database.first.GetDay() << ' ' << event << '\n';
          }
  }
private:
    std::map<Date, std::set<std::string>> m_database;
};

int main()
{
  Database db;

  std::string commandLine;
  while (std::getline(std::cin, commandLine))
  {
      std::istringstream stream(commandLine);
      std::string command, event;
      stream >> command;
      try
      {
          if (command == "Add")
          {
              Date parse_date = ParsingDate(stream);
              stream >> event;
              db.AddEvent(parse_date,event);
          }
          else if (command == "Del")
          {
              Date parse_date = ParsingDate(stream);
              stream >> event;
              if (event.empty())
                  std::cout << "Deleted " << db.DeleteDate(parse_date) << " events" << std::endl;
              else
              {
                  if (db.DeleteEvent(parse_date, event))
                      std::cout << "Deleted successfully" << std::endl;
                  else
                      std::cout << "Event not found" << std::endl;
              }
          }
          else if (command == "Find")
          {
              Date parse_date = ParsingDate(stream);
              std::set<std::string> events = db.Find(parse_date);
              for (const auto& event : events)
                  std::cout << event << std::endl;
          }
          else if (command == "Print")
              db.Print();
          else if (command.empty())
              continue;
          else
              throw std::runtime_error("Unknown command: " + command);
      }
      catch (const std::runtime_error& error)
      {
          std::cout << error.what() << std::endl;
      }
  }
  return 0;
}
