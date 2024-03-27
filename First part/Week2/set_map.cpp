#include <iostream>
#include <map>
#include <set>

// 1.9 Set and map

// Functions to print containers

void PrintSet(const std::set<char>& _set)
{
    for (auto s : _set)
    {
        std::cout << s << ' ';
    }
    std::cout << std::endl;
}

void PrintSet(const std::set<int>& _set)
{
    for (auto s : _set)
    {
        std::cout << s << ' ';
    }
    std::cout << std::endl;
}

bool IsElemSet(const std::set<int>& _set, const int elem) { return _set.count(elem); }

void PrintMap(std::map<std::string, int> _map)
{
    // C++ 17
    for (auto [key, value] : _map)
    {
        std::cout << key << ' ' << value << ' ';
    }
    std::cout << std::endl;
}

std::set<char> UniqChars(std::string str)
{
    std::set<char> _set;
    for (auto s : str)
    {
        _set.insert(s);
    }
    return _set;
}

int main()
{
    // std::set
    {
        // множество, уникальные элементы, отстортированы, дерево
        std::set<int> _set{3, 1, 2};
        PrintSet(_set);
        _set.insert(4);
        _set.erase(1);
        PrintSet(_set);
        std::cout << IsElemSet(_set, 5) << std::endl;
        _set.clear();
        std::cout << _set.size() << std::endl;
    }

    // std::map
    {
        // словарь, уникальные ключи, отсортированы, дерево красно-черное
        std::map<std::string, int> _map{{"Pasha", 4}, {"Masha", 5}};
        // rewrite value
        _map["Dasha"] = 5;
        _map["Dasha"] = 3;
        // keep value
        std::cout << _map.insert({"Andrey", 4}).second << " " << _map.insert({"Andrey", 4}).second << std::endl;
        // erasing pair key, value with key
        _map.erase("Dasha");
        PrintMap(_map);
        std::cout << _map.at("Andrey") <<
            //_map.at("Misha") << execption std::out_of_range
            std::endl;
        std::cout << _map.count("Pasha") << std::endl;
        // clear map
        _map.clear();
        std::cout << _map.size() << std::endl;
    }

    // find uniq chars in str with std::set
    std::string str{"sdjkghsjkdghksjdghsjkdhgsjkdjksjnhbeuieubgysj"};
    PrintSet(UniqChars(str));
}
