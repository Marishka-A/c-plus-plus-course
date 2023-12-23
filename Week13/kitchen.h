#pragma once

#include "factory.h"

class Kitchen
{
public:
    enum class PizzaType
    {
        NEW_YORK_PIZZA,
        CHICAGO_PIZZA
    };

    Kitchen(PizzaType type) :
        m_pizzaFactory(CreatePizzaFactory(type))
    {
    }

    [[nodiscard]] std::shared_ptr<Pizza> CookCheesePizza() const
    {
        std::shared_ptr<Pizza> pizza = m_pizzaFactory->CreateCheesePizza();
        pizza->Bake();
        pizza->Cut();
        pizza->Box();

        return pizza;
    }

    [[nodiscard]] std::shared_ptr<Pizza> CookPepperoniPizza() const
    {
        std::shared_ptr<Pizza> pizza = m_pizzaFactory->CreatePepperoniPizza();
        pizza->Bake();
        pizza->Cut();
        pizza->Box();

        return pizza;
    }

private:
    std::shared_ptr<PizzaFactory> CreatePizzaFactory(PizzaType type) const
    {
        if (type == PizzaType::NEW_YORK_PIZZA)
        {
            return std::make_shared<NewYorkPizzaFactory>();
        }
        else if (type == PizzaType::CHICAGO_PIZZA)
        {
            return std::make_shared<ChicagoPizzaFactory>();
        }

        return nullptr;
    }

    std::shared_ptr<Pizza> CreateCheesePizza() const
    {
        return m_pizzaFactory->CreateCheesePizza();
    }

    std::shared_ptr<Pizza> CreatePepperoniPizza() const
    {
        return m_pizzaFactory->CreatePepperoniPizza();
    }
private:
    // пицца
    std::shared_ptr<PizzaFactory> m_pizzaFactory;
    // роллы
};
