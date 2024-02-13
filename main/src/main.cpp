#include <stdexcept>
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <algorithm>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

void printHelp() {
    std::cout << "Usage: ./curves [max_number_of_curves] [t] ..." << std::endl;
    std::cout << "max_number_of_curves: - number of curves to generate in the container\
        (default: random between 10 and 100)" << std::endl;
    std::cout << "t: - parameter t (default: PI/4)" << std::endl;
}

void parseArgs(int argc, char* argv[], int& maxNumberOfCurves, double& t) {
    if (argc > 1) {
        std::string arg1 = argv[1];
        if (arg1 == "--help" || arg1 == "-h") {
            printHelp();
            exit(0);
        }

        try {
            maxNumberOfCurves = std::stoi(arg1);   
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            exit(1);
        }
    } else {
        maxNumberOfCurves = std::rand() % 91 + 10;
    }

    if (argc > 2) {
        std::string arg2 = argv[2];

        try {
            t = std::stod(arg2);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            exit(1);
        }
    } else {
        t = M_PI / 4;
    }
}

// Print coordinates of points and derivatives for all curves at t=PI/4
void printCurves(const std::vector<std::shared_ptr<Curve>>& curves, double t) {
    for (auto& curve : curves) {
        std::cout << "Curve type: " << typeid(*curve).name() << std::endl;
        std::vector<double> point = curve->calculatePoint(t);
        std::cout << "Point coordinates: (" << point[0] << ", " << point[1] << ", " << point[2] << ")" << std::endl;
        std::vector<double> derivative = curve->calculateDerivative(t);
        std::cout << "Derivative coordinates: (" << derivative[0] << ", " << derivative[1] << ", " << derivative[2] << ")" << std::endl;
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[]) {
    int numberOfCurves;
    double t;
    parseArgs(argc, argv, numberOfCurves, t);

    // Define a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(1.0, 10.0);

    // Populate a container with objects of random types and parameters
    std::vector<std::shared_ptr<Curve>> curves;
    for (int i = 0; i < numberOfCurves; ++i) {
        int type = std::rand() % 3; // 0: Circle, 1: Ellipse, 2: Helix
        if (type == 0) {
            curves.push_back(std::make_shared<Circle>(dis(gen)));
        } else if (type == 1) {
            curves.push_back(std::make_shared<Ellipse>(dis(gen), dis(gen)));
        } else {
            curves.push_back(std::make_shared<Helix>(dis(gen), dis(gen)));
        }
    }

    printCurves(curves, t);

    // Populate a second container that would contain only circles from the first container. Make sure the
    // second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
    std::vector<std::shared_ptr<Circle>> circles;
    for (auto& curve : curves) {
        if (typeid(*curve) == typeid(Circle)) {
            circles.push_back(std::static_pointer_cast<Circle>(curve));
        }
    }

    // Sort the second container in the ascending order of circles’ radii. That is, the first element has the
    // smallest radius, the last - the greatest.
    std::sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {
        return a->getRadius() < b->getRadius();
    });

    // Compute the total sum of radii of all curves in the second container.
    // Implement computation of the total sum of radii using parallel computations (e.g. OpenMP)
    double totalRadius = 0.0;
    #pragma omp parallel for
    for (int i = 0; i < circles.size(); ++i) {
        totalRadius += circles[i]->getRadius();
    }

    // print the result:
    std::cout << "Total sum of radii of all curves in the second container (i.e. sum of all circles): " << totalRadius << std::endl;

    return 0;
}
