#include <scheduler.h>
#include <software_timer.h>
#include <Cooler_task.h>
#include <Heater_task.h>
#include <Humidifier_task.h>
#include <Blinky_task.h>
#include <HT_Sensor.h>

void TIMER_ISR(void *pvParameters) {
  while (1) {
    SCH_Update();
    vTaskDelay(10);
  }
}

void setup() {
  xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);

  SCH_Init();

  SCH_Add_Task(heater, 0, 1);
  SCH_Add_Task(coolerRun, 0, 1);
  SCH_Add_Task(humidifierRun, 0, 1);
  SCH_Add_Task(timerRun, 0, 1);

  SCH_Add_Task(blinky, 0, 100);
  SCH_Add_Task(htSensor_read, 0, 500);
}

void loop() {
  SCH_Dispatch_Tasks();
}
