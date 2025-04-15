#include <scheduler.h>
#include <software_timer.h>
#include <HT_Sensor.h>
#include <Cooler_task.h>
#include <Heater_task.h>
#include <Humidifier_task.h>
#include <Blinky_task.h>


void TIMER_ISR(void *pvParameters) {
  while (1) {
    SCH_Update();
    vTaskDelay(10);
  }
}

void setup() {
  xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);

  pinMode(D3, OUTPUT);  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);  pinMode(D10, OUTPUT);

  pinMode(48, OUTPUT);

  SCH_Init();
  SCH_Add_Task(timerRun, 0, 1);
  SCH_Add_Task(humidifierRun, 0, 1);
  SCH_Add_Task(coolerRun, 0, 1);

  SCH_Add_Task(heater, 0, 100);
  SCH_Add_Task(blinky, 0, 100);
  SCH_Add_Task(htSensor, 0, 500);
}

void loop() {
  SCH_Dispatch_Tasks();
}
