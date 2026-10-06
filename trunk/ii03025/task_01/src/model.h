#pragma once

#include <string>

class Model {
protected:
    double y;

public:
    Model() {
        y = 0.0;
    }

    virtual double nextStep(double u) = 0;

    virtual std::string getName() const = 0;

    virtual ~Model() {
    }
};