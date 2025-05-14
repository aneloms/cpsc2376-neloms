#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return M_PI * radius * radius;
    }
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(4)
                  << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream input("shapes.txt");
    if (!input) {
        std::cerr << "Error: Could not open shapes.txt" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "rectangle") {
            double w, h;
            iss >> w >> h;
            shapes.push_back(std::make_unique<Rectangle>(w, h));
        } else if (type == "circle") {
            double r;
            iss >> r;
            shapes.push_back(std::make_unique<Circle>(r));
        }
    }

    printAllAreas(shapes);

    return 0;
}
