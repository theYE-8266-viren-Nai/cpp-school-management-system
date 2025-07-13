
//Dear UIT teachers,
//if the program is going to be used , contact us 
//I hope this message finds you well.We wanted to discuss the ongoing refinement of our C++ program, especially if there is a possibility of its usage for an upcoming event.We genuinely appreciate your dedication to our education and your guidance throughout this project.If the program is considered for an event, please do not hesitate to reach out to us.We are fully committed to ensuring its excellence for any such purpose.However, as we are currently juggling a demanding schedule, primarily due to our upcoming exams, we kindly request your understanding.We are more than willing to prioritize the program's refinement to meet the event's needs, but timely communication from your end would be greatly appreciated.We understand the importance of showcasing our skills and are ready to work diligently to enhance the program's quality. Your support in adjusting the timeline for program improvement and promptly informing us of any event-related details would greatly assist us in effectively managing our academic commitments alongside this valuable opportunity. Thank you for considering our request, and we look forward to your guidance and timely updates in this matter.
//
//Best regards,
//
//Thuriya Ye' Naing , Zwe Nyi Nyar , Shwe Nan Htet , Khin La Pyae Htun , Nyein Yati Oo , Thin Thu Win Aung 
#include <iostream>
#include <fstream>
#include<string>
#include<regex>
#include <limits>
#include <Windows.h>
#undef min
#undef max 
using namespace std;
struct ClassPeriod {
	string subject;
};
struct DaySchedule {
	ClassPeriod periods[4];
};
struct SectionSchedule {
	DaySchedule days[5];
};
struct SemesterSchedule {
	SectionSchedule section[5];
};
struct SchoolYearSchedule {
	SemesterSchedule semesters[2];
};
struct SchoolTimetable {
	SchoolYearSchedule years[2];
};


