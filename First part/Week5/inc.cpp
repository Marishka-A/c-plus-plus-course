#include <string>
#include <iostream>

/*
    Пример проблемы ромбовидного наследования:
      A
     / \
    B   C
     \ /
      D
    https://habr.com/ru/articles/445948/
*/

class A
{
public:
    A()
    {
        std::cout << "A" << std::endl;
    }
    ~A()
    {
        std::cout << "~A" << std::endl;
    }
};

// проблема ромбовидного наследования решается с помощью добавления virtual
class B : virtual public A
{
public:
    B()
    {
        std::cout << "B" << std::endl;
    }
    ~B()
    {
        std::cout << "~B" << std::endl;
    }
};

// проблема ромбовидного наследования решается с помощью добавления virtual
class C : virtual public A
{
public:
    C()
    {
        std::cout << "C" << std::endl;
    }
    ~C()
    {
        std::cout << "~C" << std::endl;
    }
};

class D : public C, public B
{
public:
    D()
    {
        std::cout << "D" << std::endl;
    }
    ~D()
    {
        std::cout << "~D" << std::endl;
    }
};

/*
    Реализуем класс Animal с виртуальным методом Voice()
*/
class Animal
{
public:
    Animal() = default;
    Animal(const bool isAlive, const std::string& name) :
        m_isAlive(isAlive),
        m_name(name)
    {
        std::cout << "Animal" << std::endl;
    }

    virtual void Voice() const
    {
        std::cout << "No sound" << std::endl;
    }

    ~Animal()
    {
        std::cout << "~Animal" << std::endl;
    }
private:
    bool m_isAlive;
    const std::string m_name;
};

class Bird : public Animal
{
public:
    Bird() = default;
    Bird(const bool isAlive, const std::string& name, const bool isFly) :
        Animal(isAlive, name),
        m_isFly(isFly)
    {
        std::cout << "Bird" << std::endl;
    }

    // C++ 11    // C++ 11: override, final
    virtual void Voice() const override final
    {
        std::cout << "Chirik" << std::endl;
    }

    ~Bird()
    {
        std::cout << "~Bird" << std::endl;
    }
private:
    const bool m_isFly = true;
};

int main()
{
    {
        Animal animal(true, "Sharik");
        Bird bird(true, "Sharik", true);
        // Animal() Bird() ~Bird() ~Animal()
    }
    // Diamond problem
    {
        // A() B() C() D() ~D() ~C() ~B() ~A()
        // A() B() A() C() D() ~D() ~C() ~A() ~B() ~A()
        D d;
    }
    // virtual method
    {
        Animal animal;
        animal.Voice();
        Bird bird;
        bird.Voice();
    }
}
