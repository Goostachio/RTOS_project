#include "Humidifier_task.h"
#include "SensorData.h"
#include "software_timer.h"
#include "Light_control.h"

float humidThreshold = 60;
int humidState = INIT;

int checkHumid (){
    if (humidity < humidThreshold){
        setTimer(5,500);
        return LOW;
    }
    else {
        setTimer(5,1);
        return CHECKING;
    }
}

void humidifierRun(){
    switch (humidState)
    {
    case INIT:
    setupLight(HUMID);
    humidState = checkHumid();
    break;

    case LOW:
    if (isTimerExpired(5) == 1){
        humidState = MID;
        setTimer(5,300);
        }
    lightController(HUMID, GREEN);
    break;

    case MID:
    if (isTimerExpired(5) == 1){
        humidState = HIGH;
        setTimer(5,200);
        }
    lightController(HUMID, YELLOW);
    break;

    case HIGH:
    if (isTimerExpired(5) == 1){
        humidState = checkHumid();
    }
    lightController(HUMID, RED);
    break;

    case CHECKING:
        if (isTimerExpired(5) == 1){
            humidState = checkHumid();
        }
        lightController(HUMID, OFF);
        break;
    }
}
