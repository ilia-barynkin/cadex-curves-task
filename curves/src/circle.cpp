#include "circle.h"

Circle::Circle(double r) : radius(r) {
    if (radius <= 0) {
        throw std::invalid_argument("Circle radius must be positive");
    }
}

std::vector<double> Circle::calculatePoint(double t) const {
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = 0;
    return {x, y, z};
}

std::vector<double> Circle::calculateDerivative(double t) const {
    double dx = -radius * sin(t);
    double dy = radius * cos(t);
    double dz = 0;
    return {dx, dy, dz};
}

double Circle::getRadius() const { return radius; }