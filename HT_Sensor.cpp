#include "HT_Sensor.h"
#include <Arduino.h>
#include <Wire.h>
#include <DHT20.h>
#include "software_timer.h"
#include "SensorData.h"


DHT20 dht20;
int stateSensor = INIT;

void htSensor_read() {
  switch (stateSensor) {
    case INIT:
      Wire.begin(GPIO_NUM_11, GPIO_NUM_12);
      dht20.begin();
      setTimer(0, 500); 
      stateSensor = READING;
      break;

    case READING:
      dht20.read();
        float readTemperature = dht20.getTemperature();
        float readHumidity = dht20.getHumidity();

      if (isnan(readTemperature) || isnan(readHumidity)) {
          Serial.println("Failed to read from DHT sensor!");
          return;
      }else {
          temperature = readTemperature;
          humidity = readHumidity;
          Serial.print("collected Temp: "); Serial.print(temperature); Serial.print(" *C ");
          Serial.print(" collected Humidity: "); Serial.print(humidity); Serial.println(" %");
      }
      if (isTimerExpired(0) == 1) {
        setTimer(0, 500);
      }
      break;
  }
}
