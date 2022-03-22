/*
 * object_wrapper_unittest.cpp
 *
 * Created on: Mar 22, 2022 21:34
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "type_erasure/object_wrapper.hpp"

#include "gtest/gtest.h"

using namespace pllee4;

auto GetId(const ObjectWrapper& obj) { return obj(); }

struct Object1 {
  static constexpr int id{1};
  int operator()() const { return id; }
};

struct Object2 {
  static constexpr int id{2};
  int operator()() const { return id; }
};

int FunctionPointer() { return 3; }

TEST(ObjectWrapper, Operator) {
  EXPECT_EQ(GetId(ObjectWrapper(Object1())), 1);
  EXPECT_EQ(GetId(ObjectWrapper(Object2())), 2);
  EXPECT_EQ(GetId(ObjectWrapper(FunctionPointer)), 3);
  // "+" implicit convert to function pointer
  EXPECT_EQ(GetId(ObjectWrapper(+[]() { return 4; })), 4);
  EXPECT_EQ(GetId(ObjectWrapper([id = 4]() { return id + 1; })), 5);
}