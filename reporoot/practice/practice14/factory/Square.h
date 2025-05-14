#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

#endif
