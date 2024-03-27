// Спецификаторы доступа
// public and private
struct S {
private:
    int a;
    void foo() {
    }
public:
    double d;
    void bar() {
    }
};

S s;
s.a;     // CE
s.foo(); // CE
s.d;     // OK
s.bar(); // OK


// отличие классов и структур

struct Student {
    int course = 1; // public
};
Student st;
st.course = 2; // OK

class Student {
    int course = 1; // private
};
Student st;
st.course = 2; // CE

// Практический пример. Мы не хотим, чтобы кто-то из вне менял size

class IntVector {
public:
    void PushBack(int x) {
        // ...
        ++size;
    }
private:
    int size = 0;
};

// Принцип сначала разрешение перегрузки, а потом проверка доступа

class C {
private:
    void foo(int a) {
        std::cout << "foo(int)" << '\n';
    }
public:
    void foo(double d) {
        std::cout << "foo(double)" << '\n';
    }
};

C c;
c.foo(1); // CE, так как будет попытка вызвать foo(int), который объявлен приватным
