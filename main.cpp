#include "Shape.h"
#include "Circle.h"
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include "ShapeException.h"
#include "InputException.h"
#include <string>
#include <iostream>

void checkNumericInput() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw InputException("Invalid numeric input.");
    }
}

int main()
{
    std::string nam, col;
    double rad = 0, ang = 0, ang2 = 180;
    int height = 0, width = 0;

    Circle circ(col, nam, rad);
    Quadrilateral quad(nam, col, width, height);
    Rectangle rec(nam, col, width, height);
    Parallelogram para(nam, col, width, height, ang, ang2);

    Shape* ptrcirc = &circ;
    Shape* ptrquad = &quad;
    Shape* ptrrec  = &rec;
    Shape* ptrpara = &para;

    std::cout << "Enter information for your objects\n";

    char x = 'y';

    while (x != 'x') {
        std::cout << "c=circle, q=quadrilateral, r=rectangle, p=parallelogram\n";

        std::string shapeInput;
        std::cin >> shapeInput;

        if (shapeInput.length() != 1) {
            std::cout << "Warning – Don’t try to build more than one shape at once\n";
            std::cin.ignore(10000, '\n');
            continue;
        }

        char shapetype = shapeInput[0];

        try {
            switch (shapetype) {

            case 'c':
                std::cin >> col >> nam >> rad;
                checkNumericInput();
                circ.setColor(col);
                circ.setName(nam);
                circ.setRad(rad);
                ptrcirc->draw();
                break;

            case 'q':
                std::cin >> nam >> col >> height >> width;
                checkNumericInput();
                quad.setName(nam);
                quad.setColor(col);
                quad.setHeight(height);
                quad.setWidth(width);
                ptrquad->draw();
                break;

            case 'r':
                std::cin >> nam >> col >> height >> width;
                checkNumericInput();
                rec.setName(nam);
                rec.setColor(col);
                rec.setHeight(height);
                rec.setWidth(width);
                ptrrec->draw();
                break;

            case 'p':
                std::cin >> nam >> col >> height >> width >> ang >> ang2;
                checkNumericInput();
                para.setName(nam);
                para.setColor(col);
                para.setHeight(height);
                para.setWidth(width);
                para.setAngle(ang, ang2);
                ptrpara->draw();
                break;

            default:
                std::cout << "invalid shape type\n";
                break;
            }

            std::cout << "add more? press any key, x to exit\n";
            std::cin >> x;
        }

        catch (InputException& e) {
            std::cout << "INPUT ERROR: " << e.what() << "\n";
            std::cin.ignore(10000, '\n');
            continue;
        }

        catch (ShapeException& e) {
            std::cout << "SHAPE ERROR: " << e.what() << "\n";
        }

        catch (std::exception& e) {
            std::cout << "GENERAL ERROR: " << e.what() << "\n";
        }
    }

    return 0;
}
