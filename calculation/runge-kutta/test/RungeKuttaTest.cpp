/*
 * RungeKuttaTest.cpp
 * Created on: Oct 08, 2021 20:06
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "RungeKutta/RungeKutta.h"

#include "gtest/gtest.h"

float Ode1(float x, float y) { return ((x - y) / 2); }
float Ode2(float x, float y) { return ((y * y - x * x) / (y * y + x * x)); }

TEST(RungeKutta, RungeKutta4) {
  EXPECT_FLOAT_EQ(GetRungeKutta4(Ode1, {0, 1}, 10, 2.0), 1.103639);
  EXPECT_FLOAT_EQ(GetRungeKutta4(Ode2, {0, 1}, 10, 0.4), 1.375279);
}