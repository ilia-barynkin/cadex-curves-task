#ifndef CIRCLE_H
#define CIRCLE_H

#include "curve.h"

class Circle : public Curve {
private:
    double radius;
public:
    Circle(double r);
    
    std::vector<double> calculatePoint(double t) const override;
    
    std::vector<double> calculateDerivative(double t) const override;
    
    double getRadius() const;
};

#endif //CIRCLE_H