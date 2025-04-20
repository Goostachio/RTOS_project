#ifndef LIGHT_CONTROLLER_H_
#define LIGHT_CONTROLLER_H_

#define HUMID 1
#define HEATER 2
#define COOLER 3

#define RED 1
#define YELLOW 2
#define GREEN 3

void setupLight (int LED);
void lightController (int LED, int color);

#endif LIGHT_CONTROLLER_H_
