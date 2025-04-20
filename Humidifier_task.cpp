#include "Humidifier_task.h"
#include "SensorData.h"
#include "software_timer.h"
#include "Light_control.h"

float humidThreshold = 75;
int humidState = INIT;

int checkHumid (){
    if (humidity > humidThreshold){
        return GREEN;
    }
    else return CHECKING;
}

void humidifierRun(){
    switch (humidState)
    {
    case INIT:
    setupLight(HUMID);
    humidState = checkHumid();
    setTimer(3,500);
    break;

    case GREEN:
    if (isTimerExpired(3) == 1){
        humidState = YELLOW;
        setTimer(3,300);
        }
    lightController(HUMID, GREEN);
    break;

    case YELLOW:
    if (isTimerExpired(3) == 1){
        humidState = RED;
        setTimer(3,200);
        }
    lightController(HUMID, YELLOW);
    break;

    case RED:
    if (isTimerExpired(3) == 1){
        humidState = checkHumid();
        setTimer(3,500);
    }
    lightController(HUMID, RED);
    break;

    case CHECKING:
        if (isTimerExpired(3) == 1){
            humidState = checkHumid();
            setTimer(3,500);
        }
        break;
    }
}
