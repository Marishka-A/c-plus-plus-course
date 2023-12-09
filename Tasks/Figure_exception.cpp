#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>

class Figure {
public:
    virtual std::string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Rect : public Figure {
private:
    int width, height;
public:
    Rect(int w, int h) : width(w), height(h) {}
    std::string Name() const override {
        return "RECT";
    }
    double Perimeter() const override {
        return 2 * (width + height);
    }
    double Area() const override {
        return width * height;
    }
};

class Triangle : public Figure {
private:
    int a, b, c;
public:
    Triangle(int sideA, int sideB, int sideC) : a(sideA), b(sideB), c(sideC) {}
    std::string Name() const override {
        return "TRIANGLE";
    }
    double Perimeter() const override {
        return a + b + c;
    }
    double Area() const override {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Circle : public Figure {
private:
    int r;
public:
    Circle(int radius) : r(radius) {}
    std::string Name() const override {
        return "CIRCLE";
    }
    double Perimeter() const override {
        return 2 * 3.14 * r;
    }
    double Area() const override {
        return 3.14 * r * r;
    }
};

std::shared_ptr<Figure> CreateFigure(std::istringstream& is) {
    std::string figureType;
    is >> figureType;

    if (figureType == "RECT") {
        int width, height;
        is >> width >> height;
        return std::make_shared<Rect>(width, height);
    } else if (figureType == "TRIANGLE") {
        int a, b, c;
        is >> a >> b >> c;
        return std::make_shared<Triangle>(a, b, c);
    } else if (figureType == "CIRCLE") {
        int r;
        is >> r;
        return std::make_shared<Circle>(r);
    } else {
        throw std::runtime_error("Wrong figure name");
    }
}

int main() {
    std::vector<std::shared_ptr<Figure>> figures;

    for (std::string line; std::getline(std::cin, line); ) {
        std::istringstream is(line);

        std::string command;
        is >> command;
        if (command == "ADD") {
            is >> std::ws;
            try {
                figures.push_back(CreateFigure(is));
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
            }
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                std::cout << std::fixed << std::setprecision(3)
                          << current_figure->Name() << " "
                          << current_figure->Perimeter() << " "
                          << current_figure->Area() << std::endl;
            }
        }
    }
    return 0;
}