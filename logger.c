#include "logger.h"
#include "sensor.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void* loggerTask(void *arg)
{
    while(1)
    {
        FILE *fp = fopen("events.log","a");
        if(fp)
        {
            time_t now = time(NULL);
            fprintf(fp,"[%ld] Distance=%d Human=%d Machine=%s\n",
                    now,
                    systemData.distance,
                    systemData.humanDetected,
                    systemData.machineStatus ? "ON":"OFF");
            fclose(fp);
        }
        sleep(5);
    }
    return NULL;
}
