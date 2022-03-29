/*
 * callback_wrapper_unittest.cpp
 *
 * Created on: Mar 26, 2022 11:17
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "callback_wrapper/callback_wrapper.hpp"

#include <iostream>

#include "gtest/gtest.h"

using namespace pllee4;

std::vector<CallbackWrapper> callback_wrappers;

template <typename Callback>
void RegisterCallback(Callback cb) {
  static_assert(function_traits<Callback>::arity == 1,
                "Only one argument is supported");
  callback_wrappers.emplace_back(cb);
}

TEST(CallbackWrapperTest, Type) {
  bool test_state = false;
  int test_value = 0;
  RegisterCallback([&](const bool state) { test_state = state; });
  RegisterCallback([&](const int value) { test_value = value; });
  EXPECT_TRUE(callback_wrappers[0](typeid(bool)));
  EXPECT_FALSE(callback_wrappers[0](typeid(double)));
  EXPECT_TRUE(callback_wrappers[1](typeid(int)));
  
  bool input_state = true;
  std::any msg = input_state;
  callback_wrappers[0](msg);
  EXPECT_TRUE(test_state);

  int input_value = 100;
  msg = input_value;
  callback_wrappers[1](msg);
  EXPECT_EQ(test_value, 100);
}