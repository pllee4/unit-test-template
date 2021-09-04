/*
 * common.h
 * Created on: Sep 04, 2021 16:59
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

typedef struct {
  int16_t rotational_motor[4];
  int16_t servo_motor[4];
} CommonActuatorCommand;

typedef struct {
  float x;
  float y;
  float z;
} CommonMotionVector;

typedef struct {
  CommonMotionVector linear;
  CommonMotionVector angular;
} CommonMotionCommand;

typedef CommonMotionCommand CommonMotionFeedback;

CommonActuatorCommand GetCommonActuatorCommand(
    CommonMotionCommand motion_command);
CommonMotionFeedback GetCommonMotionFeedback(int16_t *rpm);
#endif /* COMMON_H */
