#include "helix.h"

Helix::Helix(double r, double s) : radius(r), step(s) {
    if (radius <= 0 || step <= 0) {
        throw std::invalid_argument("Helix radius and step must be positive");
    }
}

std::vector<double> Helix::calculatePoint(double t) const {
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = step * t / (2 * M_PI);
    
    return {x, y, z};
}

std::vector<double> Helix::calculateDerivative(double t) const {
    double dx = -radius * sin(t);
    double dy = radius * cos(t);
    double dz = step / (2 * M_PI);

    return {dx, dy, dz};
}