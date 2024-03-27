#pragma once
#include "pizza.h"

#include <memory>

// Abstract Factory Interface
class PizzaFactory
{
public:
    virtual ~PizzaFactory() = default;

    virtual std::shared_ptr<Pizza> CreateCheesePizza() = 0;
    virtual std::shared_ptr<Pizza> CreatePepperoniPizza() = 0;
};

// Concrete New York Pizza Factory
class NewYorkPizzaFactory : public PizzaFactory
{
public:
    std::shared_ptr<Pizza> CreateCheesePizza() final
    {
        return std::make_shared<NewYorkCheesePizza>(NewYorkCheesePizza());
    }

    std::shared_ptr<Pizza> CreatePepperoniPizza() final
    {
        return std::make_shared<NewYorkPepperoniPizza>(NewYorkPepperoniPizza());
    }
};

// Concrete Chicago Pizza Factory
class ChicagoPizzaFactory : public PizzaFactory
{
public:
    std::shared_ptr<Pizza> CreateCheesePizza() final
    {
        return std::make_shared<ChicagoCheesePizza>(ChicagoCheesePizza());
    }

    std::shared_ptr<Pizza> CreatePepperoniPizza() final
    {
        return std::make_shared<ChicagoPepperoniPizza>(ChicagoPepperoniPizza());
    }
};
