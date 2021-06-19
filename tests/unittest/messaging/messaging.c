/*
 * messaging.c
 * Created on: Jun 13, 2021 21:58
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "messaging.h"

bool EncodeRobotMessage(RobotMessage msg, RobotMessage *encoded_message) {
  switch (msg.type) {
    case RobotInfoMsg:
      encoded_message->type = msg.type;
      encoded_message->body.robot_info = msg.body.robot_info;
      break;
    case RobotStateMsg:
      encoded_message->type = msg.type;
      encoded_message->body.robot_state = msg.body.robot_state;
      break;
    default:
      return false;
      break;
  }
  return true;
}

bool DecodeRobotMessage(RobotMessage msg, RobotMessage *decoded_message) {}
