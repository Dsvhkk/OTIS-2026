#pragma once

#include "model.h"

class Model19 : public Model {
private:
    double a1;
    double a2;
    double a3;
    double b1;

    double y_prev1;
    double y_prev2;

public:
    Model19(double a1, double a2, double a3, double b1);

    double nextStep(double u) override;
    std::string getName() const override;
};