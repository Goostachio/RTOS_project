#ifndef LIGHT_CONTROLLER_H_
#define LIGHT_CONTROLLER_H_

#define HUMID 0
#define HEATER 1
#define COOLER 2
#define BOARD 3
#define SENSOR 4

#define RED 0
#define YELLOW 1
#define GREEN 2

#define ON 3
#define OFF 4

void setupLight (int LED);
void lightController (int LED, int color);

#endif LIGHT_CONTROLLER_H_
