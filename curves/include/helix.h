#ifndef HELIX_H
#define HELIX_H

#include "curve.h"

class Helix : public Curve {
private:
    double radius;
    double step;
public:
    Helix(double r, double s);

    std::vector<double> calculatePoint(double t) const override;

    std::vector<double> calculateDerivative(double t) const override;
};

#endif // HELIX_H