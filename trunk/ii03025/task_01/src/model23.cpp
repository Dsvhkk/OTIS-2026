#include "model23.h"

Model23::Model23(double a, double b, double delta) {
    this->a = a;
    this->b = b;
    this->delta = delta;

    y = 0.0;
}

double Model23::nextStep(double u) {
    double u_new = 0.0;

    if (u > delta) {
        u_new = u - delta;
    }
    else if (u < -delta) {
        u_new = u + delta;
    }

    y = a * y + b * u_new;

    return y;
}

std::string Model23::getName() const {
    return "Model 2.3";
}