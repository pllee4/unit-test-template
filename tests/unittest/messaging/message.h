/* 
 * message.h
 * Created on: Jun 13, 2021 21:59
 * Description: 
 * 
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */ 

#ifndef MESSAGE_H
#define MESSAGE_H

typedef struct {
  char *firmware_version;
  char *robot_name;
} RobotInfo;

typedef struct {
  float battery;
  int num_of_actuators;
} RobotState;

typedef enum {
  RobotMsgNone = 0x00,
  RobotInfoMsg = 0x01,
  RobotStateMsg = 0x02
} RobotMessageType;

typedef struct {
  RobotMessageType type;
  union {
    RobotInfo robot_info;
    RobotState robot_state;
  } body;
} RobotMessage;

#endif /* MESSAGE_H */
