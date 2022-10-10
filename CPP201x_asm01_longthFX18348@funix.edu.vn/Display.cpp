#include "Display.h"
Display::Display() {

}
Display::Display(string name, string email,int id, int odo, int sv, int light, int screen, int taplo):Car(name,email,id,odo,sv) {
	this->light_level = light;
	this->screen_light_level = screen;
	this->taplo_light_level = taplo;
}
Display::~Display() {
	//cout << "Display function destruction" << endl;
}
int Display::getLightLevel() {
	return light_level;
}
int Display::getScreenLightLevel() {
	return screen_light_level;
}
int Display::getTaploLightLevel() {
	return taplo_light_level;
}