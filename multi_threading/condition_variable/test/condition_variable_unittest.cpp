/*
 * condition_variable_unittest.cpp
 *
 * Created on: Jun 04, 2022 14:44
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "condition_variable/condition_variable.hpp"

#include <unistd.h>
#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace pllee4;

TEST(ConditionVariableTest, Int) {
  int test_value = 5;
  Messaging<int> messaging;
  messaging.Run();
  EXPECT_NE(messaging.GetValue(), test_value);
  messaging.PutMessage(test_value);
  usleep(100000);
  EXPECT_EQ(messaging.GetValue(), test_value);
}

TEST(ConditionVariableTest, Float) {
  float test_value = 0.1234;
  Messaging<float> messaging;
  messaging.Run();
  EXPECT_NE(messaging.GetValue(), test_value);
  messaging.PutMessage(test_value);
  usleep(100000);
  EXPECT_FLOAT_EQ(messaging.GetValue(), test_value);
}

TEST(ConditionVariableTest, String) {
  std::string test_value = "test_value";
  Messaging<std::string> messaging;
  messaging.Run();
  EXPECT_NE(messaging.GetValue(), test_value);
  messaging.PutMessage(test_value);
  usleep(100000);
  EXPECT_EQ(messaging.GetValue(), test_value);
}