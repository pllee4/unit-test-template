/*
 * sensor_safety_unittest.cpp
 * Created on: Jun 25, 2021 06:49
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "gtest/gtest.h"

#include "sensor.h"

#define SENSOR_TEST_RUN_TIME 1000

Sensor test_sensor;

TEST(SensorSafety, InitSensor) {
  InitSensor(&test_sensor);
  float *sensor_data = GetSensorData(&test_sensor);
  for (int i = 0; i < NUM_OF_SENSOR_DATA; ++i) {
    EXPECT_FLOAT_EQ(sensor_data[i], 0);
  }
}

TEST(SensorSafety, SetSensorData) {
  InitSensor(&test_sensor);
  float sensor_dataset[] = {1.0, 1.0, 1.0, 1.0};
  SetSensorData(&test_sensor, sensor_dataset);
  float *sensor_data = GetSensorData(&test_sensor);
  for (int i = 0; i < NUM_OF_SENSOR_DATA; ++i) {
    EXPECT_FLOAT_EQ(sensor_data[i], 1.0);
  }
}

// TEST(SensorSafety, SensorAlive) {
//   uint32_t time_count = 0;
//   // ensure sensor alive time and update time is less than total run time
//   EXPECT_LE(SENSOR_STILL_ALIVE_TIME + SENSOR_UPDATE_RATE, SENSOR_TEST_RUN_TIME);
//   InitSensor(&test_sensor);
//   while (time_count <= SENSOR_TEST_RUN_TIME) {
//     time_count += SENSOR_UPDATE_RATE;
//     // set sensor timestamp should be called in placed where there is sensor
//     // data comes in in application code
//     SetSensorTimeStamp(&test_sensor, time_count);
//     EXPECT_TRUE(CheckSensorAlive(&test_sensor));
//   }
// }

TEST(SensorSafety, SensorDataLost) {
  uint32_t time_count = 0;
  // ensure sensor alive time and update time is less than total run time
  EXPECT_LE(SENSOR_STILL_ALIVE_TIME + SENSOR_UPDATE_RATE, SENSOR_TEST_RUN_TIME);
  InitSensor(&test_sensor);
  while (time_count <= SENSOR_TEST_RUN_TIME) {
    time_count += SENSOR_UPDATE_RATE;
    static uint32_t loop_count = 0;
    // set sensor timestamp should be called in placed where there is sensor
    // data comes in in application code
    if (loop_count < 2) {
      SetSensorTimeStamp(&test_sensor, time_count);
      EXPECT_TRUE(CheckSensorAlive(&test_sensor));
    } else if (loop_count > 7) {
      EXPECT_FALSE(CheckSensorAlive(&test_sensor));
      break;
    } else {
      EXPECT_TRUE(CheckSensorAlive(&test_sensor));
    }
    loop_count++;
  }
}