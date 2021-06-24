/*
 * sensor_safety_unittest.cpp
 * Created on: Jun 25, 2021 06:49
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "sensor.h"

#include "gtest/gtest.h"

#define SENSOR_TEST_RUN_TIME 1000

TEST(SensorSafety, GetData) {
  float mock_data[] = {1.0, 1.0, 1.0, 1.0};
  float *real_data;
  real_data = getSensorTestData(mock_data);
  for (int i = 0; i < NUM_OF_DATA; ++i) {
    EXPECT_FLOAT_EQ(real_data[i], mock_data[i]);
  }
}

TEST(SensorSafety, SensorFault) {
  uint16_t time_count = 0;
  // check SENSOR_STILL_ALIVE_TIME + SENSOR_TASK_TIME must be <  SENSOR_TEST_RUN_TIME
  while (time_count <= SENSOR_TEST_RUN_TIME) {
    time_count += SENSOR_TASK_TIME;
    // sensor data fault
  }
  time_count += SENSOR_TASK_TIME;
}