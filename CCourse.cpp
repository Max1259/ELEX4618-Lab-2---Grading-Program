#include "pch.h"
#include "CCourse.h"
#include "CStudent.h"
#include <iostream>
#include <fstream>
#include <iomanip>

string getString();
float getFloat(string getnum);

using namespace std;

string number, filename, l, q, m, f;
float lab, quiz, midterm, final_exam;

//////////////////////////////////////////////////////
//add student function
//arguments/return: none
//////////////////////////////////////////////////////
void CCourse::add_student() {

	number = getString();

	cout << "Lab Grade: ";
	lab = getFloat(l);
	
	cout << "Quiz Grade: ";
	quiz = getFloat(q);
	
	cout << "Midterm Grade: ";
	midterm = getFloat(m);
	
	cout << "Final Exam Grade: ";
	final_exam = getFloat(f);

	CStudent newStudent(number, lab, quiz, midterm, final_exam);
	students_in_class.push_back(newStudent);
}

/////////////////////////////////////////////////////
//edit student funtion
//agruments/return: none
/////////////////////////////////////////////////////
void CCourse::edit_student() {
	
	int num;
	cout << "Student to Edit: ";
	cin >> num;
	num--;

	number = getString();

	cout << "Lab Grade: ";
	lab = getFloat(l);

	cout << "Quiz Grade: ";
	quiz = getFloat(q);

	cout << "Midterm Grade: ";
	midterm = getFloat(m);

	cout << "Final Exam Grade: ";
	final_exam = getFloat(f);

	CStudent newStudent(number, lab, quiz, midterm, final_exam);
	students_in_class.at(num) = newStudent;	
}

///////////////////////////////////////////////////////////
//final grade calc
//arguments: int num for student
//return: float
//////////////////////////////////////////////////////////
float CCourse::final_grade(int n) {

	return ((students_in_class[n].getLab() * 0.4) + (students_in_class[n].getQuiz() * 0.1) + 
		(students_in_class[n].getMidterm() * 0.2) + (students_in_class[n].getFinal() * 0.3));
}

//////////////////////////////////////////////////
//print grades function
//arguments/return: none
/////////////////////////////////////////////////
void CCourse::print_grades() {

	cout << setw(3) << left << "#" << setw(12) << left << "Student"
		<< setw(8) << left << "Lab" << setw(10) << left << "Quiz"
		<< setw(10) << left << "Midterm" << setw(15) << left << "Final Exam"
		<< setw(10) << left << "Final Grade" << endl;

	for (unsigned int i = 0; i < students_in_class.size(); i++) {

		cout << setw(3) << left << i + 1 << setw(12) << left << students_in_class[i].getStudent();

		cout.precision(2);

		cout << fixed << setw(8) << left << students_in_class[i].getLab()
			<< setw(10) << left << students_in_class[i].getQuiz()
			<< setw(10) << left << students_in_class[i].getMidterm()
			<< setw(15) << left << students_in_class[i].getFinal()
			<< setw(10) << left << final_grade(i) << endl;
	}
	cout << endl;
}

//////////////////////////////////////////
//Delete student function
//////////////////////////////////////////
void CCourse::delete_student() {
	while (1) {

		string num;
		int check;
		cout << "Student to Delete: ";
		cin >> num;

		if (!num.find_first_not_of("0123456789")) {
			cout << "Error: Enter a number" << endl;
		}
		else {
			check = stoi(num.c_str(), 0);
			check--;

			if (check + 1 > students_in_class.size() | check < 0) {

				cout << "Student does not exist" << endl;

			}
			else {

				students_in_class.erase(students_in_class.begin() + check);
				break;
			}
		}

	}
}
//////////////////////////////////////////
//Save class function
//////////////////////////////////////////
void CCourse::save_class() {

	cout << "Name of file to save: ";
	cin >> filename;
	ofstream class_file(filename);
	
	for (unsigned int i = 0; i < students_in_class.size(); i++) {
		
		class_file << students_in_class[i].getStudent() << ' ' 
			<< students_in_class[i].getLab() << ' '
			<< students_in_class[i].getQuiz() << ' '
			<< students_in_class[i].getMidterm() << ' '
			<< students_in_class[i].getFinal() << endl;
	}
	cout << "File Saved!" << endl;
	class_file.close();
}

//////////////////////////////////////////
//Load class function
//////////////////////////////////////////
void CCourse::load_class() {
	
	students_in_class.clear();
	ifstream class_file;

	while (1) {
		cout << "Name of file to load: ";
		cin >> filename;

		class_file.open(filename);

		if (class_file.is_open()) {
			cout << "File loaded!" << endl;
			break;
		}
		else {
			cout << "File not found, try again" << endl;
		}
	}

	while (class_file >> number >> lab >> quiz >> midterm >> final_exam) {

		CStudent newStudent(number, lab, quiz, midterm, final_exam);
		students_in_class.push_back(newStudent);
	}
	
	class_file.close();
}

//////////////////////////////////////////////////////////////
//String error checking 
//arguments: none
//return string if it is 9 characters starting with A00 or A01
//////////////////////////////////////////////////////////////
string getString() {

	string n;

	while (1) {

		cout << "Student Number: ";
		cin >> n;

		int failure = 0;

		if (n.size() == 9) {

			if (n[0] == 'A' & n[1] == '0' & (n[2] == '0' | n[2] == '1')) {

				for (unsigned int i = 3; i < 9; i++) {

					if (n[i] < '0' | n[i] > '9') {

						failure++;
					}
				}
			}
			else {
				failure++;
			}
		}
		else {
			failure++;
		}

		if (failure > 0) {

			cout << "Student numbers must begin with 'A0' followed by either 0 or 1 and 6 additional numbers" << endl;
		}
		else {
			return n;
		}
	}
}

//////////////////////////////////////////////////////
//float error checking function
//arguments: float
//return value: float if error checking passed
/////////////////////////////////////////////////////
float getFloat(string getnum) {

	float checked_value;
	int failure = 0;

	while (1) {

		cin >> getnum;

		for (unsigned int i = 0; i < getnum.size(); i++) {

			if ((getnum[i] < '0' | getnum[i] > '9') & getnum[i] != '.') {

				failure++;
			}
		}
		
		if (failure > 0) {

			cout << "Error: Enter a number between 0 and 100: ";
			failure = 0;

		} 
		else {

			checked_value = strtof(getnum.c_str(), 0);

			if (checked_value < 0 | checked_value > 100) {

				cout << "Error: Enter a number between 0 and 100: ";
			}
			else {
				return checked_value;
			}
		}
	} 
}