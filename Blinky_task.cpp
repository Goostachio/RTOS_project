#include "Blinky_task.h"
#include "software_timer.h"
#include "Light_control.h"

int blink = START;
void blinky(){
  switch (blink) {
    case START:
    setupLight(BOARD);
    setTimer(4,100);
    lightController(BOARD, ON);
    blink = NO_BLINK;
    break;

    case BLINK:
    lightController(BOARD, ON);
    if(isTimerExpired(4) == 1){
      setTimer(4,100);
      blink = NO_BLINK;
    }
    break;

    case NO_BLINK:
    lightController(BOARD, OFF);
    if(isTimerExpired(4) == 1){
      setTimer(4,100);
      blink = BLINK;
    }
    break;
  }
}
