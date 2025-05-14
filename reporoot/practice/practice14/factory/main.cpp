#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "ShapeFactory.h"
#include "Shape.h"

int main() {
    std::ifstream inputFile("shapes.txt");
    std::string shapeType;
    double dimension1, dimension2;

    double totalArea = 0.0;
    while (inputFile >> shapeType) {
        if (shapeType == "circle") {
            inputFile >> dimension1;
            std::unique_ptr<Shape> shape = ShapeFactory::createShape(shapeType, dimension1);
            totalArea += shape->area();
        } else if (shapeType == "square") {
            inputFile >> dimension1;
            std::unique_ptr<Shape> shape = ShapeFactory::createShape(shapeType, dimension1);
            totalArea += shape->area();
        } else if (shapeType == "rectangle") {
            inputFile >> dimension1 >> dimension2;
            std::unique_ptr<Shape> shape = ShapeFactory::createShape(shapeType, dimension1, dimension2);
            totalArea += shape->area();
        }
    }

    std::cout << "Total area of shapes: " << totalArea << "\n";
    return 0;
}
