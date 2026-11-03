#include "simulation.h"
#include <cmath>

double generateSignal(int signalChoice, double amplitude, int tau) {
    if (signalChoice == 1) return amplitude;
    if (signalChoice == 2 && tau == 0) return amplitude;
    if (signalChoice == 3) return amplitude * std::sin(tau);
    return 0.0;
}