void prompt();
void header();
void signUpPrompt();
void loginPrompt();
void sectionRegister();
void clubRegister();
void yearRegister();
void semRegister();
void loginTrPrompt();
void dataInstall(string& fileName, string& input);
void dataIntoArray(string* arr, string& fileName);
void displayTimetable(const SchoolTimetable& timetable, int year, int semester, int section);
void rearrangeTimetable(SchoolTimetable& timetable);
void saveArrayToFile(const string array[], const string& filename);
void editTimetableEntry(SchoolTimetable& timetable, int year, int semester, int week, int day, int period, const ClassPeriod& updatedEntry);
void gimmeData();
int checkInput(int i, int j);
string trim(const string& str);
string getDataWithSpaces();
//the functions description are below the int main()
int main() {

	//mainpage
	SchoolTimetable timetable;
	int switchInput ;//main
	int switchInput1;// where the user want to go in login page
	int switchInput2;//section
	int switchInput3;//club
	int switchInput4;//year
	int switchInput5;//sem
	regex validNumberPattern("^[1-4]$");

	regex validNumberPattern1("^[1-7]$");
	regex validNumberPattern2("^[1-5]$");
	regex validNumberPattern3("^[1-6]$");
	regex validNumberPattern4("^[1-5]$");
	regex validNumberPattern5("^[1-2]$");

	int trSwitch;
	char q1;
	int n = 0;//size of an array
	do {
		fstream file;
		ifstream inputFile;
		string str;
		string fileName;//for functions
		string inputName;
		string inputPsw;
		string inputSec;
		string inputClub;
		string inputYear;
		string inputSem;
		string inputTrName;
		string inputTrPsw;
		string nameArr[10];
		string pswArr[10];
		string sectionArr[10];
		string clubArr[10];
		string yearArr[10];
		string semArr[10];
		string nameTrArr[10];
		string pswTrArr[10];
		//Zwe Zwe part
		const int ZZMAX = 25;
		string zzsection1TT[ZZMAX];
		string zzsection2TT[ZZMAX];
		string zzsection3TT[ZZMAX];
		string zzsection4TT[ZZMAX];
		string zzsection5TT[ZZMAX];

		int a1, a2, a3;
		int i = 0;
		int h = 0;
		int log = 0;
		int forInfo = 0;
		int noRepeat = 0;
		int size = 0;
		fileName = "name.txt";
		dataIntoArray(nameArr, fileName);
		fileName = "psw.txt";
		dataIntoArray(pswArr, fileName);
		fileName = "section.txt";
		dataIntoArray(sectionArr, fileName);
		prompt();
		for (int i = 0;i < 10;i++)
		{
			if (nameArr[i] == "")
			{
				break;
			}
			size++;
		}
		int flag = 0;
		if (nameArr[size - 1] != "" && sectionArr[size - 1] == "")
		{
			flag = 1;
		}
		switchInput = checkInput(1, 4);
			switch (switchInput) {
			case 1:
				system("cls");
				if (flag != 0)
				{
					system("cls");
					cout << "You need to put the data first to the account that has previously been created ";
					Sleep((800));
				}
				else
				{
					cout << "Enter your username you want to register \n";
					inputName = getDataWithSpaces();
					inputName = trim(inputName);
					cout << "Enter your password you want to register\n";
					cin >> inputPsw;
					inputPsw = trim(inputPsw);
					file.open("name.txt", ios::in);//file read
					while (getline(file, str)) {
						if (inputName == str) {
							noRepeat = 1;
							break;
						}
						else {}

					}
					file.close();
					file.open("psw.txt", ios::in);
					while (getline(file, str)) {


						if (inputPsw == str) {
							noRepeat = 1;
							break;
						}
						else {}
						//i++;
					}
					file.close();

					if (noRepeat != 0) {
						system("cls");
						cout << "This username , password or has already been registered \n";
						Sleep(1000);
					}
					else {
						fileName = "name.txt";
						dataInstall(fileName, inputName);
						fileName = "psw.txt";
						dataInstall(fileName, inputPsw);
					}
					file.close();

				}
				break;
			case 2:
				fileName = "name.txt";
				dataIntoArray(nameArr, fileName);
				fileName = "psw.txt";
				dataIntoArray(pswArr, fileName);
				//checking with the array is necessary therefore install data into theArray
				system("cls");
				cout << "Enter your username \n";
				inputName = getDataWithSpaces();
				inputName = trim(inputName);
				cout << "Enter your password \n";
				cin >> inputPsw;
				inputPsw = trim(inputPsw);
				//file read for checking name and password and tnt
				//file reading for checking
				file.open("name.txt", ios::in);
				while (getline(file, str)) {
					if (inputName == nameArr[h]) {
						if (inputName == trim(str)) {
							log += 1;
							break;
						}
					}
					else {}
					forInfo += 1;
					h++;
				}
				file.close();
				file.open("psw.txt", ios::in);
				h = 0;
				while (getline(file, str)) {

					if (inputPsw == pswArr[forInfo]) {
						if (inputPsw == trim(str)) {
							log += 1;
							break;
						}
					}
					else {}
				}
				file.close();
				//
				if (log == 2) {
					do {
						fileName = "name.txt";
						dataIntoArray(nameArr, fileName);
						fileName = "section.txt";
						dataIntoArray(sectionArr, fileName);
						fileName = "club.txt";
						dataIntoArray(clubArr, fileName);
						fileName = "year.txt";
						dataIntoArray(yearArr, fileName);
						fileName = "sem.txt";
						dataIntoArray(semArr, fileName);
						loginPrompt();
						//log in
						switchInput1= checkInput(1,7);
							switch (switchInput1) {
							case 1://section register
								if (sectionArr[forInfo] == "A" || sectionArr[forInfo] == "B" || sectionArr[forInfo] == "C" || sectionArr[forInfo] == "D" || sectionArr[forInfo] == "E") {
									system("cls");
									cout << "You cannot register the class again \n";
									Sleep(1000);
								}
								else {
									sectionRegister();
									switchInput2 = checkInput(1, 5);
										switch (switchInput2) {
										case 1:
											inputSec = "A";
											cout << "Section registration has completed \n";
											break;
										case 2:
											inputSec = "B";
											cout << "Section registration has completed \n";
											break;
										case 3:
											inputSec = "C";
											cout << "Section registration has completed \n";
											break;
										case 4:
											inputSec = "D";
											cout << "Section registration has completed \n";
											break;
										case 5:
											inputSec = "E";
											cout << "Section registration has completed \n";
											break;
										default:
											cout << "Invalid";
											break;

										}
										file.open("section.txt", ios::out | ios::app);
										file << inputSec << endl;
										file.close();
									}
									

								break;
							case 2://club register
								if (clubArr[forInfo] == "Football" || clubArr[forInfo] == "Volleyball" || clubArr[forInfo] == "Badminton" || clubArr[forInfo] == "Tennis" || clubArr[forInfo] == "TableTennis" || clubArr[forInfo] == "Swimming")
								{
									system("cls");
									cout << "You cannot register the club again \n";
									Sleep(1000);
								}
								else {
									clubRegister();
									switchInput3 = checkInput(1, 6);
										switch (switchInput3) {
										case 1:
											inputClub = "Football";
											cout << "Club registration has completed \n";
											break;
										case 2:
											inputClub = "Volleyball";
											cout << "Club registration has completed \n";
											break;
										case 3:
											inputClub = "Badminton";
											cout << "Club registration has completed \n";
											break;
										case 4:
											inputClub = "Tennis";
											cout << "Club registration has completed \n";
											break;
										case 5:
											inputClub = "TableTennis";
											cout << "Club registration has completed \n";
											break;
										case 6:
											inputClub = "Swimming";
											cout << "Club registration has completed \n";
											break;
										default:
											cout << "Invalid";
											break;

										}
										file.open("club.txt", ios::out | ios::app);
										file << inputClub << endl;
										file.close();
									
									}

								break;
							case 3://year register
								if (yearArr[forInfo] == "First Year" || yearArr[forInfo] == "Second Year" || yearArr[forInfo] == "Third Year" || yearArr[forInfo] == "Fourth Year" || yearArr[forInfo] == "Fifth Year") {
									system("cls");
									cout << "You cannot register the year again \n";
									Sleep(1000);
								}
								else {
									yearRegister();
									switchInput4 = checkInput(1, 5);
									
										switch (switchInput4) {
										case 1:
											inputYear = "First Year";
											cout << "Year registration has completed \n";
											break;
										case 2:
											inputYear = "Second Year";
											cout << "Year registration has completed \n";
											break;
										case 3:
											inputYear = "Third Year";
											cout << "Year registration has completed \n";
											break;
										case 4:
											inputYear = "Fourth Year";
											cout << "Year registration has completed \n";
											break;
										case 5:
											inputYear = "Fifth Year";
											cout << "Year registration has completed \n";
											break;
										default:
											cout << "Invalid";
											break;

										}
										file.open("year.txt", ios::out | ios::app);
										file << inputYear << endl;
										file.close();
									
									}
								break;
							case 4://semester register
								if (semArr[forInfo] == "First Semester" || semArr[forInfo] == "Second Semester") {
									system("cls");
									cout << "You cannot register the sem again. Please try again. \n";
									Sleep(1000);
								}
								else {
									semRegister();
									
									switchInput5 = checkInput(1, 2);
										switch (switchInput5) {
										case 1:
											inputSem = "First Semester";
											cout << "Semester registration has completed \n";
											break;
										case 2:
											inputSem = "Second Semester";
											cout << "Semester registration has completed \n";
											break;
										default:
											cout << "Invalid";
											break;

										}
										file.open("sem.txt", ios::out | ios::app);
										file << inputSem << endl;
										file.close();
									
									}
								
								break;
							case 5:
								if(yearArr[forInfo] == "" || sectionArr [forInfo] == "" || semArr[forInfo] == "")
								{
									system("cls");
									cout << "Please input section , year and semester first \n";
									Sleep(1000);
								}
								else
								{
									inputFile.open("timetable.bin", ios::binary);
									if (!inputFile) {
										cerr << "Failed to open the binary file." << endl;
										return 1;
									}

									inputFile.read(reinterpret_cast<char*>(&timetable), sizeof(timetable));

									inputFile.close();
									if (sectionArr[forInfo] == "A") a3 = 1;
									if (sectionArr[forInfo] == "B") a3 = 2;
									if (sectionArr[forInfo] == "C") a3 = 3;
									if (sectionArr[forInfo] == "D") a3 = 4;
									if (sectionArr[forInfo] == "E") a3 = 5;

									if (yearArr[forInfo] == "First Year") a1 = 1;
									if (yearArr[forInfo] == "Second Year") a1 = 2;

									if (semArr[forInfo] == "First Semester") a2 = 1;
									if (semArr[forInfo] == "Second Semester") a2 = 2;




									displayTimetable(timetable, a1, a2, a3);
								}
								break;
								//zwe zwe end

							case 6:

								//this is check my info
								system("cls");
								cout << "\t\t\t\t\t Your information are : \n ";
								cout << endl;
								cout << "\t\t\t\t\t " << "\tName :" << nameArr[forInfo] << endl;
								cout << endl;
								cout << "\t\t\t\t\t " << "\tSection :" << sectionArr[forInfo] << endl;
								cout << endl;
								cout << "\t\t\t\t\t " << "\tClub :" << clubArr[forInfo] << endl;
								cout << endl;
								cout << "\t\t\t\t\t " << "\tYear  :" << yearArr[forInfo] << endl;
								cout << endl;
								cout << "\t\t\t\t\t " << "\tSemester  :" << semArr[forInfo] << endl;
								cout << endl;
								Sleep(2000);
								break;
							case 7:
								if (sectionArr[forInfo] == "" || clubArr[forInfo] == "" || yearArr[forInfo] == "" || semArr[forInfo] == "") {
									system("cls");
									cout << "You cannot leave without registering section and clubs \n";
									switchInput1 = 6;
									Sleep(1000);
								}
								else {
									switchInput1 = 7;
								}
								break;
							default:
								break;
							}
						

					} while (switchInput1 != 7);

				}
				else {
					cout << "login failed" << endl;
				}
				Sleep(1000);
				//login
				//file.open("")
				break;
			case 3:

				fileName = "teachername.txt";
				dataIntoArray(nameTrArr, fileName);
				fileName = "teacherpsw.txt";
				dataIntoArray(pswTrArr, fileName);
				//checking with the array is necessary therefore install data into theArray
				system("cls");
				cout << "Enter your username \n";
				cin >> inputTrName;
				cout << "Enter your password \n";
				cin >> inputTrPsw;
				//file read for checking name and password and tnt
				//file reading for checking
				file.open("teachername.txt", ios::in);
				while (getline(file, str)) {
					if (inputTrName == nameTrArr[h]) {
						log += 1;
						break;
					}
					else {}
					forInfo += 1;
					h++;
				}
				file.close();
				file.open("teacherpsw.txt", ios::in);
				h = 0;
				while (getline(file, str)) {

					if (inputTrPsw == pswTrArr[forInfo]) {
						log += 1;
						break;
					}
					else {}
				}
				file.close();
				if (log == 2) {
					do {
						loginTrPrompt();
						trSwitch = checkInput(1, 2);
							switch (trSwitch) {

							case 1:

								ifstream inputFile("timetable.bin", ios::binary);
								if (!inputFile) {
									cerr << "Failed to open the binary file." << endl;
									return 1;
								}

								inputFile.read(reinterpret_cast<char*>(&timetable), sizeof(timetable));

								inputFile.close();
								//input from a binary file
								rearrangeTimetable(timetable);
								ofstream outputFile("timetable.bin", ios::binary);
								if (!outputFile) {
									cerr << "Failed to open the binary file for writing." << endl;
									return 1;
								}

								outputFile.write(reinterpret_cast<char*>(&timetable), sizeof(timetable));
								outputFile.close();


								break;
							}
						
						
					} while (trSwitch != 2);
				}
				else
				{
					cout << "login failed" << endl;
				}
				Sleep(1000);
				break;
			default:
				break;
			}
		
		
	} while (switchInput != 4 );

}

