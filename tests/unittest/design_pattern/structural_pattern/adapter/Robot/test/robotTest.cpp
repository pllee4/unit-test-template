/*
 * robotTest.cpp
 * Created on: Sep 07, 2021 20:46
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "robot_interface/robot_interface.h"

#include "gtest/gtest.h"

TEST(RobotInterface, RobotMotionFeedbackCheck) {
  // move front
  int16_t rpm[] = {100, 100};
  RobotMotionFeedback robot_motion_feedback;
  robot_motion_feedback = GetRobotMotionFeedback(rpm);
  EXPECT_NEAR(0.057567, robot_motion_feedback.linear.x, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.linear.y, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.linear.z, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.angular.x, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.angular.y, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.angular.z, 1.0e-6);

  // move backwards
  rpm[0] = -100;
  rpm[1] = -100;
  robot_motion_feedback = GetRobotMotionFeedback(rpm);
  EXPECT_NEAR(-0.057567, robot_motion_feedback.linear.x, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.linear.y, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.linear.z, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.angular.x, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.angular.y, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.angular.z, 1.0e-6);

  // rotates clockwise
  rpm[0] = 100;
  rpm[1] = -100;
  robot_motion_feedback = GetRobotMotionFeedback(rpm);
  EXPECT_NEAR(0.00, robot_motion_feedback.linear.x, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.linear.y, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.linear.z, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.angular.x, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.angular.y, 1.0e-6);
  EXPECT_NEAR(-0.115596, robot_motion_feedback.angular.z, 1.0e-6);

  // rotates counter clockwise
  rpm[0] = -100;
  rpm[1] = 100;
  robot_motion_feedback = GetRobotMotionFeedback(rpm);
  EXPECT_NEAR(0.00, robot_motion_feedback.linear.x, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.linear.y, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.linear.z, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.angular.x, 1.0e-6);
  EXPECT_NEAR(0.00, robot_motion_feedback.angular.y, 1.0e-6);
  EXPECT_NEAR(0.115596, robot_motion_feedback.angular.z, 1.0e-6);
}

TEST(RobotInterface, RobotActuatorCommandCheck) {
  RobotMotionCommand robot_motion_command;
  robot_motion_command.linear.x = 0.1;
  robot_motion_command.linear.y = 0.0;
  robot_motion_command.linear.z = 0.0;
  robot_motion_command.angular.x = 0.0;
  robot_motion_command.angular.y = 0.0;
  robot_motion_command.angular.z = 0.0;

  RobotActuatorCommand robot_actuator_command;
  robot_actuator_command = GetRobotActuatorCommand(robot_motion_command);
  EXPECT_EQ(173, robot_actuator_command.rotation_motor_0);
  EXPECT_EQ(-173, robot_actuator_command.rotation_motor_1);
  EXPECT_EQ(-173, robot_actuator_command.rotation_motor_2);
  EXPECT_EQ(173, robot_actuator_command.rotation_motor_3);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_0);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_1);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_2);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_3);

  robot_motion_command.linear.x = -0.1;
  robot_motion_command.linear.y = 0.0;
  robot_motion_command.linear.z = 0.0;
  robot_motion_command.angular.x = 0.0;
  robot_motion_command.angular.y = 0.0;
  robot_motion_command.angular.z = 0.0;

  robot_actuator_command = GetRobotActuatorCommand(robot_motion_command);
  EXPECT_EQ(-173, robot_actuator_command.rotation_motor_0);
  EXPECT_EQ(173, robot_actuator_command.rotation_motor_1);
  EXPECT_EQ(173, robot_actuator_command.rotation_motor_2);
  EXPECT_EQ(-173, robot_actuator_command.rotation_motor_3);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_0);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_1);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_2);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_3);

  robot_motion_command.linear.x = 0.0;
  robot_motion_command.linear.y = 0.0;
  robot_motion_command.linear.z = 0.0;
  robot_motion_command.angular.x = 0.0;
  robot_motion_command.angular.y = 0.0;
  robot_motion_command.angular.z = 0.1;

  robot_actuator_command = GetRobotActuatorCommand(robot_motion_command);
  EXPECT_EQ(86, robot_actuator_command.rotation_motor_0);
  EXPECT_EQ(86, robot_actuator_command.rotation_motor_1);
  EXPECT_EQ(86, robot_actuator_command.rotation_motor_2);
  EXPECT_EQ(86, robot_actuator_command.rotation_motor_3);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_0);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_1);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_2);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_3);

  robot_motion_command.linear.x = 0.0;
  robot_motion_command.linear.y = 0.0;
  robot_motion_command.linear.z = 0.0;
  robot_motion_command.angular.x = 0.0;
  robot_motion_command.angular.y = 0.0;
  robot_motion_command.angular.z = -0.1;

  robot_actuator_command = GetRobotActuatorCommand(robot_motion_command);
  EXPECT_EQ(-86, robot_actuator_command.rotation_motor_0);
  EXPECT_EQ(-86, robot_actuator_command.rotation_motor_1);
  EXPECT_EQ(-86, robot_actuator_command.rotation_motor_2);
  EXPECT_EQ(-86, robot_actuator_command.rotation_motor_3);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_0);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_1);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_2);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_3);

  robot_motion_command.linear.x = 0.5;
  robot_motion_command.linear.y = 0.0;
  robot_motion_command.linear.z = 0.0;
  robot_motion_command.angular.x = 0.0;
  robot_motion_command.angular.y = 0.0;
  robot_motion_command.angular.z = -0.1;

  robot_actuator_command = GetRobotActuatorCommand(robot_motion_command);
  EXPECT_EQ(782, robot_actuator_command.rotation_motor_0);
  EXPECT_EQ(-955, robot_actuator_command.rotation_motor_1);
  EXPECT_EQ(-955, robot_actuator_command.rotation_motor_2);
  EXPECT_EQ(782, robot_actuator_command.rotation_motor_3);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_0);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_1);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_2);
  EXPECT_EQ(0, robot_actuator_command.servo_motor_3);
}