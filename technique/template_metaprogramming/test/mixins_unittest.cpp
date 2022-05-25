/*
 * mixins_unittest.cpp
 *
 * Created on: May 25, 2022 23:01
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "mixins/mixins.hpp"

#include "gtest/gtest.h"

using namespace pllee4;

TEST(Mixins, DefaultConstructor) {
  using MyPoint = Point<Label, Color>;
  MyPoint my_point;
  EXPECT_EQ(my_point.x, 0.0);
  EXPECT_EQ(my_point.y, 0.0);
  EXPECT_EQ(my_point.label, "");
  EXPECT_EQ(my_point.red, 0);
  EXPECT_EQ(my_point.green, 0);
  EXPECT_EQ(my_point.blue, 0);
}