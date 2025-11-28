#include "Polygon.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype> 

Polygon readPolygonFromUser(int idx) {
    int n;
    std::cout << "Введите количество вершин многоугольника " << idx << ": ";
    std::cin >> n;

    if (n < 3) {
        throw std::runtime_error("Многоугольник должен иметь минимум 3 вершины");
    }

    std::vector<Point> pts;
    pts.reserve(n);
    std::cout << "Введите " << n << " пар координат (x y):\n";
    for (int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        pts.emplace_back(x, y);
    }
    return Polygon(pts);
}

bool askYesNo() {
    while (true) {
        std::cout << "Хотите ли вы написать свой тест? (да/нет): ";
        std::string ans;
        std::getline(std::cin >> std::ws, ans);
        for (auto &c : ans) c = std::tolower(static_cast<unsigned char>(c));
        if (ans.find("да") != std::string::npos || ans.find("y") != std::string::npos || ans.find("yes") != std::string::npos) return true;
        if (ans.find("нет") != std::string::npos || ans.find("n") != std::string::npos || ans.find("no") != std::string::npos) return false;
        std::cout << "Пожалуйста, введите 'да' или 'нет'.\n";
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "==================================================================\n";
    std::cout << "Тестирование расстояния между многоугольниками\n";
    std::cout << "==================================================================\n\n";
    
    // Тест 1: Полное разделение
    {
        std::vector<Point> p1 = {Point(0,0), Point(2,0), Point(1,2)};
        std::vector<Point> p2 = {Point(5,0), Point(7,0), Point(6,2)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 1] Полное разделение\n";
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается ~3.0)\n\n";
    }
    
    // Тест 2: Касание вершина-вершина
    {
        std::vector<Point> p1 = {Point(0,0), Point(2,0), Point(1,2)};
        std::vector<Point> p2 = {Point(1,2), Point(3,2), Point(2,4)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 2] Касание вершина-вершина\n";
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается 0.0)\n\n";
    }
    
    // Тест 3: Пересечение
    {
        std::vector<Point> p1 = {Point(0,0), Point(4,0), Point(4,4), Point(0,4)};
        std::vector<Point> p2 = {Point(2,2), Point(6,2), Point(6,6), Point(2,6)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 3] Частичное пересечение\n";
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается 0.0)\n\n";
    }

    // Тест 4: Вложение
    {
        std::vector<Point> p1 = {Point(0,0), Point(10,0), Point(10,10), Point(0,10)};
        std::vector<Point> p2 = {Point(2,2), Point(8,2), Point(8,8), Point(2,8)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 4] Вложение\n";
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается 0.0)\n\n";
    }

    // Тест 5: Параллельные стороны
    {
        std::vector<Point> p1 = {Point(0,0), Point(4,0), Point(4,2), Point(0,2)};
        std::vector<Point> p2 = {Point(0,4), Point(4,4), Point(4,6), Point(0,6)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 5] Параллельные стороны\n";
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается 2.0)\n\n";
    }

    // Тест 6: Касание вершина-сторона
    {
        std::vector<Point> p1 = {Point(0,0), Point(2,0), Point(1,2)};
        std::vector<Point> p2 = {Point(1,0), Point(3,0), Point(2,2)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 6] Касание вершина-сторона\n";
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается 0.0)\n\n";
    }

    // Тест 7: Невыпуклые многоугольники
    {
        std::vector<Point> p1 = {Point(0,0), Point(2,0), Point(2,2), Point(1,1), Point(0,2)};
        std::vector<Point> p2 = {Point(4,0), Point(6,0), Point(6,2), Point(5,1), Point(4,2)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 7] Невыпуклые многоугольники\n";
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << " (ожидается ~2.0)\n\n";
    }

    // Тест 8: Многоугольники общего вида
    {
        std::vector<Point> p1 = {Point(0,0), Point(3,1), Point(4,3), Point(2,5), Point(-1,3)};
        std::vector<Point> p2 = {Point(6,1), Point(9,2), Point(8,4), Point(7,5), Point(5,3)};
        Polygon poly1(p1), poly2(p2);
        std::cout << "[Тест 8] Многоугольники общего вида\n";
        std::cout << "  Расстояние: " << poly1.Distance(poly2) << "\n\n";
    }

    std::cout << "Автоматические тесты завершены!\n\n";

    // Цикл пользовательских тестов
    while (askYesNo()) {
        try {
            Polygon poly1 = readPolygonFromUser(1);
            Polygon poly2 = readPolygonFromUser(2);
            
            if (!poly1.IsDef() || !poly2.IsDef()) {
                std::cout << "Ошибка: один из многоугольников невалиден!\n\n";
                continue;
            }
            
            double d = poly1.Distance(poly2);
            std::cout << "\nМинимальное расстояние: " << d;
            
            if (d < PolygonUtils::EPSILON) {
                std::cout << " (многоугольники пересекаются или касаются)";
            }
            std::cout << "\n\n";
            
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << "\n\n";
            // Очистка буфера ввода
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    std::cout << "==================================================================\n";
    std::cout << "Программа завершена.\n";
    std::cout << "==================================================================\n";
    
    return 0;
}