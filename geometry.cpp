#include "geometry.h"

// расстояние между двумя точками
double Point::distance(const Point& other) const {
	double dx = x - other.x;
	double dy = y - other.y;
	return std::sqrt(dx*dx + dy * dy);
}

Polygon::Polygon(const std::vector<Point>& points) : vertices(points) {
	if (vertices.size() < 3) throw std::invalid_argument("Polygon must have at least 3 vertices.");
}

const Point& Polygon::getVertex(size_t i) const {
	if (i >= vertices.size()) throw std::out_of_range("Vertex index out of range.");
	return vertices[i];
}

// вспомогательная функция: расстояние от точки до отрезка [A,B]
static double distanceToSegment(const Point& P, const Point& A, const Point& B) {
	double px = B.getX() - A.getX();
	double py = B.getY() - A.getY();
	double norm = px * px + py * py;
	double u = ((P.getX() - A.getX())*px + (P.getY() - A.getY())*py) / norm;
	u = std::min(std::max(u, 0.0), 1.0);
	Point closest(A.getX() + u * px, A.getY() + u * py);
	return P.distance(closest);
}

// минимальное расстояние между двумя многоугольниками
double Polygon::minDistance(const Polygon& other) const {
	double minDist = 1e20;
	for (size_t i = 0; i < vertices.size(); ++i) {
		Point P = vertices[i];
		for (size_t j = 0; j < other.size(); ++j) {
			Point A = other.getVertex(j);
			Point B = other.getVertex((j + 1) % other.size());
			double d = distanceToSegment(P, A, B);
			if (d < minDist) minDist = d;
		}
	}
	// Теперь наоборот
	for (size_t i = 0; i < other.size(); ++i) {
		Point P = other.getVertex(i);
		for (size_t j = 0; j < vertices.size(); ++j) {
			Point A = vertices[j];
			Point B = vertices[(j + 1) % vertices.size()];
			double d = distanceToSegment(P, A, B);
			if (d < minDist) minDist = d;
		}
	}
	return minDist;
}
