#include "Cooler_task.h"
#include "software_timer.h"
#include "SensorData.h"
#include <Light_control.h>

int coolerState = INIT;
float coolerThreshold = 40;

int checkCooler (){
    if (temperature > coolerThreshold){
        return COOLING;
    }
    else return NOT_COOLING;
}

void coolerRun(){
    switch (coolerState) {
        case INIT:
        setupLight(COOLER);
        coolerState = checkCooler();
        setTimer(3, 500);
        break;

        case COOLING:
        if (isTimerExpired(3) == 1){
            coolerState = checkCooler();
            setTimer(3, 500);
        }
        lightController(COOLER, GREEN);
        break;

        case NOT_COOLING:
        if (isTimerExpired(3) == 1){
            coolerState = checkCooler();
            setTimer(3,500);
        }
        lightController(COOLER, RED);
        break;
    }
}
