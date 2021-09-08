/*
 * messaging_unittest.cpp
 * Created on: Jun 16, 2021 22:23
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "messaging.h"

#include "gtest/gtest.h"

TEST(EncodeMessageTest, CheckValue) {
  RobotState robot_state;
  robot_state.battery = 24.5;
  robot_state.num_of_actuators = 4;
  RobotMessage robot_msg, encoded_robot_msg;
  robot_msg.type = RobotStateMsg;
  robot_msg.body.robot_state = robot_state;
  EncodeRobotMessage(robot_msg, &encoded_robot_msg);
  EXPECT_EQ(encoded_robot_msg.body.robot_state.battery,
            robot_msg.body.robot_state.battery);
  EXPECT_EQ(encoded_robot_msg.body.robot_state.num_of_actuators,
            robot_msg.body.robot_state.num_of_actuators);
}