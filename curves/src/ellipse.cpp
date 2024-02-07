#include "ellipse.h"

Ellipse::Ellipse(double rx, double ry) : radiusX(rx), radiusY(ry) {
    if (radiusX <= 0 || radiusY <= 0) {
        throw std::invalid_argument("Ellipse radii must be positive");
    }
}

std::vector<double> Ellipse::calculatePoint(double t) const {
    double x = radiusX * cos(t);
    double y = radiusY * sin(t);
    double z = 0;
    return {x, y, z};
}

std::vector<double> Ellipse::calculateDerivative(double t) const {
    double dx = -radiusX * sin(t);
    double dy = radiusY * cos(t);
    double dz = 0;
    return {dx, dy, dz};
}