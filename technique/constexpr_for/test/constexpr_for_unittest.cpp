/*
 * constexpr_for_unittest.cpp
 *
 * Created on: Mar 27, 2022 18:41
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "constexpr_for/constexpr_for.hpp"

#include "gtest/gtest.h"

TEST(ConstexprFor, Tuple) {
  int index = 0;
  constexpr_for_tuple(
      [&index](auto const &v) {
        if (index == 0) {
          EXPECT_EQ(v, 1);
        } else if (index == 1) {
          EXPECT_EQ(v, 2.0);
        } else if (index == 2) {
          EXPECT_TRUE(v);
        }
        index++;
      },
      std::make_tuple(1, 2.0, true));
}