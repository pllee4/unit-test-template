/*
 * robot1.c
 * Created on: Sep 04, 2021 16:50
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "robot/robot.h"

#include <stdint.h>

#include "robot/details/robot1_spec.h"

int16_t ConvertWheelAngularVelocityToRPM(const float vel) {
  return (int16_t)(vel * 60 / (2 * 3.14)) * ROBOT1_TRANSMISSION_RATE;
}

float ConvertRPMToWheelAngularVelocity(const int16_t rpm) {
  return (float)((float)rpm * (2 * 3.14) / 60.0) / ROBOT1_TRANSMISSION_RATE;
}

CommonActuatorCommand GetCommonActuatorCommand(
    CommonMotionCommand motion_command) {
  CommonActuatorCommand actuator_command;
  if (motion_command.linear.x > ROBOT1_LINEAR_VELOCITY_MAX) {
    motion_command.linear.x = ROBOT1_LINEAR_VELOCITY_MAX;
  } else if (motion_command.linear.x < ROBOT1_LINEAR_VELOCITY_MIN) {
    motion_command.linear.x = ROBOT1_LINEAR_VELOCITY_MIN;
  }
  if (motion_command.angular.z > ROBOT1_ANGULAR_VELOCITY_MAX) {
    motion_command.angular.z = ROBOT1_ANGULAR_VELOCITY_MAX;
  } else if (motion_command.angular.z < ROBOT1_ANGULAR_VELOCITY_MIN) {
    motion_command.angular.z = ROBOT1_ANGULAR_VELOCITY_MIN;
  }

  // convert to angular velocity of wheels (rad/s)
  float vel_left =
      (motion_command.linear.x - motion_command.angular.z * ROBOT1_WHEELBASE) /
      ROBOT1_WHEEL_RADIUS;
  float vel_right =
      (motion_command.linear.x + motion_command.angular.z * ROBOT1_WHEELBASE) /
      ROBOT1_WHEEL_RADIUS;

  // convert to RPM (rounds/minute)
  int16_t vel_left_cmd = ConvertWheelAngularVelocityToRPM(vel_left);
  int16_t vel_right_cmd = ConvertWheelAngularVelocityToRPM(vel_right);

  actuator_command.rotational_motor[0] = vel_right_cmd;
  actuator_command.rotational_motor[1] = -vel_left_cmd;
  actuator_command.rotational_motor[2] = -vel_left_cmd;
  actuator_command.rotational_motor[3] = vel_right_cmd;

  return actuator_command;
}

CommonMotionFeedback GetCommonMotionFeedback(int16_t *rpm) {
  int16_t vel_left_feedback = rpm[0];
  int16_t vel_right_feedback = rpm[1];

  float vel_left = ConvertRPMToWheelAngularVelocity(vel_left_feedback);
  float vel_right = ConvertRPMToWheelAngularVelocity(vel_right_feedback);

  CommonMotionFeedback motion_feedback;

  motion_feedback.linear.x = (vel_left + vel_right) * ROBOT1_WHEEL_RADIUS / 2;
  motion_feedback.linear.y = 0.0;
  motion_feedback.linear.z = 0.0;

  motion_feedback.angular.x = 0.0;
  motion_feedback.angular.y = 0.0;
  motion_feedback.angular.z =
      (vel_right * ROBOT1_WHEEL_RADIUS - motion_feedback.linear.x) /
      ROBOT1_WHEELBASE;

  return motion_feedback;
}
