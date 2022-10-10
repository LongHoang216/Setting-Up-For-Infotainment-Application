#pragma once
#ifndef SOUND_H_
#define SOUND_H_
#include <iostream>
#include <string>
#include "Car.h"
using namespace std;
class Sound : public Car{
private:
	int media_volume_level;
	int call_volume_level;
	int navigation_volume_level;
	int notification_volume_level;
public:
	Sound();
	Sound(string, string, int, int, int, int, int, int, int);
	~Sound();
	int getMediaVolume();
	int getCallVolume();
	int getNavigationVolume();
	int getNotificationVolume();
};

#endif //SOUND_H_