#pragma once
#ifndef SYSTEM_CONTROLLER_H_
#define SYSTEM_CONTROLLER_H_
#include <iostream>
#include <regex>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Display.h"
#include "Car.h"
#include "Sound.h"
#include "General.h"
using namespace std;

const auto VALIDATE_EMAIL = "^\\w+\\@\\w+\\.\\w+(\\.\\w+)*$";	//Định dạng email là: name@abc.xyz(.vn)
const auto VALIDATE_ID = "^\\d{8}$";	//MSCN phải bao gồm 8 số
const auto VALIDATE_INPUT_ODO_SERVICE = "^[1-9]\\d+$";
const auto VALIDATE_INPUT_DISPLAY_SOUND = "^[1-5]$";
const auto VALIDATE_INPUT_SCREEN = "^\\d+$";	//input nhập vào phải là số
const auto VALIDATE_INPUT_YES_NO = "^y$|^n$";	//Các câu hỏi yes/no chỉ nhập vào y or n

enum CATEGORY {
	DISPLAY, SOUND, GENERAL	//Biến enum CATEGORY dùng để hiển thị thông báo ứng với đối tượng cần nhập thông tin
};

class SystemController {
public:
	//XÉT TÍNH HỢP LỆ CỦA INPUT 
	bool ValidateInput(string str, const char* regExp);
	//HÀM NHẬP THÔNG TIN CHO XE
	void EnterInformation(string& name, string& email, string& id, string& odo, string& sv, CATEGORY category);
	//SCREEN 1:	GENERAL SCREEN
	void MH1_SCREEN();
	//SCREEN 2: INPUT SCREEN
	void MH2_SCREEN();
	void MH2_SCREEN_DISPLAY();
	void MH2_SCREEN_SOUND();
	void MH2_SCREEN_GENERAL();
	//SCREEN 3: PRINT SCREEN
	void MH3_SCREEN();
	void MH3_SCREEN_PRINT_DISPLAY();
	void MH3_SCREEN_PRINT_SOUND();
	void MH3_SCREEN_PRINT_GENERAL();
	void MH3_SCREEN_PRINT_ALL();
};
#endif //SYSTEM_CONTROLLER_H_