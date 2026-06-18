#include "sensor.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

SystemData systemData;
pthread_mutex_t dataMutex;

void* sensorTask(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&dataMutex);
        systemData.distance = rand() % 100;
        systemData.humanDetected = rand() % 2;
        pthread_mutex_unlock(&dataMutex);

        sleep(1);
    }
    return NULL;
}
