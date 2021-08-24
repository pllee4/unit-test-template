/*
 * VersionEnquiryManagerTest.cpp
 * Created on: Aug 22, 2021 21:45
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "VersionEnquiryManager/VersionEnquiryManager.h"

#include "gtest/gtest.h"

static VersionType test_version_type;
static VersionInfo test_version_info;
static bool enter_version_reply_func = false;

void TestVersionReplyFunc(const VersionType version_type,
                          const VersionInfo version_info) {
  EXPECT_EQ(version_type, test_version_type);
  EXPECT_EQ(version_info.version[0], test_version_info.version[0]);
  EXPECT_EQ(version_info.version[1], test_version_info.version[1]);
  EXPECT_EQ(version_info.version[2], test_version_info.version[2]);
  enter_version_reply_func = true;
}

class VersionEnquiryManagerTest : public ::testing::Test {
 protected:
  VersionEnquiryManagerTest() {}

  void SetUp() override { InitVersionEnquiryManager(TestVersionReplyFunc); }
};

TEST(VersionEnquiryManager, SingletonInitialization) {
  VersionInfo version_info;
  EXPECT_FALSE(SetVersionInfo(BOARD_TYPE, version_info));
  AskReplyFromVersionEnquiryManager(BOARD_TYPE);
  EXPECT_FALSE(enter_version_reply_func);
  EXPECT_TRUE(InitVersionEnquiryManager(TestVersionReplyFunc));
  EXPECT_FALSE(InitVersionEnquiryManager(TestVersionReplyFunc));
}

TEST_F(VersionEnquiryManagerTest, InvalidSetVersionInfo) {
  VersionInfo version_info;
  EXPECT_FALSE(SetVersionInfo((VersionType)6, version_info));
}

TEST_F(VersionEnquiryManagerTest, SetVersionInfo) {
  test_version_type = FIRMWARE_TYPE;
  test_version_info.valueof.major = 1;
  test_version_info.valueof.minor = 2;
  test_version_info.valueof.patch = 3;
  EXPECT_TRUE(SetVersionInfo(test_version_type, test_version_info));

  test_version_type = BOARD_TYPE;
  EXPECT_TRUE(SetVersionInfo(test_version_type, test_version_info));

  test_version_type = ROBOT_TYPE;
  EXPECT_TRUE(SetVersionInfo(test_version_type, test_version_info));
}

TEST_F(VersionEnquiryManagerTest, AskReplyFromVersionEnquiryManager) {
  test_version_type = FIRMWARE_TYPE;
  test_version_info.valueof.major = 1;
  test_version_info.valueof.minor = 2;
  test_version_info.valueof.patch = 3;
  EXPECT_TRUE(SetVersionInfo(test_version_type, test_version_info));
  AskReplyFromVersionEnquiryManager(test_version_type);
  EXPECT_TRUE(enter_version_reply_func);
  enter_version_reply_func = false;

  test_version_type = BOARD_TYPE;
  test_version_info.valueof.major = 4;
  test_version_info.valueof.minor = 5;
  test_version_info.valueof.patch = 6;
  EXPECT_TRUE(SetVersionInfo(test_version_type, test_version_info));
  AskReplyFromVersionEnquiryManager(test_version_type);
  EXPECT_TRUE(enter_version_reply_func);
  enter_version_reply_func = false;

  test_version_type = ROBOT_TYPE;
  test_version_info.valueof.major = 7;
  test_version_info.valueof.minor = 8;
  test_version_info.valueof.patch = 9;
  EXPECT_TRUE(SetVersionInfo(test_version_type, test_version_info));
  AskReplyFromVersionEnquiryManager(test_version_type);
  EXPECT_TRUE(enter_version_reply_func);
  enter_version_reply_func = false;
}