#ifndef SENSOR_H
#define SENSOR_H
#include <pthread.h>

typedef struct {
    int distance;
    int humanDetected;
    int machineStatus;
} SystemData;

extern SystemData systemData;
extern pthread_mutex_t dataMutex;

void* sensorTask(void *arg);

#endif
