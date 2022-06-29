/*
 * person_unittest.cpp
 *
 * Created on: Jun 29, 2022 22:13
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "person/person.hpp"

#include "gtest/gtest.h"

using namespace pllee4;

TEST(ObserverTest, Person) {
  Person p{1};
  auto conn = p.property_changed.connect(
      [](Person &my_person, const std::string &prop_name) {
        EXPECT_STREQ(std::string{"age"}.c_str(), prop_name.c_str());
        EXPECT_EQ(50, my_person.GetAge());
      });

  p.SetAge(50);
  conn.disconnect();
}