/*
 * motion_damper_unittest.cpp
 * Created on: Jun 19, 2021 21:09
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "motion_damper.h"

#include "gtest/gtest.h"

TEST(MotionDamper, Decelerate) {
  MotionCommandMsg motion_command_msg;
  float input[] = {1.5, 1.5, 1.0, 0.0};
  float output[] = {MAX_LINEAR_ACCELERATE, MAX_LINEAR_ACCELERATE * 2.0,
                    MAX_LINEAR_ACCELERATE * 3.0,
                    MAX_LINEAR_ACCELERATE * 3.0 - MAX_LINEAR_DECELERATE};
  for (int i = 0; i < 4; ++i) {
    motion_command_msg.linear.x = input[i];
    MotionDamper(&motion_command_msg);
    EXPECT_FLOAT_EQ(motion_command_msg.linear.x, output[i]);
        // << "Test failed: expected " << output[i] << " but got "
        // << motion_command_msg.linear.x;
  }
}

TEST(MotionDamper, AccelerateThenStop) {
  MotionCommandMsg motion_command_msg;
  float input[] = {0.0, 1.5, 1.0, 0.0};
  float output[] = {0, MAX_LINEAR_ACCELERATE,
                    MAX_LINEAR_ACCELERATE * 2.0,
                    MAX_LINEAR_ACCELERATE * 2.0 - MAX_LINEAR_DECELERATE};
  for (int i = 0; i < 4; ++i) {
    motion_command_msg.linear.x = input[i];
    MotionDamper(&motion_command_msg);
    EXPECT_FLOAT_EQ(motion_command_msg.linear.x, output[i]);
        // << "Test failed: expected " << output[i] << " but got "
        // << motion_command_msg.linear.x;
  }
}

TEST(MotionDamper, AccelerateInverse) {
  MotionCommandMsg motion_command_msg;
  float input[] = {0.0, -1.0, -1.5, 0.0};
  float output[] = {0, -MAX_LINEAR_ACCELERATE,
                    -MAX_LINEAR_ACCELERATE * 2.0,
                    -MAX_LINEAR_ACCELERATE * 2.0 + MAX_LINEAR_DECELERATE};
  for (int i = 0; i < 4; ++i) {
    motion_command_msg.linear.x = input[i];
    MotionDamper(&motion_command_msg);
    EXPECT_FLOAT_EQ(motion_command_msg.linear.x, output[i]);
        // << "Test failed: expected " << output[i] << " but got "
        // << motion_command_msg.linear.x;
  }
}