#pragma once

#include "model.h"

class Model37 : public Model {
private:
    double a;
    double b;
    double dt;

public:
    Model37(double a, double b, double dt);

    double nextStep(double u) override;

    std::string getName() const override;
};