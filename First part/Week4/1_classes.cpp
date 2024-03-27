// Классы и структуры
// int, double, char, и др. - встроенные типы
// Тип - множество значений и операций над ними. Класс - пользовательский тип

class Student { // класс
}; // ";" !

int main() {
    Student st; // st - объект класса
}

// ------------------------

struct Student {
    std::string name; // поле класса
    int course = 0; // поле класса со значением по умолчанию

    void PrintName { // метод класса
        std::cout << name << '\n'; // в методе класса можно использовать поля класса
    }
};

// Объявление и определение методов

struct Student { // определение класса
    std::string name;
    int course = 0;

    void PrintName(); // объявление метода PrintName
    void PrintCourse() { // объявление и определение метода PrintName
        std::cout << "Course: " << course << '\n';
    }
};

void Student::PrintName { // определение метода PrintName вне тела класса
    std::cout << name << '\n';
} 

// Видимость членов классов
// в обычных функциях нужно сперва объявить, прежде чем использовать

int foo() {
    print_hello(); // CE: print_hello() was not declarated
    return 0;
}

void print_hello() {
    std::cout << "Hello world!" << '\n';
}

// в классах все поля и методы можно использовать до их объявления

struct Student {
    void PrintName() {
        std::cout << name << '\n'; // OK, хоть и name объявлено вот здесь |
    }                              //                                     |
    std::string name; // <-------------------------------------------------
};
