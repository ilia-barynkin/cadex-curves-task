#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

class Ellipse : public Curve {
private:
    double radiusX;
    double radiusY;
public:
    Ellipse(double rx, double ry);

    std::vector<double> calculatePoint(double t) const override;

    std::vector<double> calculateDerivative(double t) const override;
};

#endif // ELLIPSE_H