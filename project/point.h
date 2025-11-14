#ifndef POINT_H
#define POINT_H

#include <cmath>

class Point {
    private:
        double x, y;
    
    public:
        Point(double x_val = 0.0, double y_val = 0.0);
        double getX() const;
        double getY() const;
        double distanceTo(const Point& other) const;
};

#endif