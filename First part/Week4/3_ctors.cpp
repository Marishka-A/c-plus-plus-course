// Конструкторы
class C {
    C() {}    // constructor - специальный метод, который описывает, как должен создаваться объект
    C(int) {} // может быть прегружен и иметь любые аргументы
};

// ------------

class Student {
public:
    // BAD - инициализация полей в теле конструктора. Сперва поля инициализируются по умолчанию
    // а потом полученными аргументами -- двойная работа
    Student(std::string _name, int _course) {
        name = _name;
        course = _course;
    }
    // GOOD - инициализация полей через список инициализации. Присваивается сразу нужное значение
    Student(std::string _name, int _course): name(_name), course(_course) {}
    Student(std::string _name) name(_name): {} // перегрузка конструктора
private:
    std::string name;
    int course = 1;
};

// порядок инициализации
class Student {
public:
    // даже если в списке мы инициализируем сперва course, а потом имя,
    // порядок инициализации будет таким, в каком порядке поля написаны в классе
    Student(std::string _name, int _course): course(_course), name(_name) {} // !
private:
    std::string name; // будет инициализировано первым
    int course = 1;   // будет инициализировано вторым
};

// const поле
class Student {
public:
    Student(std::string _name, int _course, int _id) {
        name = _name;
        course = _course;
        id = _id; // CE - нельзя изменять const поле, так как оно инициализируется до входа в тело
                  // конструктора. 
        // !Присвоить какое-то значение const полю можно только в списке 
        // инициализации
    }
private:
    std::string name;
    int course = 1;
    const int id;
};

// ------------

// default and delete
// 1
class Student {
public:
    Student(std::string _name, int _course) : course(_course), name(_name) {
        std::cout << "my constructor\n";
    }
private:
    std::string name;
    int course = 1;
};
Student st("Ilya", 4); // OK
// но!
Student st; // CE - конструктор по умолчанию не генерируется, если есть пользовательский

// 2
class Student {
public:
    Student() = default; // просим компилятор сгенерировать конструктор по умолчанию
    Student(std::string _name, int _course) : course(_course), name(_name) {}
private:
    std::string name;
    int course = 1;
};
Student st; // OK
Student st("Ilya", 4); // OK

// 3
class Student {
public:
    Student() = default;
    Student(std::string _name, int _course) : course(_course), name(_name) {}
    Student(const char* str) = delete; // запрещаем создавать класс от const char*
private:
    std::string name;
    int course = 1;
};
Student st; // OK
Student st("Ilya", 4); // OK
Student st("Ilya"); // CE

// ------------
// Explicit
// 1
class C {
    C(int) {} // конструктор от int
};

void foo(C c) {
    //...
}

int main() {
    foo(5); // OK - неявно вызывается конструктор C(5) и вызывается foo(С с)
}


// 2
class C {
    explicit C(int) {} // explicit - запрет на неявный вызов конструктора
};

void foo(C c) {
    //...
}

int main() {
    foo(5); // CE, потому что C(int) помечен explicit
}
