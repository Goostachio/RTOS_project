#include "Heater_task.h"
#include "software_timer.h"
#include "SensorData.h"
#include "Light_control.h"

int heaterState = INIT;
float safe = 20;
float slightly_risky = 30;
float risky = 40;

int checkTemp (){
    if (temperature > risky || temperature < safe) return RISKY;
    else if (temperature > slightly_risky) return SLIGHTLY_RISKY;
    else return NOT_RISKY;
}

void heater(){
    switch (heaterState) {
        case INIT:
        setupLight(HEATER);
        heaterState = checkTemp();
        setTimer(4,500);
        lightController(HEATER, OFF);
        break;

        case NOT_RISKY:
        if (isTimerExpired(4) == 1){
            heaterState = checkTemp();
            setTimer(4,500);
        }
        lightController(HEATER, GREEN);
        break;

        case SLIGHTLY_RISKY:
        if (isTimerExpired(4) == 1){
            heaterState = checkTemp();
            setTimer(4,500);
        }
        lightController(HEATER, YELLOW);
        break;

        case RISKY:
        if (isTimerExpired(4) == 1){
            heaterState = checkTemp();
            setTimer(4,500);
        }
        lightController(HEATER, RED);
        break;
    }
}
