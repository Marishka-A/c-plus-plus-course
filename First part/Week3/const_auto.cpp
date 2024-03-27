#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <cstdint>

// std::vector - Dynamic array (масссив)
// 1. Нужно хранить список неупорядоченных, неуникальных элементов. 2. Добавлять в конец, удалять из конца в рантайме
// find (O(N)), push_back()/pop_back() O(1) Amortized, size() O(1)
// erase() 1. Удаляем из конца O(1). 2. Удаляем из середины или начала O(N)

// std::set - Множество (красно-черное дерево)
// 1. Нужно хранить уникальные и упорядоченные элементы. 2. Добавлять и удалять элемента.
// find()/count() O(log(N)), insert()/erase() O(log(N)), size() O(1)

// std::map - Словарь (красно-черное), insert()/erase() O(log(N)), size() O(1)
// 1. Нужно хранить уникальные и упорядоченные ключи элементов. 2. Добавлять и удалять элементы по ключу

// std::array - Static array (массив)
// 1. Нужно хранить список неупорядоченных, неуникальных элементов количество которых заранее известно (compile time)
// 2. Скорость доступа к элементам


// Памятка про передачу параметров

// Копируем объект при передаче, когда работаем с Simple types (int, double etc)

// Передаем объекты по ссылке, когда работаем с Compound types (std::string, std::vector etc),
// и хотим изменять искомый объект

// Передаем объект по константной ссылке, когда работаем с Compound types,
// и не хотим изменять искомый объект


// 2.0 const specificator

// Хотим менять в этом скоупе, изменения не отражаются из места вызова
void CopyVec(std::vector<int> vec)
{
    std::cout << &vec << std::endl;
    for (int v : vec)
    {
        std::cout << v << ' ';
    }
}

// Хотим менять в этом скоупе, изменения отражаются в месте вызова
void RefVec(std::vector<int>& vec)
{
    for (int v : vec)
    {
        std::cout << v << ' ';
    }
    vec.push_back(4);
}

// Не хотим менять в этом скоупе, изменения не отражаются в месте вызова
void ConstRefVec(const std::vector<int>& vec)
{
    std::cout << &vec << std::endl;
    for (int v : vec)
    {
        std::cout << v << ' ';
    }
}


// 2.1 Const and reference in for()

void Print()
{
    {
        // Range based for since C++11
        std::vector<char> vec {1, 2, 3};
        for (int v : vec) // v - copy of elem
        {
        }

        for (auto& v : vec) // v - ref to elem
        {
            v = 3; // we will change every elem in vec
            std::cout << v << ' ';
        }
        std::cout << std::endl;
        for (const auto v : vec) // v const copy of elem
        {
            std::cout << (int)v << ' ';
        }

        for (const auto& v : vec) // v const ref to elem
        {
            std::cout << v << ' ';
        }
    }

    {
        std::map<int, std::string> _map {{1, "xcjkghssdg"}, {2, "asfhjahjasfasfhah"}};

        // we can iterate over the map using our keywords
        for (auto& [key, value] : _map)
        {
            // u can change "key", cur it's const
            // key = 5; compile error
            value = "abc";
        }

        for (const auto& [key, value] : _map)
        {
            std::cout << key << " " << value << std::endl;
        }
    }
}

// 2.2 Structures

struct Date
{
    // day, month, year
    unsigned int m_day = 0;
    unsigned int m_month = 0;
    unsigned int m_year = 0;
};

int main()
{
    {
        std::vector<int> _vec {1, 2, 3, 4};
        // print address of vec
        std::cout << &_vec << std::endl;
        // we will work with same address
        ConstRefVec(_vec);
        // we will copy vec
        CopyVec(_vec);
    }

// 2.3 auto
    {
        auto d = 2.0; // int
        auto dl = 2.0l; // unsigned int
        // we also can use auto in for
        Print();
    }
}
