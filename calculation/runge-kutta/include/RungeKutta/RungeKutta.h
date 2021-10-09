/*
 * RungeKutta.h
 * Created on: Oct 08, 2021 20:08
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef RUNGEKUTTA_H
#define RUNGEKUTTA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
  float x;
  float y;
} RungeKuttaInitialVal;

typedef float (*OdeFunc)(float x, float y);

float GetRungeKutta4(OdeFunc ode_func, RungeKuttaInitialVal initial_val,
                     uint16_t n, float x);

#ifdef __cplusplus
}
#endif

#endif /* RUNGEKUTTA_H */
