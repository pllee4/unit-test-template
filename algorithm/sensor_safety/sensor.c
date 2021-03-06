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
  for (int i = 0; i < NUM_OF_SENSOR_DATA; i++) {
    sensor->data[i] = 0.0;
  }
  sensor->time_stamp = 0;
  sensor->current_time_stamp = 0;
  sensor->first_data = true;
}

void SetSensorData(Sensor *sensor, float sensor_data[]) {
  memcpy(sensor->data, sensor_data, (sizeof(float) * NUM_OF_SENSOR_DATA));
}

void SetSensorTimeStamp(Sensor *sensor, uint32_t time_stamp) {
  sensor->time_stamp = time_stamp;
}

float *GetSensorData(Sensor *sensor) { return sensor->data; }

bool CheckSensorAlive(Sensor *sensor) {
  if (!sensor->first_data) {
    if (sensor->current_time_stamp > SENSOR_STILL_ALIVE_TIME + sensor->time_stamp)
      return false;
  } else {
    if (sensor->time_stamp != 0)  // once got data
      sensor->first_data = false;
    else  // sensor not yet alive
      return false;
  }
  sensor->current_time_stamp += SENSOR_UPDATE_RATE;
  return true;
}