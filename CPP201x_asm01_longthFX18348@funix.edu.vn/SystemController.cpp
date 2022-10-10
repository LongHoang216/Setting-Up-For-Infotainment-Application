#include "SystemController.h"
using namespace std;
//Các biên count này để đếm số đối tượng trong các mảng 
int displayCnt = 0, soundCnt = 0, generalCnt = 0, carCnt = 0;

Car car[100];
Display display [100];
Sound sound [100];
General general [100];

bool SystemController::ValidateInput(string str, const char* regExp) {
	regex regexInput(regExp);
	if (regex_match(str, regexInput))	//Kiem tra giá trị nhập từ bàn phím có match với định dạng cho sẵn hay không
		return true;
	return false;
}

void SystemController::EnterInformation(string& name, string& email, string& id, string& odo, 
												string& sv, CATEGORY category) {
	system("cls");
	if (category == DISPLAY) {
		cout << "----- Input Display Setting ------" << endl;
		cout << "Car Index: " << displayCnt + 1 << endl;
	}
	else if (category == SOUND) {
		cout << "----- Input Sound Setting ------" << endl;
		cout << "Car Index: " << soundCnt + 1 << endl;
	}
	else if (category == GENERAL) {
		cout << "----- Input General Setting ------" << endl;
		cout << "Car Index: " << generalCnt + 1 << endl;
	}
	cout << "Owner name: ";
	cin.ignore(1000,'\n');	//Xóa bộ nhớ đệm trước khi getline để bò qua ký tự '\n'
	std::getline(std::cin, name);

	cout << "Private ID: ";
	cin >> id;
	cin.clear(); //Xóa cờ lỗi trên cin để I/O làm việc chính xác hơn
	while (!ValidateInput(id, VALIDATE_ID)) {	//Nếu ID nhập vào không hợp lệ thì nhập lại, các thông tin đã lưu
		system("cls");							//ở trên sẽ được hiển thị lại. Các thông tin ở dưới sẽ được thực hiện
		if (category == DISPLAY) {				// tương tự như ID
			cout << "----- Input Display Setting ------" << endl;
			cout << "Car Index: " << displayCnt + 1 << endl;
		}
		else if (category == SOUND) {
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << soundCnt + 1 << endl;
		}
		else if (category == GENERAL) {
			cout << "----- Input General Setting ------" << endl;
			cout << "Car Index: " << generalCnt + 1 << endl;
		}
		cout << "Owner: " << name << endl;
		cout << "Private ID: ";
		cin >> id;
		cin.clear();
	}
	
	cout << "Email: ";
	cin >> email;
	cin.clear();
	while (!ValidateInput(email, VALIDATE_EMAIL)) {
		system("cls");
		if (category == DISPLAY) {
			cout << "----- Input Display Setting ------" << endl;
			cout << "Car Index: " << displayCnt + 1 << endl;
		}
		else if (category == SOUND) {
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << soundCnt + 1 << endl;
		}
		else if (category == GENERAL) {
			cout << "----- Input General Setting ------" << endl;
			cout << "Car Index: " << generalCnt + 1 << endl;
		}

		cout << "Owner: " << name << endl;
		cout << "Private ID: " << id << endl;
		cout << "Email ";
		cin >> email;
		cin.clear();
	}
	//Enter ODO number
	cout << "Odo number: ";
	cin >> odo;
	cin.clear();
	while (!ValidateInput(odo, VALIDATE_INPUT_ODO_SERVICE)) {
		system("cls");
		if (category == DISPLAY) {
			cout << "----- Input Display Setting ------" << endl;
			cout << "Car Index: " << displayCnt + 1 << endl;
		}
		else if (category == SOUND) {
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << soundCnt + 1 << endl;
		}
		else if (category == GENERAL) {
			cout << "----- Input General Setting ------" << endl;
			cout << "Car Index: " << generalCnt + 1 << endl;
		}

		cout << "Owner: " << name << endl;
		cout << "Private ID: " << id << endl;
		cout << "Email: " << email << endl;
		cout << "Odo number: ";
		cin >> odo;
		cin.clear();
	}
	//Enter Remind Service number
	cout << "Remind service number (km): ";
	cin >> sv;
	cin.clear();
	while (!ValidateInput(odo, VALIDATE_INPUT_ODO_SERVICE)) {
		system("cls");
		if (category == DISPLAY) {
			cout << "----- Input Display Setting ------" << endl;
			cout << "Car Index: " << displayCnt + 1 << endl;
		}
		else if (category == SOUND) {
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << soundCnt + 1 << endl;
		}
		else if (category == GENERAL) {
			cout << "----- Input General Setting ------" << endl;
			cout << "Car Index: " << generalCnt + 1 << endl;
		}

		cout << "Owner: " << name << endl;
		cout << "Private ID: " << id << endl;
		cout << "Email: " << email << endl;
		cout << "Odo number: " << odo << endl;
		cout << "Remind service number (km): ";
		cin >> sv;
		cin.clear();
	}
	bool isExisted = false;
	int replace = 0;	//Biến replace dùng để lấy vị trí của đối tượng đã tồn tại trong mảng
	if (carCnt == 0) {
		car[carCnt] = { name,email,stoi(id),stoi(odo),stoi(sv) };
	}
	else {
		while (replace < carCnt) {
			if (car[replace].getPrivateID() == stoi(id)) {	//Tìm kiếm đối tượng đã tồn tại bằng việc so sánh ID
				isExisted = true;
				break;
			}
			replace++;
		}
	}
	if (isExisted) {	//Nếu đối tượng đã tồn tại thì thay thế bằng thông tin mới
		cout << "This car already existed, data will be overwritten !!!" << endl;
		car[replace] = { name,email,stoi(id),stoi(odo),stoi(sv) };
	}
	else {	//Nếu chưa thì lưu vào vị trí tiếp theo trong mảng
		cout << "This is new car, data will be append to your list" << endl;
		car[carCnt++] = { name,email,stoi(id),stoi(odo),stoi(sv) };
	}
	//Sắp xếp các phần tử trong mảng theo thứ tự ID từ bé đến lớn
	for (int i = 0; i < carCnt - 1; i++) {
		for (int j = i + 1; j < carCnt; j++) {
			if (car[i].getPrivateID() > car[j].getPrivateID()) {
				Car temp = car[i];
				car[i] = car[j];
				car[j] = temp;
			}
		}
	}
}
void SystemController::MH1_SCREEN() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT INPUT ---" << endl;
		cout << "1. INPUT SETTING INFORMATION" << endl;
		cout << "2. PRINT SETTING INFORMATION" << endl;
		cout << "3. EXIT" << endl;
		cout << "Your selection: ";
		cin >> inputkey;
		cin.clear();
	} while (!ValidateInput(inputkey,VALIDATE_INPUT_SCREEN));
	int key = stoi(inputkey);

	switch (key) {
	case 1:
		MH2_SCREEN();
		break;
	case 2:
		MH3_SCREEN();
		break;
	case 3:
		cout << "GOOD BYE !!!" << endl;
		exit(0);
	default:
		cout << "NOT MATCHED ANY KEY" << endl;
		break;
	}
}

