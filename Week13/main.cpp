#include "pizza.h"
#include "factory.h"
#include "kitchen.h"

// cafe
int main()
{
    Kitchen kitchen(Kitchen::PizzaType::NEW_YORK_PIZZA);
    std::shared_ptr<Pizza> cookedPizza = kitchen.CookCheesePizza();
    std::shared_ptr<Pizza> pepperonniPizza = kitchen.CookPepperoniPizza();

    return 0;
}
