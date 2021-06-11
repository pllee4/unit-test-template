/* 
 * example_unittest.cpp
 * Created on: Jun 10, 2021 21:19
 * Description: 
 * 
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */ 

 #include "example.hpp"
 #include "gtest/gtest.h"

TEST(ReturnLocalVariableTest, HandleStaticLocalVariable) {
  Example example;
  EXPECT_TRUE(example.ReturnStaticLocalVariable());
  EXPECT_FALSE(example.ReturnStaticLocalVariable());
  EXPECT_FALSE(example.ReturnStaticLocalVariable());
  Example another_example;
  EXPECT_FALSE(another_example.ReturnStaticLocalVariable());
  EXPECT_FALSE(example.ReturnStaticLocalVariable());
}

TEST(ReturnPrivateMemberTest, HandlePrivateMember) {
  Example example;
  EXPECT_TRUE(example.ReturnPrivateMember());
  EXPECT_FALSE(example.ReturnPrivateMember());
  EXPECT_FALSE(example.ReturnPrivateMember());
  Example another_example;
  EXPECT_TRUE(another_example.ReturnPrivateMember());
  EXPECT_FALSE(example.ReturnPrivateMember());
}