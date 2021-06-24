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

#define SENSOR_TASK_TIME 20          // ms
#define SENSOR_STILL_ALIVE_TIME 100  // should be always updating within 100ms
#define NUM_OF_DATA 4              // assume there are 4 data 

float *getSensorTestData(float mock_data[]);

#ifdef __cplusplus
}
#endif

#endif /* SENSOR_H */
