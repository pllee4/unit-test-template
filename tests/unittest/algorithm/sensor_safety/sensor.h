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

#define SENSOR_TASK_TIME 20          // ms
#define SENSOR_STILL_ALIVE_TIME 100  // should be always updating within 100ms
#define NUM_OF_SENSOR_DATA 4         // assume there are 4 data

typedef struct {
  float data[NUM_OF_SENSOR_DATA];
  uint32_t time_stamp;
} Sensor;

bool InitSensor(Sensor *sensor);
void SetSensorData(Sensor *sensor, float sensor_data[]);
void SetSensorTimeStamp(Sensor *sensor, uint32_t time_stamp);
float *GetSensorData(Sensor *sensor);
bool CheckSensorAlive(Sensor *sensor);

#ifdef __cplusplus
}
#endif

#endif /* SENSOR_H */
