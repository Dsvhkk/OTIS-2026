#pragma once

#include "model.h"

class Model23 : public Model {
private:
    double a;
    double b;
    double delta;

public:
    Model23(double a, double b, double delta);

    double nextStep(double u) override;

    std::string getName() const override;
};