void prompt() {
	system("cls");
	cout << "\t\t\t ---------------------------------------------------\n";
	cout << "\t\t\t|                                                   |\n";
	cout << "\t\t\t| Welcome from University Of Information Technology |\n";
	cout << "\t\t\t|                                                   |\n";
	cout << "\t\t\t ---------------------------------------------------\n";
	cout << endl;
	cout << "\t\t\t\t\t    FOR STUDENTS" << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter a number ( 1 to 4)" << endl;
	cout << endl;
	cout << "\t\t\t\t\t    1. Sign Up" << endl;
	cout << endl;
	cout << "\t\t\t\t\t    2. Log In" << endl;
	cout << endl;
	cout << "\t\t\t\t\t    FOR TEACHERS" << endl;
	cout << endl;
	cout << "\t\t\t\t\t    3. Log In" << endl;
	cout << endl;
	cout << "\t\t\t\t\t    4. Exit " << endl;
	cout << endl;
}
//this is the prompt for the header
void header() {
	system("cls");
	cout << "\t\t\t ---------------------------------------------------\n";
	cout << "\t\t\t|                                                   |\n";
	cout << "\t\t\t| Welcome from University Of Information Technology |\n";
	cout << "\t\t\t|                                                   |\n";
	cout << "\t\t\t ---------------------------------------------------\n";
	cout << endl;
}
//signup
void signUpPrompt() {
	system("cls");
	cout << "sign up successfully" << endl;
}
//login
void loginPrompt() {
	system("cls");
	cout << "\t\t\t ---------------------------------------------------\n";
	cout << "\t\t\t|                                                   |\n";
	cout << "\t\t\t| Welcome from University Of Information Technology |\n";
	cout << "\t\t\t|                                                   |\n";
	cout << "\t\t\t ---------------------------------------------------\n";
	cout << endl;
	cout << "\t\t\t\t\t  FOR STUDENTS" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  1. Section Register" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  2. School Clubs Register" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  3. Year Register" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  4. Semester Register" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  5. Schedule " << endl;
	cout << endl;
	cout << "\t\t\t\t\t  6. Check my info" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  7. Exit" << endl;
	cout << endl;
}
void sectionRegister() {
	system("cls");
	cout << "\t\t\t\t  Enter a number to choose the section you want to register \n";
	cout << endl;
	cout << "\t\t\t\t  You cannot reregister the section once it has been registered \n";
	cout << endl;
	cout << "\t\t\t\t\t  1. A" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  2. B" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  3. C" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  4. D" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  5. E" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  ";
}
void yearRegister() {
	system("cls");
	cout << "\t\t\t\t  Enter a number to choose the year you want to register \n";
	cout << endl;
	cout << "\t\t\t\t  You cannot reregister the year once it has been registered \n";
	cout << endl;
	cout << "\t\t\t\t\t  1. First Year" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  2. Second Year" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  3. Third Year" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  4. Fourth Year" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  5. Fifth Year" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  ";
}
void semRegister() {
	system("cls");
	cout << "\t\t\t\t  Enter a number to choose which semester you want to register \n";
	cout << endl;
	cout << "\t\t\t\t  You cannot reregister the section once it has been registered \n";
	cout << endl;
	cout << "\t\t\t\t\t  1. First Semester " << endl;
	cout << endl;
	cout << "\t\t\t\t\t  2. Second Semester" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  ";
}
void clubRegister() {
	system("cls");
	cout << "\t\t\t\t  Enter a number to choose the clubs you want to register \n";
	cout << endl;
	cout << "\t\t\t\t  You cannot reregister the clubs once it has been registered \n";
	cout << endl;
	cout << "\t\t\t\t\t  1. Football " << endl;
	cout << endl;
	cout << "\t\t\t\t\t  2. Volleyball" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  3. Badminton" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  4. Tennis" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  5. Table Tennis" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  6. Swimming" << endl;
}
void dataInstall(string& fileName, string& input) {
	fstream file1;
	file1.open(fileName, ios::out | ios::app);
	file1 << input << endl;
	file1.close();
	/*file.open("name.txt", ios::out | ios::app);
				file << inputName << endl;
				file.close();*/
}
void dataIntoArray(string* arr, string& fileName) {
	int i = 0;
	string str;
	fstream file;
	file.open(fileName, ios::in);
	while (getline(file, str)) {
		arr[i] = str;
		i++;
	}
	file.close();
}
void displayTimetable(const SchoolTimetable& timetable, int year, int semester, int section) {
	system("cls");
	cout << "\t\t\t\t  Timetable" << endl;
	cout << "\t\t\t -----------------------------------------" << endl;
	cout << "\t\t\t| Day      |  1st  |  2nd  |  3rd  |  4th  |" << endl;
	cout << "\t\t\t -----------------------------------------" << endl;

	for (int day = 0; day < 5; day++) {
		cout << "\t\t\t| ";

		switch (day) {
		case 0: cout << "Monday   |"; break;
		case 1: cout << "Tuesday  |"; break;
		case 2: cout << "Wednesday|"; break;
		case 3: cout << "Thursday |"; break;
		case 4: cout << "Friday   |"; break;

		}

		// Display class periods for the day
		for (int period = 0; period < 4; period++) {

			const ClassPeriod& classPeriod = timetable.years[year - 1].semesters[semester - 1].section[section - 1].days[day].periods[period];
			if (classPeriod.subject == " ") { cout << "       |"; }
			else
				cout << " " << classPeriod.subject << "  |";
		}

		cout << endl;
	}

	cout << "\t\t\t -----------------------------------------" << endl;
	// Add a delay so that the user has time to see the timetable
	Sleep(4000);
}


