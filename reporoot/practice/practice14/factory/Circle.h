#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <cmath>

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

#endif
