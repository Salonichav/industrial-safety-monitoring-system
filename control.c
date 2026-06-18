#include "control.h"
#include "sensor.h"
#include <unistd.h>

void* controlTask(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&dataMutex);

        if(systemData.humanDetected && systemData.distance < 50)
            systemData.machineStatus = 0;
        else
            systemData.machineStatus = 1;

        pthread_mutex_unlock(&dataMutex);

        usleep(100000);
    }
    return NULL;
}
