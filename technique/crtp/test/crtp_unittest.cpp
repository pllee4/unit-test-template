/* 
 * crtp_unittest.cpp
 * 
 * Created on: Jul 13, 2022 21:08
 * Description: 
 * 
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */ 

#include "crtp/ctrp.hpp"
#include "gtest/gtest.h"

using namespace pllee4;

template <typename T>
void ValidateName(NameableObject<T> const& object, const std::string& name) {
  EXPECT_STREQ(name.c_str(), object.GetName().c_str());
}

TEST(CRTPTest, NameableObject) {
  MapBase map_base;
  ValidateName(map_base, std::string{"MapBase"});
  Map map{"My Map"};
  ValidateName(map, std::string{"My Map"});
}