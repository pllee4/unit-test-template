/*
 * motion_damper.c
 * Created on: Jun 19, 2021 20:51
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "motion_damper.h"

void MotionDamper(MotionCommandMsg *current_command_msg) {
  static MotionCommandMsg prev_command_msg;

  float linear_change =
      current_command_msg->linear.x - prev_command_msg.linear.x;

  if (linear_change < -MAX_LINEAR_DECELERATE) {
    // forward
    if (prev_command_msg.linear.x > 0)  // only for deceleration
      current_command_msg->linear.x =
          prev_command_msg.linear.x - MAX_LINEAR_DECELERATE;
  } else if (linear_change > MAX_LINEAR_DECELERATE) {
    // backward
    if (prev_command_msg.linear.x < 0)  // only for deceleration
      current_command_msg->linear.x =
          prev_command_msg.linear.x + MAX_LINEAR_DECELERATE;
  }

  if (linear_change < -MAX_LINEAR_ACCELERATE) {
    // backward
    if (prev_command_msg.linear.x <= 0)  // only for acceleration
      current_command_msg->linear.x =
          prev_command_msg.linear.x - MAX_LINEAR_ACCELERATE;
  } else if (linear_change > MAX_LINEAR_ACCELERATE) {
    // forward
    if (prev_command_msg.linear.x >= 0)  // only for acceleration
      current_command_msg->linear.x =
          prev_command_msg.linear.x + MAX_LINEAR_ACCELERATE;
  }

  prev_command_msg = *current_command_msg;
}
