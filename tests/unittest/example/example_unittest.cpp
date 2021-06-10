/* 
 * example_unittest.cpp
 * Created on: Jun 10, 2021 21:19
 * Description: 
 * 
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */ 

 #include "example.hpp"
 #include "gtest/gtest.h"

TEST(ExampleTest, ReturnValue) {
  Example example;
  EXPECT_EQ(true, example.ReturnOnce());
  EXPECT_EQ(false, example.ReturnOnce());
  EXPECT_EQ(false, example.ReturnOnce());
}