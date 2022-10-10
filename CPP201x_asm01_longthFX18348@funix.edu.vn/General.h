#pragma once
#ifndef GENERAL_H_
#define GENERAL_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Car.h"
const auto FILE_TIME = "timezone.txt";
const auto FILE_LANGUAGE = "language.txt";
using namespace std;
class General : public Car{
private:
	string time_zone;
	string language;
public:
	General();
	General(string, string, int, int, int, string, string);
	~General();
	string getTimeZone();
	string getLanguage();
};

#endif //GENERAL_H_