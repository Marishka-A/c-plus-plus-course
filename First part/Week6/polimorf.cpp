#include <string>
#include <iostream>
#include <memory>
#include <vector>
/*
    Реализуем класс Animal с виртуальным методом Voice()
*/
class Animal
{
public:
    Animal() = default;
    Animal(const std::string& name) :
        m_name(name)
    {
        //std::cout << "Animal" << std::endl;
    }

    virtual void Voice() const
    {
        std::cout << "No sound" << std::endl;
    }

    ~Animal()
    {
        //std::cout << "~Animal" << std::endl;
    }
private:
    const std::string m_name;
};

class Bird : public Animal
{
public:
    Bird() = default;
    Bird(const std::string& name, const bool isFly) :
        Animal(name),
        m_isFly(isFly)
    {
        //std::cout << "Bird" << std::endl;
    }

    // C++ 11: override, final
    virtual void Voice() const override final
    {
        std::cout << "Chirik" << std::endl;
    }

    ~Bird()
    {
        //std::cout << "~Bird" << std::endl;
    }
private:
    const bool m_isFly = true;
};

class Dog : public Animal
{
public:
    Dog() = default;
    virtual void Voice() const override final
    {
        std::cout << "Whoof" << std::endl;
    }
};

class Zoo
{
public:
    Zoo() = default;

    void InsertBird(const Bird& animal)
    {
        m_animals.push_back(std::make_shared<Bird>(animal));
    }

    void InsertDog(const Dog& animal)
    {
        m_animals.push_back(std::make_shared<Dog>(animal));
    }

    void PrintAnimals() const
    {
        for (const auto& animal : m_animals)
        {
            animal->Voice();
        }
    }
private:
    std::vector<std::shared_ptr<Animal>> m_animals;
};

class A
{
public:
    A()
    {
        std::cout << "A" << std::endl;
    }

    virtual void foo()
    {
    }

    ~A()
    {
        std::cout << "~A" << std::endl;
    }
};

class B : public A
{
public:
    B()
    {
        std::cout << "B" << std::endl;
    }

    virtual void foo() override
    {
    }

    ~B()
    {
        std::cout << "~B" << std::endl;
    }
};

int main()
{
    {
        std::shared_ptr<A> a = std::make_shared<B>();
        // ref_counter = 1
    }
    Zoo zoo;
    zoo.InsertDog(Dog());
    zoo.InsertBird(Bird());
    zoo.PrintAnimals();
}