void SystemController::MH2_SCREEN() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT INPUT ---" << endl;
		cout << "1. DISPLAY SETTING" << endl;
		cout << "2. SOUND SETTING" << endl;
		cout << "3. GENERAL SETTING" << endl;
		cout << "4. EXIT" << endl;
		cout << "Your selection: ";
		cin >> inputkey;
		cin.clear();
	} while (!ValidateInput(inputkey, VALIDATE_INPUT_SCREEN));
	int key = stoi(inputkey);

	switch (key) {
	case 1:
		MH2_SCREEN_DISPLAY();
		break;
	case 2:
		MH2_SCREEN_SOUND();
		break;
	case 3:
		MH2_SCREEN_GENERAL();
		break;
	case 4:
		MH1_SCREEN();
	default:
		cout << "NOT MATCHED ANY KEY" << endl;
		break;
	}
}
void SystemController::MH2_SCREEN_DISPLAY() {
	string name, email, id, odo, sv, inputkey;
	do {
		bool isExisted = false;
		int replace = 0;
		EnterInformation(name, email, id, odo, sv, DISPLAY);	//Nhập thông tin chung vào mảng Car
		//Kiểm tra đối tượng nhập vào đã được lưu trong mảng display hay chưa
		while (replace < displayCnt) {
			if (display[replace].getPrivateID() == stoi(id)) {
				isExisted = true;
				break;
			}
			replace++;
		}
		//Nhập thông tin riêng vào mảng Display
		string light_level, screen_light_level, taplo_light_level;
		cout << "Light level: ";
		cin >> light_level;
		cin.clear();
		while (!ValidateInput(light_level, VALIDATE_INPUT_DISPLAY_SOUND)) {
			system("cls");
			cout << "----- Input Display Setting ------" << endl;
			cout << "Car Index: " << displayCnt + 1 << endl;
			cout << "Owner: " << name << endl;
			cout << "Private ID: " << id << endl;
			cout << "Email: " << email << endl;
			cout << "Odo number: " << odo << endl;
			cout << "Remind service number (km): " << sv << endl;
			cout << "Light level: ";
			cin >> light_level;
			cin.clear();
		}
		cout << "Screen light level: ";
		cin >> screen_light_level;
		cin.clear();
		while (!ValidateInput(screen_light_level, VALIDATE_INPUT_DISPLAY_SOUND)) {
			system("cls");
			cout << "----- Input Display Setting ------" << endl;
			cout << "Car Index: " << displayCnt + 1 << endl;
			cout << "Owner: " << name << endl;
			cout << "Private ID: " << id << endl;
			cout << "Email: " << email << endl;
			cout << "Odo number: " << odo << endl;
			cout << "Remind service number (km): " << sv << endl;
			cout << "Light level: " << light_level << endl;
			cout << "Screen light level: ";
			cin >> screen_light_level;
			cin.clear();
		}
		cout << "Taplo light level: ";
		cin >> taplo_light_level;
		cin.clear();
		while (!ValidateInput(taplo_light_level, VALIDATE_INPUT_DISPLAY_SOUND)) {
			system("cls");
			cout << "----- Input Display Setting ------" << endl;
			cout << "Car Index: " << displayCnt + 1 << endl;
			cout << "Owner: " << name << endl;
			cout << "Private ID: " << id << endl;
			cout << "Email: " << email << endl;
			cout << "Odo number: " << odo << endl;
			cout << "Remind service number (km): " << sv << endl;
			cout << "Light level: " << light_level << endl;
			cout << "Screen light level: " << screen_light_level << endl;
			cout << "Taplo light level: ";
			cin >> taplo_light_level;
			cin.clear();
		}

		if (displayCnt == 0) {
			//Nếu mảng display chưa có phần tử nào thì nhập vào phần tử đầu của mảng
			display[displayCnt++] = { name, email, stoi(id), stoi(odo), stoi(sv),
							stoi(light_level), stoi(screen_light_level), stoi(taplo_light_level) };
		}
		else {
			//Khi mảng đã có phần tử thì mới quét mảng để kiểm tra phần tử nhập vào đã tồn tại trong mảng chưa
			if (isExisted) {	//Nếu phần tử đã tồn tại thì ghi đè lên phần tử cũ
				display[replace] = { name, email, stoi(id), stoi(odo), stoi(sv),
							stoi(light_level), stoi(screen_light_level), stoi(taplo_light_level) };
			}
			else {	//Nếu là phần tử mới thì ghi vào vị trí tiếp theo trong mảng
				display[displayCnt++] = { name, email, stoi(id), stoi(odo), stoi(sv),
							stoi(light_level), stoi(screen_light_level), stoi(taplo_light_level) };
			}
		}
		//Sắp xếp các phần tử trong mảng theo thứ tự ID từ bé đến lớn
		for (int i = 0; i < displayCnt - 1; i++) {
			for (int j = i + 1; j < displayCnt; j++) {
				if (display[i].getPrivateID() > display[j].getPrivateID()) {
					Display temp = display[i];
					display[i] = display[j];
					display[j] = temp;
				}
			}
		}
		cout << "Will you input for car " << displayCnt + 1 << " (y/n): ";
		cin >> inputkey;
		cin.clear();
		while (!ValidateInput(inputkey, VALIDATE_INPUT_YES_NO))
		{
			system("cls");
			cout << "----- Input Display Setting ------" << endl;
			cout << "Car Index: " << displayCnt + 1 << endl;
			cout << "Owner: " << name << endl;
			cout << "Private ID: " << id << endl;
			cout << "Email: " << email << endl;
			cout << "Odo number: " << odo << endl;
			cout << "Remind service number (km): " << sv << endl;
			cout << "Light level: " << light_level << endl;
			cout << "Screen light level: " << screen_light_level << endl;
			cout << "Taplo light level: " << taplo_light_level << endl;
			cout << "Will you input for car " << displayCnt + 1 << " (y/n): ";
			cout << "Please enter y or n: ";
			cin >> inputkey;
			cin.clear();
		}
	} while (displayCnt < 100 && inputkey == "y"); //Nếu người dùng chọn yes thì tiếp tục nhập phần tử cho mảng Display
	MH2_SCREEN();
}
void SystemController::MH2_SCREEN_SOUND() {
	string name, email, id, odo, sv, inputkey;
	do {
		bool isExisted = false;
		int replace = 0;
		EnterInformation(name, email, id, odo, sv, SOUND);
		while (replace < soundCnt) {
			if (sound[replace].getPrivateID() == stoi(id)) {
				isExisted = true;
				break;
			}
			replace++;
		}
		string media, call, navi, noti;
		cout << "Media volume: ";
		cin >> media;
		cin.clear();
		while (!ValidateInput(media, VALIDATE_INPUT_DISPLAY_SOUND)) {
			system("cls");
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << soundCnt + 1 << endl;
			cout << "Owner: " << name << endl;
			cout << "Private ID: " << id << endl;
			cout << "Email: " << email << endl;
			cout << "Odo number: " << odo << endl;
			cout << "Remind service number (km): " << sv << endl;
			cout << "Media volume: ";
			cin >> media;
			cin.clear();
		}
		cout << "Call volume: ";
		cin >> call;
		cin.clear();
		while (!ValidateInput(call, VALIDATE_INPUT_DISPLAY_SOUND)) {
			system("cls");
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << soundCnt + 1 << endl;
			cout << "Owner: " << name << endl;
			cout << "Private ID: " << id << endl;
			cout << "Email: " << email << endl;
			cout << "Odo number: " << odo << endl;
			cout << "Remind service number (km): " << sv << endl;
			cout << "Media volume: " << media << endl;
			cout << "Call volume: ";
			cin >> call;
			cin.clear();
		}
		cout << "Navigation volume: ";
		cin >> navi;
		cin.clear();
		while (!ValidateInput(navi, VALIDATE_INPUT_DISPLAY_SOUND)) {
			system("cls");
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << soundCnt + 1 << endl;
			cout << "Owner: " << name << endl;
			cout << "Private ID: " << id << endl;
			cout << "Email: " << email << endl;
			cout << "Odo number: " << odo << endl;
			cout << "Remind service number (km): " << sv << endl;
			cout << "Media volume: " << media << endl;
			cout << "Call volume: " << call << endl;
			cout << "Navigation volume: ";
			cin >> navi;
			cin.clear();
		}
		cout << "Notification volume: ";
		cin >> noti;
		cin.clear();
		while (!ValidateInput(noti, VALIDATE_INPUT_DISPLAY_SOUND)) {
			system("cls");
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << soundCnt + 1 << endl;
			cout << "Owner: " << name << endl;
			cout << "Private ID: " << id << endl;
			cout << "Email: " << email << endl;
			cout << "Odo number: " << odo << endl;
			cout << "Remind service number (km): " << sv << endl;
			cout << "Media volume: " << media << endl;
			cout << "Call volume: " << call << endl;
			cout << "Navigation volume: " << navi << endl;
			cout << "Notification volume: ";
			cin >> noti;
			cin.clear();
		}
		//Tương tự như Display
		if (soundCnt == 0) {
			sound[soundCnt++] = { name, email, stoi(id), stoi(odo), stoi(sv),
									stoi(media), stoi(call), stoi(navi), stoi(noti) };
		}
		else {
			if (isExisted) {
				sound[replace] = { name, email, stoi(id), stoi(odo), stoi(sv),
										stoi(media), stoi(call), stoi(navi), stoi(noti) };
			}
			else {
				sound[soundCnt++] = { name, email, stoi(id), stoi(odo), stoi(sv),
										stoi(media), stoi(call), stoi(navi), stoi(noti) };
			}
		}
		//Sắp xếp các phần tử trong mảng theo thứ tự ID từ bé đến lớn
		for (int i = 0; i < soundCnt - 1; i++) {
			for (int j = i + 1; j < soundCnt; j++) {
				if (sound[i].getPrivateID() > sound[j].getPrivateID()) {
					Sound temp = sound[i];
					sound[i] = sound[j];
					sound[j] = temp;
				}
			}
		}
		cout << "Will you input for car " << soundCnt + 1 << " (y/n): ";
		cin >> inputkey;
		cin.clear();
		while (!ValidateInput(inputkey, VALIDATE_INPUT_YES_NO))
		{
			system("cls");
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << soundCnt + 1 << endl;
			cout << "Owner: " << name << endl;
			cout << "Private ID: " << id << endl;
			cout << "Email: " << email << endl;
			cout << "Odo number: " << odo << endl;
			cout << "Remind service number (km): " << sv << endl;
			cout << "Media volume: " << media << endl;
			cout << "Call volume: " << call << endl;
			cout << "Navigation volume: " << navi << endl;
			cout << "Notification volume: " << noti << endl;
			cout << "Will you input for car " << soundCnt + 1 << " (y/n)" << endl;
			cout << "Please enter y or n: ";
			cin >> inputkey;
			cin.clear();
		}
	} while (soundCnt < 100 && inputkey == "y");
	MH2_SCREEN();
}
void SystemController::MH2_SCREEN_GENERAL() {
	string name, email, id, odo, sv, inputkey;
	do {
		bool isExisted = false;
		int replace = 0;
		EnterInformation(name, email, id, odo, sv, GENERAL);
		while (replace < generalCnt) {
			if (general[replace].getPrivateID() == stoi(id)) {
				isExisted = true;
				break;
			}
			replace++;
		}
		//CHOOSE TIMEZONE
		string input_time;
		vector<string> list_time_zone;
		fstream file1(FILE_TIME, ios::in | ios::out);
		if (file1.is_open()) {
			string line, cityname, GMT;
			while (getline(file1, line)) {	//Lấy thông tin từ file timezone.txt và lưu vào vector time_zone
				list_time_zone.push_back(line);
			}
		}
		else {
			cout << "FAIL TO OPEN FILE" << endl;
		}
		file1.close();
		sort(list_time_zone.begin(), list_time_zone.end());	//Sắp xếp các giá trị timezone theo thứ tự UTC
		do{
			do {
				system("cls");
				cout << "--- SELECT TIMEZONE DATA ---" << endl;
				for (int i = 0; i < list_time_zone.size(); i++) {
					cout << i + 1 << ": " << list_time_zone[i] << endl;
				}
				cout << "YOUR SELECTION: ";
				cin >> input_time;
			}  while (!ValidateInput(input_time, VALIDATE_INPUT_SCREEN));
		} while (stoi(input_time) > 32); //Chỉ có 32 giá trị timezone nên người dùng không nhập vào quá 32

		//CHOOSE LANGUAGE
		string input_language;
		vector<string> list_language;
		fstream file(FILE_LANGUAGE, ios::in | ios::out);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {	//Lấy giá trị trong language.txt và lưu vào vector list_language
				list_language.push_back(line);
			}
		}
		else {
			cout << "FAIL TO OPEN FILE" << endl;
		}
		file.close();
		sort(list_language.begin(), list_language.end());	//Sắp xếp các giá trị trong list_language theo thứ tự Alphabet
		do{
			do {
				system("cls");
				cout << "--- SELECT LANGUAGE DATA ---" << endl;
				for (int i = 0; i < list_language.size(); i++) {
					cout << i + 1 << ": " << list_language[i] << endl;
				}
				cout << "YOUR SELECTION: ";
				cin >> input_language;
			}  while (!ValidateInput(input_language, VALIDATE_INPUT_SCREEN));
		} while (stoi(input_language) > 30);	//Chỉ có 30 language nên giá trị nhập vào không được vượt quá 30

		if (generalCnt == 0) {
			general[generalCnt++] = { name, email, stoi(id), stoi(odo), stoi(sv), 
										list_time_zone[stoi(input_time) - 1], list_language[stoi(input_language) - 1] };
		}
		else {
			if (isExisted) {
				general[replace] = { name, email, stoi(id), stoi(odo), stoi(sv),
										list_time_zone[stoi(input_time) - 1], list_language[stoi(input_language) - 1] };
			}
			else {
				general[generalCnt++] = { name, email, stoi(id), stoi(odo), stoi(sv),
										list_time_zone[stoi(input_time) - 1], list_language[stoi(input_language) - 1] };
			}
		}
		//Sắp xếp các phần tử trong mảng theo thứ tự ID từ bé đến lớn
		for (int i = 0; i < generalCnt - 1; i++) {
			for (int j = i + 1; j < generalCnt; j++) {
				if (general[i].getPrivateID() > general[j].getPrivateID()) {
					General temp = general[i];
					general[i] = general[j];
					general[j] = temp;
				}
			}
		}
		cout << "Will you input for car " << generalCnt + 1 << " (y/n): ";
		cin >> inputkey;
		cin.clear();
		while (!ValidateInput(inputkey, VALIDATE_INPUT_YES_NO)) {
			system("cls");
			cout << "----- Input General Setting ------" << endl;
			cout << "Car Index: " << generalCnt + 1 << endl;
			cout << "Owner: " << name << endl;
			cout << "Private ID: " << id << endl;
			cout << "Email: " << email << endl;
			cout << "Odo number: " << odo << endl;
			cout << "Remind service number (km): " << sv << endl;
			cout << "Timezone: " << list_time_zone[stoi(input_time)] << endl;
			cout << "Language: " << list_language[stoi(input_language)] << endl;
			cout << "Will you input for car " << generalCnt + 1 << " (y/n): ";
			cout << "Please enter y or n: ";
			cin >> inputkey;
			cin.clear();
		}
	} while (inputkey == "y" && generalCnt < 100);
	MH2_SCREEN();
}
void SystemController::MH3_SCREEN() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT INPUT ---" << endl;
		cout << "1. PRINT DISPLAY SETTING INFORMATION" << endl;
		cout << "2. PRINT SOUND SETTING INFORMATION" << endl;
		cout << "3. PRINT GENERAL SETTING INFORMATION" << endl;
		cout << "4. PRINT ALL SETTING INFORMATION" << endl;
		cout << "5. EXIT" << endl;
		cout << "Your selection: ";
		cin >> inputkey;
		cin.clear();
	} while (!ValidateInput(inputkey, VALIDATE_INPUT_SCREEN));
	int key = stoi(inputkey);

	switch (key) {
	case 1:
		MH3_SCREEN_PRINT_DISPLAY();
		break;
	case 2:
		MH3_SCREEN_PRINT_SOUND();
		break;
	case 3:
		MH3_SCREEN_PRINT_GENERAL();
		break;
	case 4:
		MH3_SCREEN_PRINT_ALL();
		break;
	case 5:
		MH1_SCREEN();
	default:
		cout << "NOT MATCHED ANY KEY" << endl;
		break;
	}
}

