#pragma once
#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "Car.h"
class Display:public Car {
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
public:
	Display();
	Display(string, string, int, int, int, int, int, int);
	~Display();
	int getLightLevel();
	int getScreenLightLevel();
	int getTaploLightLevel();
};

#endif //DISPLAY_H_