#include "point.h"
#include <iostream>

int main() {
    double x1, x2, y1, y2;

    std::cout << "Введите координаты первой точки:" << std::endl;
    std::cout << "X1: " << std::endl;
    std::cin >> x1;
    std::cout << "Y1: ";
    std::cin >> y1;

    std::cout << "Введите координаты второй точки:" << std::endl;
    std::cout << "X2: " << std::endl;
    std::cin >> x2;
    std::cout << "Y2: ";
    std::cin >> y2;

    Point p1(x1, y1);
    Point p2(x2, y2);

    double d = p1.distanceTo(p2);
    std::cout <<  "Расстояние между точками: " << d << std::endl;

    return 0;
};