void SystemController::MH3_SCREEN_PRINT_DISPLAY() {
	int i = 0;
	system("cls");
	//Đối với các giá trị chung như: name, email. ID, odo number hay remind service sẽ được lấy từ mảng Car
	//Các giá trị riêng sẽ được lấy từ các mảng riêng như Display, Sound hay General
	cout << "--- Display setting ---" << endl;
	cout << setw(30) << left << "Owner name" << setw(25) << "Email" << setw(25) << "Key number" << setw(20) << "ODO number" << setw(25) << "Remind service (km)" << setw(20) << "Light level" << setw(25) << "Screen light level" << setw(25) << "Taplo light level" << endl;
	while (i < displayCnt) {
		for (int j = 0; j < carCnt; j++) {
			//Chỉ in những giá trị trong mảng Car mà tồn tại trong mảng sound
			if (car[j].getPrivateID() == display[i].getPrivateID())
				cout << setw(30) << left << car[j].getOwnerName() << setw(25) << car[j].getEmail() << setw(25) << car[j].getPrivateID() << setw(20) << car[j].getOdoNumber() << setw(25) << car[j].getRemindService() << setw(20) << display[i].getLightLevel() << setw(25) << display[i].getScreenLightLevel() << setw(25) << display[i].getTaploLightLevel() << endl;
		}
		i++;
	}
	system("pause");
	MH3_SCREEN();
}

