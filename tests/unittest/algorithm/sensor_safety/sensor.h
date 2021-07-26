/*
 * sensor.h
 * Created on: Jun 25, 2021 06:31
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef SENSOR_H
#define SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#define SENSOR_UPDATE_RATE 20        // ms
#define SENSOR_STILL_ALIVE_TIME 100  // should be always updating within 100ms
#define NUM_OF_SENSOR_DATA 4         // assume there are 4 data
#define SENSOR_VALUE_MIN 1.0
#define SENSOR_VALUE_MAX 10.0
#define IS_SENSOR_FAULT(value) \
  (value<SENSOR_VALUE_MIN | value> SENSOR_VALUE_MAX)

typedef struct {
  float data[NUM_OF_SENSOR_DATA];
  uint32_t time_stamp;
  uint32_t current_time_stamp;
  bool first_data;
} Sensor;

bool InitSensor(Sensor *sensor);
void SetSensorData(Sensor *sensor, float sensor_data[]);
void SetSensorTimeStamp(Sensor *sensor, uint32_t time_stamp);
float *GetSensorData(Sensor *sensor);
bool CheckSensorAlive(Sensor *sensor);
bool CheckSensorRangeFault(Sensor *sensor, uint8_t fault_count);

#ifdef __cplusplus
}
#endif

#endif /* SENSOR_H */
