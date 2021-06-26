/*
 * sensor.c
 * Created on: Jun 25, 2021 06:37
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#include "sensor.h"

#include <string.h>

bool InitSensor(Sensor *sensor) {
  for (int i = 0; i < NUM_OF_SENSOR_DATA; i++)
    sensor->data[i] = 0.0;
}

void SetSensorData(Sensor *sensor, float sensor_data[]) {
  memcpy(sensor->data, sensor_data, (sizeof(float) * NUM_OF_SENSOR_DATA));
}

float *GetSensorData(Sensor *sensor) {
  return sensor->data;
}
