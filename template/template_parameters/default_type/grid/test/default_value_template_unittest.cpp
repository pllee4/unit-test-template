/*
 * default_value_template_unittest.cpp
 * Created on: Nov 28, 2021 21:31
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "grid/grid.hpp"
#include "gtest/gtest.h"

using namespace pllee4;

TEST(DefaultValueTemplate, SingleType) {
  Grid<int> myIntGrid;
  myIntGrid.at(5, 5) = 10;
  Grid<int> anotherIntGrid{myIntGrid};
  int y{anotherIntGrid.at(5, 5).value_or(0)};
  EXPECT_EQ(y, 10);
}

TEST(DefaultValueTemplate, SingleParameter) {
  Grid<int, 6> myIntGrid;
  myIntGrid.at(5, 5) = 10;
  Grid<int, 6> anotherIntGrid{myIntGrid};
  int y{anotherIntGrid.at(5, 5).value_or(0)};
  EXPECT_EQ(y, 10);
}

TEST(DefaultValueTemplate, DoubleParameters) {
  Grid<int, 6, 6> myIntGrid;
  myIntGrid.at(5, 5) = 10;
  Grid<int, 6, 6> anotherIntGrid{myIntGrid};
  int y{anotherIntGrid.at(5, 5).value_or(0)};
  EXPECT_EQ(y, 10);
}