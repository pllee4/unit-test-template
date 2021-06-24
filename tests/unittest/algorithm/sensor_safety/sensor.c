/*
 * sensor.c
 * Created on: Jun 25, 2021 06:37
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "sensor.h"

#include <string.h>

float *getSensorTestData(float mock_data[]) {
  static float data[NUM_OF_DATA];
  memcpy(data, mock_data, sizeof(data));
  return data;
}

float *getSensorData() {
  // should be returning data the same way as getSensorTestData
}
