/*
 * robot_interface.c
 * Created on: Sep 04, 2021 15:47
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "robot_interface/robot_interface.h"

#include "robot/robot.h"

RobotActuatorCommand GetRobotActuatorCommand(
    RobotMotionCommand motion_command) {
  // internal
  CommonActuatorCommand common_actuator_command;
  CommonMotionCommand common_motion_command;

  common_motion_command.linear.x = motion_command.linear.x;
  common_motion_command.linear.y = motion_command.linear.y;
  common_motion_command.linear.z = motion_command.linear.z;

  common_motion_command.angular.x = motion_command.angular.x;
  common_motion_command.angular.y = motion_command.angular.y;
  common_motion_command.angular.z = motion_command.angular.z;

  common_actuator_command = GetCommonActuatorCommand(common_motion_command);

  // public
  RobotActuatorCommand robot_actuator_command;
  robot_actuator_command.rotation_motor_0 =
      common_actuator_command.rotational_motor[0];
  robot_actuator_command.rotation_motor_1 =
      common_actuator_command.rotational_motor[1];
  robot_actuator_command.rotation_motor_2 =
      common_actuator_command.rotational_motor[2];
  robot_actuator_command.rotation_motor_3 =
      common_actuator_command.rotational_motor[3];
  robot_actuator_command.servo_motor_0 = common_actuator_command.servo_motor[0];
  robot_actuator_command.servo_motor_1 = common_actuator_command.servo_motor[1];
  robot_actuator_command.servo_motor_2 = common_actuator_command.servo_motor[2];
  robot_actuator_command.servo_motor_3 = common_actuator_command.servo_motor[3];

  return robot_actuator_command;
}

RobotMotionFeedback GetRobotMotionFeedback(int16_t *rpm) {
  // internal
  CommonMotionFeedback common_motion_feedback;
  common_motion_feedback = GetCommonMotionFeedback(rpm);

  // public
  RobotMotionFeedback robot_motion_feedback;
  robot_motion_feedback.linear.x = common_motion_feedback.linear.x;
  robot_motion_feedback.linear.y = common_motion_feedback.linear.y;
  robot_motion_feedback.linear.z = common_motion_feedback.linear.z;
  robot_motion_feedback.angular.x = common_motion_feedback.angular.x;
  robot_motion_feedback.angular.y = common_motion_feedback.angular.y;
  robot_motion_feedback.angular.z = common_motion_feedback.angular.z;

  return robot_motion_feedback;
}