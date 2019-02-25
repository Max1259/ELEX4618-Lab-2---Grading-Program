#include "stdafx.h"
#include "CCourse.h"
#include "CStudent.h"
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

void print_menu();

int main() {

	char command; //for add/edit/print/quit menu commands
	CCourse course;

	do {

		print_menu();
		cin >> command;
		cout << endl;

		switch (command) {

		case 'A':
		case 'a':
			course.add_student();
			break;

		case 'E':
		case 'e':
			course.edit_student();
			break;

		case 'P':
		case 'p':
			course.print_grades();
			break;

		case 'D':
		case 'd':
			course.delete_student();
			break;

		case 'S':
		case 's':
			course.save_class();
			break;

		case 'L':
		case 'l':
			course.load_class();
			break;

		default:
			cout << "Command unknown\n";
		}
		cout << endl;
	} while (command != 'q' & command != 'Q');

	return 0;
}

////////////////////////////////////////////////////////
//print menu function
//arguments/return: none
///////////////////////////////////////////////////////
void print_menu() {

	cout << "************************************" << endl
		<< "ELEX 4618 Grade System, by Max Horie" << endl
		<< "************************************" << endl
		<< "(A)dd student\n(E)dit student\n(P)rint grades\n(D)elete student\n(S)ave File\n(L)oad File\n(Q)uit\n\n";
}