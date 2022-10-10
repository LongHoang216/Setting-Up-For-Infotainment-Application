#include "Sound.h"
Sound::Sound() {

}
Sound::Sound(string name, string email, int id, int odo, int sv, int media, int call, int navi, int noti) : Car(name, email, id, odo, sv) {
	this->media_volume_level = media;
	this->call_volume_level = call;
	this->navigation_volume_level = navi;
	this->notification_volume_level = noti;
}
Sound::~Sound() {
	//cout << "Sound function destruction" << endl;
}
int Sound::getMediaVolume() {
	return media_volume_level;
}
int Sound::getCallVolume() {
	return call_volume_level;
}
int Sound::getNavigationVolume() {
	return navigation_volume_level;
}
int Sound::getNotificationVolume() {
	return notification_volume_level;
}