void loginTrPrompt() {
	system("cls");
	cout << "\t\t\t ---------------------------------------------------\n";
	cout << "\t\t\t|                                                   |\n";
	cout << "\t\t\t| Welcome from University Of Information Technology |\n";
	cout << "\t\t\t|                                                   |\n";
	cout << "\t\t\t ---------------------------------------------------\n";
	cout << endl;
	cout << "\t\t\t\t\t  FOR TEACHERS" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  Enter a number" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  1. Rearrange Schedule" << endl;
	cout << endl;
	cout << "\t\t\t\t\t  2. Exit" << endl;
	cout << endl;
}
void rearrangeTimetable(SchoolTimetable& timetable) {
	char zzans = 's';
	do {
		system("cls");

		int zYear, zSemester;
		char zSection;
		int w;
		cout << "Enter Year (1 or 2): ";
		cin >> zYear;
		cout << "Enter Semester (1 or 2): ";
		cin >> zSemester;
		cout << "Enter Section (A, B, C, D, E): ";
		cin >> zSection;

		if (zYear < 1 || zYear > 2 || zSemester < 1 || zSemester > 2 || (zSection != 'A' && zSection != 'B' && zSection != 'C' && zSection != 'D' && zSection != 'E')) {
			cout << "Invalid input. Year must be 1 or 2, Semester must be 1 or 2, and Section must be A, B, C, D, or E." << endl;
			continue;
		}

		int zDay, zPeriod;
		string newSubject;

		cout << "\nEnter the Day (1-5): ";
		cin >> zDay;

		if (zDay < 1 || zDay > 5) {
			cout << "Invalid day input. Day must be between 1 and 5." << endl;
			continue;
		}

		cout << "Enter the Period (1-4): ";
		cin >> zPeriod;

		if (zPeriod < 1 || zPeriod > 4) {
			cout << "Invalid period input. Period must be between 1 and 4." << endl;
			continue;
		}

		cout << "Enter the Subject (3 or 4 alphabets): ";
		cin >> newSubject;

		// Update the subject of the class period in the timetable
		timetable.years[zYear - 1].semesters[zSemester - 1].section[zSection - 'A'].days[zDay - 1].periods[zPeriod - 1].subject = newSubject;

		// Display the updated timetable
		if (zSection == 'A') w = 1;
		if (zSection == 'B') w = 2;
		if (zSection == 'C') w = 3;
		if (zSection == 'D') w = 4;
		if (zSection == 'E') w = 5;
		cout << "Do another? (y/n): ";
		cin >> zzans;
	} while (zzans != 'n');
}


void saveArrayToFile(const string array[], const string& filename) {
	// Open a file for writing
	ofstream outputFile(filename);

	// Check if the file is open successfully
	if (!outputFile.is_open()) {
		cerr << "Error opening the file " << filename << std::endl;
		return;
	}

	// Write the array elements to the file
	for (int i = 0; i < 25; ++i) {
		outputFile << array[i] << endl;
	}

	// Close the file
	outputFile.close();
}
int checkInput(int i, int j)
{
	int switchin;
	do {
		cin >> switchin;
		if (!cin || (switchin < i || switchin > j)) {
			cout << "\t\t\t\t\tInvalid Input.. Try again.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}/* else if (switchin <']
					  i || switchin >j) {
			cout << "\t\t\t\t\tInvalid input. Try again.\n";
		}*/
	} while (switchin < i || switchin >j);
	return switchin;
}
string getDataWithSpaces() {
	string input;
	cin.ignore(); // Clear the input buffer
	getline(cin, input);
	return input;
}
string trim(const string& str) {
	size_t first = str.find_first_not_of(" \t");
	if (string::npos == first) {
		return str;
	}
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}









