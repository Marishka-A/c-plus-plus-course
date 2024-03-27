#include <iostream>
#include <vector>

// 1.6 Operators
//  + - * / % << >> | & ^ ~ with Integral types
// < > <= >=, <=> - spaceship(since 20++)
// && || (Lazy)
// += -= *= /= %=
// ++ (prefix), ++(postfix) -- (prefix) --(postfix)

// 1.7 Declarations, definitions, overloading, scopes

// namespace local
namespace local
{
    int localVar = 5;
}

// Create variable at global scope
int globalX = 2;

int main()
{
    // Let's create a scope
    {
        // using all namespace only there
        using namespace local;
        // Declaration
        int elem;
        // Create a var in this scope and rewrite globalX
        int globalX = 5;
        std::cout << "localX " << globalX << std::endl;
        // Definition with value from global scope
        int defElem = ::globalX;
        std::cout << "defElem (globalX) " << defElem << std::endl;
    }

    {
        // We can't call like this
        // std::cout << localVar << std::endl;

        // using for take a 1 var
        using local::localVar;
        std::cout << "localVar " << localVar << std::endl;
    }
}
