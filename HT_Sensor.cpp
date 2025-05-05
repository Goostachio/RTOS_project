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
      Serial.begin(115200);
      Wire.begin(GPIO_NUM_11, GPIO_NUM_12);
      dht20.begin();
      setTimer(2, 500); 
      stateSensor = READING;
      break;

    case READING:
      if (isTimerExpired(2) == 1) {
        setTimer(2, 500);
        dht20.read();
        float readTemperature = dht20.getTemperature();
        float readHumidity = dht20.getHumidity();

        if (isnan(readTemperature) || isnan(readHumidity)) {
            Serial.println("Failed to read from DHT sensor!");
            return;
        }else {
            temperature = readTemperature;
            humidity = readHumidity;
            Serial.print("Humidity: ");
            Serial.print(humidity);
            Serial.print("%  Temperature: ");
            Serial.print(temperature);
            Serial.println("°C");
        }
      }
      break;
  }
}
