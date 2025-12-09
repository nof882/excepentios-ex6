#include "Circle.h"
#include "ShapeException.h"
#include <iostream>

Circle::Circle(std::string nam, std::string col, double rad)
    : Shape(nam, col)
{
    setRad(rad);
}

void Circle::draw()
{
    std::cout << std::endl
              << "Color is " << getColor() << std::endl
              << "Name is " << getName() << std::endl
              << "Radius is " << getRad() << std::endl
              << "Circumference: " << CalCircumference() << std::endl;
}

void Circle::setRad(double rad)
{
    if (rad < 0) {
        throw ShapeException();
    }
    radius = rad;
}

double Circle::getRad()
{
    return radius;
}

double Circle::CalArea()
{
    return 3.14 * radius * radius;
}

double Circle::CalCircumference()
{
    return 2 * 3.14 * radius;
}
