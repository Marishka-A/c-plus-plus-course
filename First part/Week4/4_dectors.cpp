// Деструкторы

class A {
public:
    A() {
        std::cout << "A()\n";
    }
    ~A() { // - деструктор
        std::cout << "~A()\n";
    }
};

int main() {
    A a;      // A()
    return 0; // ~A() - деструктор вызывается, когда объект выходит из области видимости
              //        в которой он был создан
}

// вот ещё пример

class A {
public:
    A() {
        std::cout << "A()\n";
    }
    ~A() {
        std::cout << "~A()\n";
    }
};

class B {
public:
    B() {
        std::cout << "B()\n";
    }
    ~B() {
        std::cout << "~B()\n";
    }
};

int main() {
    A a;      // A()
    {      
        B b;  // B()
    }         // ~B()
    return 0; // ~A()
}

// порядок создания и уничтожения полей класса

class A {
public:
    A() {
        std::cout << "A()\n";
    }
    ~A() {
        std::cout << "~A()\n";
    }
};

class B {
public:
    B() {
        std::cout << "B()\n";
    }
    ~B() {
        std::cout << "~B()\n";
    }
};

class C {
public:
    C() {
        std::cout << "C()\n";
    }
    ~C() {
        std::cout << "~C()\n";
    }
};

class D {
public:
    D() {
        std::cout << "D()\n";
    }
    ~D() {
        std::cout << "~D()\n";
    }
private:
    A a;
    B b;
    C c;
}

int main() {
    {
        D d; // A(), B(), C(), D()
    }        // ~D(), ~C(), ~B(), ~A()
    return 0;
}
