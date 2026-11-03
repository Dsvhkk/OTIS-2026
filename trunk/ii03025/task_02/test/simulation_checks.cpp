#include <gtest/gtest.h>
#include <cmath>
#include "simulation.h"

TEST(Signal, Step)       { EXPECT_DOUBLE_EQ(generateSignal(1, 5.0, 7), 5.0); }
TEST(Signal, PulseFirst) { EXPECT_DOUBLE_EQ(generateSignal(2, 5.0, 0), 5.0); }
TEST(Signal, PulseLater) { EXPECT_DOUBLE_EQ(generateSignal(2, 5.0, 3), 0.0); }
TEST(Signal, Harmonic)   { EXPECT_NEAR(generateSignal(3, 2.0, 1), 2.0 * std::sin(1.0), 1e-12); }
TEST(Signal, Unknown)    { EXPECT_DOUBLE_EQ(generateSignal(9, 5.0, 0), 0.0); }