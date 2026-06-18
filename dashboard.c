#include "dashboard.h"
#include "sensor.h"
#include <stdio.h>
#include <unistd.h>

void* dashboardTask(void *arg)
{
    while(1)
    {
        printf("\033[2J\033[H");

        printf("===============================================\n");
        printf("     INDUSTRIAL SAFETY MONITOR v1.0\n");
        printf("===============================================\n\n");

        printf("Distance Sensor : %d cm\n", systemData.distance);
        printf("IR Sensor       : %s\n",
               systemData.humanDetected ? "DETECTED" : "NOT DETECTED");
        printf("Danger Zone     : %s\n",
               (systemData.humanDetected && systemData.distance < 50) ? "ACTIVE":"NO");
        printf("Machine Status  : %s\n\n",
               systemData.machineStatus ? "ON":"OFF");

        printf("Threads Running : Sensor | Control | Logger | Dashboard\n");
        printf("\nPress Ctrl+C to Exit\n");

        fflush(stdout);
        sleep(1);
    }
    return NULL;
}
