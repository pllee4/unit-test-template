/*
 * motion_damper.h
 * Created on: Jun 19, 2021 20:50
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef MOTION_DAMPER_H
#define MOTION_DAMPER_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_LINEAR_ACCELERATE 0.015
#define MAX_LINEAR_DECELERATE 0.025

typedef struct {
  float x;
  float y;
  float z;
} Vector3;

typedef struct {
  Vector3 linear;
  Vector3 angular;
} MotionCommandMsg;

void MotionDamper(MotionCommandMsg *current_command_msg);

#ifdef __cplusplus
}
#endif

#endif /* MOTION_DAMPER_H */
