/*
 * union_unittest.cpp
 * Created on: Aug 21, 2021 09:37
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "gtest/gtest.h"

#include "union/union.h"

TEST(Union, Structure) {
  UnionInput union_input;

  for (uint8_t test_input = 0xFF; test_input >= 0; test_input--) {
    union_input.valueof.bit0 = (bool)(test_input & BIT_MASK(0));
    union_input.valueof.bit1 = (bool)(test_input & BIT_MASK(1));
    union_input.valueof.bit2 = (bool)(test_input & BIT_MASK(2));
    union_input.valueof.bit3 = (bool)(test_input & BIT_MASK(3));
    union_input.valueof.bit4 = (bool)(test_input & BIT_MASK(4));
    union_input.valueof.bit5 = (bool)(test_input & BIT_MASK(5));
    union_input.valueof.bit6 = (bool)(test_input & BIT_MASK(6));
    union_input.valueof.bit7 = (bool)(test_input & BIT_MASK(7));

    EXPECT_EQ(union_input.input, test_input);
    if (test_input == 0)  // to prevent dead loop
      break;
  }

  for (uint8_t test_input = 0xFF; test_input >= 0; test_input--) {
    union_input.input = test_input;
    EXPECT_EQ(union_input.valueof.bit0, (bool)(test_input & BIT_MASK(0)));
    EXPECT_EQ(union_input.valueof.bit1, (bool)(test_input & BIT_MASK(1)));
    EXPECT_EQ(union_input.valueof.bit2, (bool)(test_input & BIT_MASK(2)));
    EXPECT_EQ(union_input.valueof.bit3, (bool)(test_input & BIT_MASK(3)));
    EXPECT_EQ(union_input.valueof.bit4, (bool)(test_input & BIT_MASK(4)));
    EXPECT_EQ(union_input.valueof.bit5, (bool)(test_input & BIT_MASK(5)));
    EXPECT_EQ(union_input.valueof.bit6, (bool)(test_input & BIT_MASK(6)));
    EXPECT_EQ(union_input.valueof.bit7, (bool)(test_input & BIT_MASK(7)));
    if (test_input == 0)  // to prevent dead loop
      break;
  }
}