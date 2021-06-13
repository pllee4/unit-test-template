/* 
 * messaging.h
 * Created on: Jun 13, 2021 21:58
 * Description: 
 * 
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */ 

#ifndef MESSAGING_H
#define MESSAGING_H

#include "message.h"

#include <stdbool.h>

bool EncodeRobotMessage(RobotMessage msg, RobotMessage *encoded_message);
bool DecodeRobotMessage(RobotMessage msg, RobotMessage *decoded_message);

#endif /* MESSAGING_H */
