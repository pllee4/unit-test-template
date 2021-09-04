/* 
 * robot_interface.h
 * Created on: Sep 04, 2021 15:46
 * Description: 
 * 
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */ 

#ifndef ROBOT_INTERFACE_H
#define ROBOT_INTERFACE_H

#include <stdint.h>

typedef struct {
  int8_t rotation_motor_0;
  int8_t rotation_motor_1;
  int8_t rotation_motor_2;
  int8_t rotation_motor_3;
  int8_t servo_motor_0;
  int8_t servo_motor_1;
  int8_t servo_motor_2;
  int8_t servo_motor_3;
} RobotActuatorCommand;

typedef struct {
  float x;
  float y;
  float z;
} RobotMotionVector;

typedef struct {
  RobotMotionVector linear;
  RobotMotionVector angular;
} RobotMotionCommand;

typedef RobotMotionCommand RobotMotionFeedback;

RobotActuatorCommand GetRobotActuatorCommand(RobotMotionCommand motion_command);
RobotMotionFeedback GetRobotMotionFeedback(int16_t *rpm);

#endif /* ROBOT_INTERFACE_H */
