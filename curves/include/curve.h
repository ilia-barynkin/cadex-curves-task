#ifndef CURVE_H
#define CURVE_H

#include <cmath>
#include <vector>
#include <stdexcept>

class Curve {
public:
    virtual std::vector<double> calculatePoint(double t) const = 0;
    
    virtual std::vector<double> calculateDerivative(double t) const = 0;
    
    virtual ~Curve();
};

#endif // CURVE_H