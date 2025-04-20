#include "Heater_task.h"
#include "software_timer.h"
#include "SensorData.h"
#include "Light_control.h"

int heaterState = CHECKING;
float safe = 31;
float slightly_risky = 32;
float risky = 33;

int checkTemp (){
    if (temperature > risky || temperature < safe) return RISKY;
    else if (temperature > slightly_risky) return SLIGHTLY_RISKY;
    else return NOT_RISKY;


}

void heater(){
    switch (heaterState) {
        case CHECKING:
        setupLight(HEATER);
        heaterState = checkTemp();
        setTimer(1,100);
        break;

        case NOT_RISKY:
        if (isTimerExpired(1) == 1){
            heaterState = checkTemp();
            setTimer(1,100);
        }
        lightController(HEATER, GREEN);
        break;

        case SLIGHTLY_RISKY:
        if (isTimerExpired(1) == 1){
            heaterState = checkTemp();
            setTimer(1,100);
        }
        lightController(HEATER, YELLOW);
        break;

        case RISKY:
        if (isTimerExpired(1) == 1){
            heaterState = checkTemp();
            setTimer(1,100);
        }
        lightController(HEATER, RED);
        break;
    }
}
