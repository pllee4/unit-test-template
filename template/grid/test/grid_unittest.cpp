/*
 * grid_unittest.cpp
 * Created on: Nov 27, 2021 22:57
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "grid/grid.hpp"

#include "gtest/gtest.h"

using namespace pllee4;

TEST(Grid, CopyConstructor) {
  Grid<int> myIntGrid;
  myIntGrid.at(0, 0) = 10;
  Grid<int> anotherIntGrid{myIntGrid};
  int y{anotherIntGrid.at(0, 0).value_or(0)};
  EXPECT_EQ(y, 10);
}