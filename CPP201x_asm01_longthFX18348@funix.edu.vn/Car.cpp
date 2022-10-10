#include "Car.h"
Car::Car() {

}
Car::Car(string name, string email,int id, int odo, int sv) {
	this->owner_name = name;
	this->private_id = id;
	this->user_email = email;
	this->odo_number = odo;
	this->remind_service = sv;
}
Car::~Car() {
	//cout << "Car destruction" << endl;
}
string Car::getOwnerName() {
	return owner_name;
}
int Car::getPrivateID() {
	return private_id;
}
string Car::getEmail() {
	return user_email;
}
int Car::getOdoNumber() {
	return odo_number;
}
int Car::getRemindService() {
	return remind_service;
}