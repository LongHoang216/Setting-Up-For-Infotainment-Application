#include "General.h"
General::General() {

}
General::General(string name, string email, int id, int odo, int sv, string time, string language) : Car(name, email, id, odo, sv) {
	this->time_zone = time;
	this->language = language;
}
General::~General() {
	//cout << "General function destruction" << endl;
}
string General::getTimeZone() {
	return time_zone;
}
string General::getLanguage() {
	return language;
}