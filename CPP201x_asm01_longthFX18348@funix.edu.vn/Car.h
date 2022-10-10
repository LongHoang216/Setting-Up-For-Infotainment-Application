#pragma once
#ifndef CAR_H_
#define CAR_H_
#include <iostream>
#include <string>
#include <regex>
using namespace std;
class Car {
private:
	string owner_name;
	string user_email;
	int private_id;
	int odo_number;
	int remind_service;
public:
	Car();
	Car(string, string, int, int, int);
	~Car();
	string getOwnerName();
	string getEmail();
	int getPrivateID();
	int getOdoNumber();
	int getRemindService();
};

#endif