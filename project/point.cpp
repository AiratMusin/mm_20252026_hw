#include "point.h"
#include <cmath>

Point::Point(double x_val, double y_val) {
    x = x_val;
    y = y_val;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::distanceTo(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    double distance = sqrt(dx * dx + dy * dy);
    return distance;
}