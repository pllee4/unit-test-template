/*
 * arctangent_unittest.cpp
 * Created on: Sep 26, 2021 16:40
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include <math.h>

#include "gtest/gtest.h"

TEST(Arctangent, Arctan) {
  EXPECT_NEAR(0.0, atan(0), 1.0e-6);
  EXPECT_NEAR(0.4636476, atan(0.5), 1.0e-6);
  EXPECT_NEAR(-0.4636476, atan(-0.5), 1.0e-6);
}

TEST(Arctangent, Arctanf) {
  EXPECT_NEAR(0.0, atanf(0), 1.0e-6);
  EXPECT_NEAR(0.4636476, atanf(0.5), 1.0e-6);
  EXPECT_NEAR(-0.4636476, atanf(-0.5), 1.0e-6);
}

TEST(Arctangent, Arctan2) {
  EXPECT_NEAR(0.0, atan2(0, 0), 1.0e-6);
  EXPECT_NEAR(0.4636476, atan2(0.5, 1), 1.0e-6);
  EXPECT_NEAR(-0.4636476, atan2(-0.5, 1), 1.0e-6);
  EXPECT_NEAR(2.677945, atan2(0.5, -1), 1.0e-6);
}
