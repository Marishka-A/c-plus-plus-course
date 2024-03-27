#include <iostream>
#include <cstring>
#include <algorithm>

class Foo
{
public:
    Foo() = default;
    Foo(const int i, double d) :
        m_i(i),
        m_d(d)
    {
    }

private:
    const int m_i = 0;
    double m_d;
};

class String
{
public:
    String() = default;
    String(const size_t size, const char symbol) :
        m_data(new char[size]()),
        m_size(size)
    {
        std::memset(m_data, symbol, m_size);
        //for (size_t i = 0; i < m_size; ++i)
        //{
        //    std::cout << m_data[i];
        //}
        //std::cout << " " << m_size << std::endl;
    }

    String(const String& str) :
        m_data(new char[str.m_size]),
        m_size(str.m_size)
    {
        std::memcpy(m_data, str.m_data, m_size);
        for (size_t i = 0; i < m_size; ++i)
        {
            std::cout << m_data[i];
        }
        std::cout << " " << m_size << std::endl;
    }
/*
    String& operator=(const String& other)
    {
        delete[] m_data;
        m_data = new char[other.m_size];
        m_size = other.m_size;
        std::memcpy(m_data, other.m_data, m_size);
        //for (size_t i = 0; i < m_size; ++i)
        //{
        //    std::cout << m_data[i];
        //}
        //std::cout << " " << m_size << std::endl;

        return *this;
    }
*/
    String& operator=(const String& other)
    {
        String copy(other);
        swap(copy);

        return *this;
    }

    ~String()
    {
        delete[] m_data;
    }
private:
    void swap(String& other)
    {
        std::swap(m_data, other.m_data);
        std::swap(m_size, other.m_size);
    }
private:
    char* m_data = nullptr;
    size_t m_size = 0;
};

int main()
{
    // Foo
    {
        Foo fooDef;
        Foo foo(2, 3.0);
        Foo copyFoo(foo); // Copy Constructor
        // foo = copyFoo; // Copy Asssignment operator
    }
    // String
    {
        String str;
        String strFill(3, 'a');
        String strCopy(strFill); // Copy Constructor
        String strCopyTwo = strFill; // Copy Constructor
        str = strFill;
    }
}
