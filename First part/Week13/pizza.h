#pragma once
#include <iostream>
#include <memory>

// Abstract Product Interface
class Pizza
{
public:
    virtual ~Pizza() = default;

    virtual void Bake() const = 0;
    virtual void Cut() const = 0;
    virtual void Box() const = 0;
};

// Concrete New York Cheese Pizza
class NewYorkCheesePizza : public Pizza
{
public:
    void Bake() const final
    {
        std::cout << "Baking New York-style cheese pizza."
                << std::endl;
    }

    void Cut() const final
    {
        std::cout << "Cutting New York-style cheese pizza."
                << std::endl;
    }

    void Box() const final
    {
        std::cout << "Boxing New York-style cheese pizza."
                << std::endl;
    }
};

// Concrete New York Pepperoni Pizza
class NewYorkPepperoniPizza : public Pizza
{
public:
    void Bake() const final
    {
        std::cout
            << "Baking New York-style pepperoni pizza."
            << std::endl;
    }

    void Cut() const final
    {
        std::cout
            << "Cutting New York-style pepperoni pizza."
            << std::endl;
    }

    void Box() const final
    {
        std::cout
            << "Boxing New York-style pepperoni pizza."
            << std::endl;
    }
};

// Concrete Chicago Cheese Pizza
class ChicagoCheesePizza : public Pizza
{
public:
    void Bake() const final
    {
        std::cout << "Baking Chicago-style cheese pizza."
                << std::endl;
    }

    void Cut() const final
    {
        std::cout << "Cutting Chicago-style cheese pizza."
                << std::endl;
    }

    void Box() const final
    {
        std::cout << "Boxing Chicago-style cheese pizza."
                << std::endl;
    }
};

// Concrete Chicago Pepperoni Pizza
class ChicagoPepperoniPizza : public Pizza
{
public:
    void Bake() const final
    {
        std::cout << "Baking Chicago-style pepperoni pizza."
                << std::endl;
    }

    void Cut() const final
    {
        std::cout
            << "Cutting Chicago-style pepperoni pizza."
            << std::endl;
    }

    void Box() const final
    {
        std::cout << "Boxing Chicago-style pepperoni pizza."
                << std::endl;
    }
};
