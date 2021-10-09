/*
 * RungeKutta.c
 * Created on: Oct 08, 2021 20:09
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "RungeKutta/RungeKutta.h"

float GetRungeKutta4(OdeFunc ode_func, RungeKuttaInitialVal initial_val,
                     uint16_t n, float x) {
  float h;
  float k1;
  float k2;
  float k3;
  float k4;
  float k;

  float yn = initial_val.y;
  float x0 = initial_val.x;

  h = (x - x0) / n;

  for (uint16_t i = 1; i <= n; i++) {
    k1 = h * ode_func(x0, yn);
    k2 = h * ode_func(x0 + h / 2, yn + k1 / 2);
    k3 = h * ode_func(x0 + h / 2, yn + k2 / 2);
    k4 = h * ode_func(x0 + h, yn + k3);
    k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

    yn = yn + k;

    x0 += h;
  }
  return yn;
}