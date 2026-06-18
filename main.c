#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#include "sensor.h"
#include "control.h"
#include "logger.h"
#include "dashboard.h"

int main()
{
    pthread_t sensorThread, controlThread, loggerThread, dashboardThread;

    srand(time(NULL));

    pthread_mutex_init(&dataMutex,NULL);

    pthread_create(&sensorThread,NULL,sensorTask,NULL);
    pthread_create(&controlThread,NULL,controlTask,NULL);
    pthread_create(&loggerThread,NULL,loggerTask,NULL);
    pthread_create(&dashboardThread,NULL,dashboardTask,NULL);

    pthread_join(sensorThread,NULL);
    pthread_join(controlThread,NULL);
    pthread_join(loggerThread,NULL);
    pthread_join(dashboardThread,NULL);

    pthread_mutex_destroy(&dataMutex);
    return 0;
}
