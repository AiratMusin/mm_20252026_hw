#include "geometry.h"
#include <iostream>
#include <vector>
#include <cassert>

int main() {
    // Ввод первого многоугольника
    int m;
    std::cout << "Введите число вершин первого многоугольника: ";
    std::cin >> m;
    std::vector<Point> poly1_points;
    std::cout << "Введите " << m << " пар координат (x y) через пробел:\n";
    for (int i = 0; i < m; ++i) {
        double x, y;
        std::cin >> x >> y;
        poly1_points.push_back(Point(x, y));
    }

    // Ввод второго многоугольника
    int n;
    std::cout << "Введите число вершин второго многоугольника: ";
    std::cin >> n;
    std::vector<Point> poly2_points;
    std::cout << "Введите " << n << " пар координат (x y) через пробел:\n";
    for (int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        poly2_points.push_back(Point(x, y));
    }

    try {
        Polygon poly1(poly1_points);
        Polygon poly2(poly2_points);
        double res = poly1.minDistance(poly2);
        std::cout << "Минимальное расстояние между многоугольниками: " << res << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
