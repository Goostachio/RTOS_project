#include "Light_control.h"
#include <Arduino.h>

void setupLight (int LED){
    switch (LED)
    {    
    case HEATER:
        pinMode(D3, OUTPUT);
        pinMode(D4, OUTPUT);
        break;

    case COOLER:
        pinMode(D5, OUTPUT);
        pinMode(D6, OUTPUT);
        break;

    case HUMID:
        pinMode(D7, OUTPUT);
        pinMode(D8, OUTPUT);
        break;
    }
}

void lightController (int LED, int color){
    switch (LED)
    {
    case HEATER:
        switch (color)
        {
        case RED:
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);
          break;
        
        case YELLOW:
        digitalWrite(D3, LOW);
        digitalWrite(D4, HIGH);
          break;

        case GREEN:
        digitalWrite(D3, HIGH);
        digitalWrite(D4, LOW);
          break;

        case OFF:
        digitalWrite(D3, LOW);
        digitalWrite(D4, LOW);
          break;
        }
        break;
    
    case COOLER:
        switch (color)
        {
        case RED:
        digitalWrite(D5, HIGH);
        digitalWrite(D6, HIGH);
          break;
        
        case YELLOW:
        digitalWrite(D5, LOW);
        digitalWrite(D6, HIGH);
          break;

        case GREEN:
        digitalWrite(D5, HIGH);
        digitalWrite(D6, LOW);
          break;

        case OFF:
        digitalWrite(D5, LOW);
        digitalWrite(D6, LOW);
          break;
        }
        break;

    case HUMID:
        switch (color)
        {
        case RED:
        digitalWrite(D7, HIGH);
        digitalWrite(D8, HIGH);
          break;
        
        case YELLOW:
        digitalWrite(D7, LOW);
        digitalWrite(D8, HIGH);
          break;

        case GREEN:
        digitalWrite(D7, HIGH);
        digitalWrite(D8, LOW);
          break;
        
        case OFF:
        digitalWrite(D7, LOW);
        digitalWrite(D8, LOW);
          break;
        }
        break;
    }
}
