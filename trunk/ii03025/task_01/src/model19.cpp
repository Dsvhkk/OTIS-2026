#include "model19.h"

Model19::Model19(double a1, double a2, double a3, double b1) {
    this->a1 = a1;
    this->a2 = a2;
    this->a3 = a3;
    this->b1 = b1;

    y = 0.0;
    y_prev1 = 0.0;
    y_prev2 = 0.0;
}

double Model19::nextStep(double u) {
    double y_next = a1 * y
                  + a2 * y_prev1
                  + a3 * y_prev2
                  + b1 * u;

    y_prev2 = y_prev1;
    y_prev1 = y;
    y = y_next;

    return y;
}

std::string Model19::getName() const {
    return "Model 1.9";
}