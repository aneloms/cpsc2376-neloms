#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include <memory>
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include <string>

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& shapeType, double dim1, double dim2 = 0) {
        if (shapeType == "circle") {
            return std::make_unique<Circle>(dim1);
        } else if (shapeType == "square") {
            return std::make_unique<Square>(dim1);
        } else if (shapeType == "rectangle") {
            return std::make_unique<Rectangle>(dim1, dim2);
        } else {
            return nullptr;
        }
    }
};

#endif
