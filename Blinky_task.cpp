#include "Blinky_task.h"
#include "software_timer.h"
#include <Arduino.h>

int status = 0;
void blinky(){
  status = 1 - status;
  digitalWrite(LED_PIN, status);
}