void SystemController::MH3_SCREEN_PRINT_SOUND() {
	int i = 0;
	system("cls");
	cout << "--- Sound setting ---" << endl;
	cout << setw(25) << left << "Owner name" << setw(25) << "Email" << setw(15) << "Key number" << setw(15) << "ODO number" << setw(25) << "Remind service (km)" << setw(25) << "Media volume level" << setw(25) << "Call volume level" << setw(30) << "Navigation volume level" << setw(20) << right << "Notification volume level" << endl;
	while (i < soundCnt) {
		for (int j = 0; j < carCnt; j++) {
			if (car[j].getPrivateID() == sound[i].getPrivateID())
				cout << setw(25) << left << car[j].getOwnerName() << setw(25) << car[j].getEmail() << setw(15) << car[j].getPrivateID() << setw(15) << car[j].getOdoNumber() << setw(25) << car[j].getRemindService() << setw(25) << sound[i].getMediaVolume() << setw(25) << sound[i].getCallVolume() << setw(30) << sound[i].getNavigationVolume() << setw(20) << sound[i].getNotificationVolume() << endl;
		}
		i++;
	}
	system("pause");
	MH3_SCREEN();
}

void SystemController::MH3_SCREEN_PRINT_GENERAL() {
	int i = 0;
	system("cls");
	cout << "--- General setting ---" << endl;
	cout << setw(25) << left << "Owner name" << setw(20) << "Email" << setw(15) << "Key number" << setw(15) << "ODO number" << setw(25) << "Remind service (km)" << setw(45) << "Timezone" << setw(30) << right << "Language" << endl;
	while (i < generalCnt) {
		for (int j = 0; j < carCnt; j++) {
			if (car[j].getPrivateID() == general[i].getPrivateID())
				cout << setw(25) << left << car[j].getOwnerName() << setw(20) << car[j].getEmail() << setw(15) << car[j].getPrivateID() << setw(15) << car[j].getOdoNumber() << setw(25) << car[j].getRemindService() << setw(67) << general[i].getTimeZone() << setw(30) << general[i].getLanguage() << endl;
		}
		i++;
	}
	system("pause");
	MH3_SCREEN();
}
void SystemController::MH3_SCREEN_PRINT_ALL() {
	//In ra màn hình các đối tượng trong mảng Car
	//Nếu trong các mảng Display, Sound hay General có đối tượng đã được lưu trong mảng Car thì in ra màn hình
	int i = 0;
	cout << "--- All setting ---" << endl;
	while (i < carCnt) {
		cout << setw(25) << left << "Owner name" << setw(25) << "Email" << setw(20) << "Key number" << setw(20) << "ODO number" << setw(30) << "Remind service (km)" << endl;
		cout << setw(25) << left << car[i].getOwnerName() << setw(25) << car[i].getEmail() << setw(20) << car[i].getPrivateID() << setw(20) << car[i].getOdoNumber() << setw(30) << car[i].getRemindService() << endl;
		for (int j = 0; j < displayCnt; j++) {
			if (display[j].getPrivateID() == car[i].getPrivateID()) {
				cout << left << setw(20) << "Display: " << setw(20) << "Light" << setw(20) << "Screen Light" << setw(20) << "Taplo Light" << endl;
				cout << left << setw(20) << " " << setw(20) << display[i].getLightLevel() << setw(20) << display[i].getScreenLightLevel() << setw(20) << display[i].getTaploLightLevel() << endl;
			}
		}
		for (int j = 0; j < soundCnt; j++) {
			if (sound[j].getPrivateID() == car[i].getPrivateID()) {
				cout << left << setw(20) << "Sound: " << setw(20) << "Media" << setw(20) << "Call" << setw(20) << "Navigation" << setw(20) << "Notification" << endl;
				cout << left << setw(20) << " " << setw(20) << sound[i].getMediaVolume() << setw(20) << sound[i].getCallVolume() << setw(20) << sound[i].getNavigationVolume() << setw(20) << sound[i].getNotificationVolume() << endl;				
			}
		}
		for (int j = 0; j < generalCnt; j++) {
			if (general[j].getPrivateID() == car[i].getPrivateID()) {
				cout << left << setw(20) << "General: " << setw(50) << "Timezone" << endl;
				cout << setw(20) << " " << general[i].getTimeZone() << endl;
				cout << setw(20) << " " << "Language" << endl;
				cout << setw(20) << " " << general[i].getLanguage() << endl;
			}
		}
		i++;
		cout <<"------------------------------------------------------------------------------------------------------" << endl;
	}
	system("pause");
	MH3_SCREEN();
}