/*
 * html_unittest.cpp
 *
 * Created on: Jun 22, 2022 22:26
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "html/html.hpp"

#include "gtest/gtest.h"

using namespace pllee4;

TEST(BuilderTest, HTML) {
  HtmlBuilder builder{"test"};
  builder.add_child("name1", "text1").add_child("name2", "text2");
  std::string expected_str{"test\n->name1 text1\n->name2 text2"};
  EXPECT_STREQ(expected_str.c_str(), builder.str().c_str());
}
