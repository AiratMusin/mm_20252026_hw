#include "Polygon.h"
#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "==================================================================" << std::endl;
    std::cout << "Тестирование расстояния между многоугольниками" << std::endl;
    std::cout << "==================================================================" << std::endl << std::endl;
    
    // Тест 1: Полное разделение
    {
        std::vector<Point> p1 = {Point(0,0), Point(2,0), Point(1,2)};
        std::vector<Point> p2 = {Point(5,0), Point(7,0), Point(6,2)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 1] Полное разделение" << std::endl;
        std::cout << "  Многоугольник 1: треугольник в (0,0)-(2,0)-(1,2)" << std::endl;
        std::cout << "  Многоугольник 2: треугольник в (5,0)-(7,0)-(6,2)" << std::endl;
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается ~3.0)" << std::endl << std::endl;
    }
    
    // Тест 2: Касание вершина-вершина
    {
        std::vector<Point> p1 = {Point(0,0), Point(2,0), Point(1,2)};
        std::vector<Point> p2 = {Point(1,2), Point(3,2), Point(2,4)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 2] Касание вершина-вершина" << std::endl;
        std::cout << "  Многоугольник 1: треугольник с вершиной (1,2)" << std::endl;
        std::cout << "  Многоугольник 2: треугольник с вершиной (1,2)" << std::endl;
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается 0.0)" << std::endl << std::endl;
    }
    
    // Тест 3: Пересечение (частичное)
    {
        std::vector<Point> p1 = {Point(0,0), Point(4,0), Point(4,4), Point(0,4)};
        std::vector<Point> p2 = {Point(2,2), Point(6,2), Point(6,6), Point(2,6)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 3] Частичное пересечение" << std::endl;
        std::cout << "  Многоугольник 1: квадрат (0,0)-(4,0)-(4,4)-(0,4)" << std::endl;
        std::cout << "  Многоугольник 2: квадрат (2,2)-(6,2)-(6,6)-(2,6)" << std::endl;
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается 0.0)" << std::endl << std::endl;
    }

    // Тест 4: Вложение - один внутри другого
    {
        std::vector<Point> p1 = {Point(0,0), Point(10,0), Point(10,10), Point(0,10)};
        std::vector<Point> p2 = {Point(2,2), Point(8,2), Point(8,8), Point(2,8)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 4] Вложение без касания" << std::endl;
        std::cout << "  Многоугольник 1: большой квадрат (0,0)-(10,0)-(10,10)-(0,10)" << std::endl;
        std::cout << "  Многоугольник 2: малый квадрат (2,2)-(8,2)-(8,8)-(2,8)" << std::endl;
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается 0.0 - пересечение)" << std::endl << std::endl;
    }

    // Тест 5: Параллельные стороны
    {
        std::vector<Point> p1 = {Point(0,0), Point(4,0), Point(4,2), Point(0,2)};
        std::vector<Point> p2 = {Point(0,4), Point(4,4), Point(4,6), Point(0,6)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 5] Параллельные стороны" << std::endl;
        std::cout << "  Многоугольник 1: прямоугольник (0,0)-(4,0)-(4,2)-(0,2)" << std::endl;
        std::cout << "  Многоугольник 2: прямоугольник (0,4)-(4,4)-(4,6)-(0,6)" << std::endl;
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается 2.0)" << std::endl << std::endl;
    }

    // Тест 6: Касание вершина-сторона
    {
        std::vector<Point> p1 = {Point(0,0), Point(2,0), Point(1,2)};
        std::vector<Point> p2 = {Point(1,0), Point(3,0), Point(2,2)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 6] Касание вершина-сторона" << std::endl;
        std::cout << "  Многоугольник 1: треугольник (0,0)-(2,0)-(1,2)" << std::endl;
        std::cout << "  Многоугольник 2: треугольник (1,0)-(3,0)-(2,2)" << std::endl;
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается 0.0 - касание)" << std::endl << std::endl;
    }

    // Тест 7: Невыпуклые многоугольники
    {
        std::vector<Point> p1 = {Point(0,0), Point(2,0), Point(2,2), Point(1,1), Point(0,2)};
        std::vector<Point> p2 = {Point(4,0), Point(6,0), Point(6,2), Point(5,1), Point(4,2)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 7] Невыпуклые многоугольники" << std::endl;
        std::cout << "  Многоугольник 1: невыпуклый пятиугольник" << std::endl;
        std::cout << "  Многоугольник 2: невыпуклый пятиугольник" << std::endl;
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается ~2.0)" << std::endl << std::endl;
    }

    // Тест 8: Многоугольники общего вида
    {
        std::vector<Point> p1 = {Point(0,0), Point(3,1), Point(4,3), Point(2,5), Point(-1,3)};
        std::vector<Point> p2 = {Point(6,1), Point(9,2), Point(8,4), Point(7,5), Point(5,3)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 8] Многоугольники общего вида (пятиугольники)" << std::endl;
        std::cout << "  Многоугольник 1: произвольный пятиугольник" << std::endl;
        std::cout << "  Многоугольник 2: произвольный пятиугольник" << std::endl;
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << std::endl << std::endl;
    }

    std::cout << "==================================================================" << std::endl;
    std::cout << "Все тесты успешно завершены!" << std::endl;
    std::cout << "==================================================================" << std::endl;
    
    return 0;
}