/*
 * non-type_template_unittest.cpp
 * Created on: Nov 28, 2021 21:13
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "grid/grid.hpp"
#include "gtest/gtest.h"

using namespace pllee4;

TEST(NonTypeTemplate, CopyConstructor) {
  Grid<int, 10, 10> myIntGrid;
  myIntGrid.at(0, 0) = 10;
  Grid<int, 10, 10> anotherIntGrid{myIntGrid};
  int y{anotherIntGrid.at(0, 0).value_or(0)};
  EXPECT_EQ(y, 10);
}

TEST(NonTypeTemplate, Exception) {
  Grid<double, 10, 10> myDoubleGrid;
  try {
    myDoubleGrid.at(100, 0) = 10.0;
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("x exceeded width!"));
  }
  try {
    myDoubleGrid.at(0, 100) = 10.0;
  } catch (std::out_of_range const& err) {
    EXPECT_EQ(err.what(), std::string("y exceeded height!"));
  }
}

TEST(NonTypeTemplate, ConstType) {
  const size_t height{10};  // DOES NOT COMPILE without const
  Grid<int, 10, height> myGrid;
}