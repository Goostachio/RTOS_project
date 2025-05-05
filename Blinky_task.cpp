#include "Blinky_task.h"
#include "software_timer.h"
#include "Light_control.h"

int blink = START;
void blinky(){
  switch (blink) {
    case START:
    setupLight(BOARD);
    setTimer(1,100);
    blink = BLINK;
    break;

    case BLINK:
    lightController(BOARD, ON);
    if(isTimerExpired(1) == 1){
      setTimer(1,100);
      blink = NO_BLINK;
    }
    break;

    case NO_BLINK:
    lightController(BOARD, OFF);
    if(isTimerExpired(1) == 1){
      setTimer(1,100);
      blink = BLINK;
    }
    break;
  }
}
