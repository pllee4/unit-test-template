/*
 * variadic_overloading_unittest.cpp
 *
 * Created on: Mar 26, 2022 22:50
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "variadic_overloading/variadic_overloading.hpp"

#include <algorithm>

#include "gtest/gtest.h"

using namespace pllee4;

TEST(VariadicOverloading, Int) {
  SubIndexObj<int> subindex_obj;
  subindex_obj.UpdateSubIndexTable(1, 2, 3, 4, 5, 6);
  std::vector<int> expected = {1, 2, 3, 4, 5, 6};
  EXPECT_TRUE(std::equal(std::begin(expected), std::end(expected),
                         subindex_obj.GetSubIndexTable().begin()));
  subindex_obj.UpdateSubIndexTable(7);
  EXPECT_EQ(subindex_obj[6], 7);
}

TEST(VariadicOverloading, Double) {
  SubIndexObj<double> subindex_obj;
  subindex_obj.UpdateSubIndexTable(12.3, 4.56, 7.89);
  std::vector<double> expected = {12.3, 4.56, 7.89};
  EXPECT_TRUE(std::equal(std::begin(expected), std::end(expected),
                         subindex_obj.GetSubIndexTable().begin()));
  subindex_obj.UpdateSubIndexTable(11.22);
  EXPECT_EQ(subindex_obj[3], 11.22);
}

TEST(VariadicOverloading, String) {
  SubIndexObj<std::string> subindex_obj;
  subindex_obj.UpdateSubIndexTable(std::string{"Foo"});
  subindex_obj.UpdateSubIndexTable(std::string{"Bar"});
  EXPECT_EQ(subindex_obj[0], "Foo");
  EXPECT_EQ(subindex_obj[1], "Bar");
}