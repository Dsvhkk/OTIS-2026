#include "model37.h"
#include <cmath>

Model37::Model37(double A, double B, double DT) {
    a = A;
    b = B;
    dt = DT;

    y = 0.0;
}

double Model37::nextStep(double u) {
    y = y + dt * (-std::exp(a) * y + b * u);

    return y;
}

std::string Model37::getName() const {
    return "Model 3.7";
}