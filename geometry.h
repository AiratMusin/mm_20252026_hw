#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include <stdexcept>
#include <cmath>

// Класс точки
class Point {
private:
	double x, y;
public:
	Point(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
	double getX() const { return x; }
	double getY() const { return y; }
	double distance(const Point& other) const;
};

// Класс многоугольника
class Polygon {
private:
	std::vector<Point> vertices;
public:
	Polygon(const std::vector<Point>& points);
	size_t size() const { return vertices.size(); }
	const Point& getVertex(size_t i) const;
	double minDistance(const Polygon& other) const;
};

#endif // GEOMETRY_H
