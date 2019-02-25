#include "pch.h"
#include <string>

#ifndef CSTUDENT_H
#define CSTUDENT_H

using namespace std;

class CStudent {
	private:
		string student_number;
		float lab_grade, quiz_grade, midterm_grade, final_exam_grade;
	public:
		CStudent() {}
		~CStudent() {}
		CStudent(string n, float l, float q, float m, float f);
		string getStudent();
		float getLab();
		float getQuiz();
		float getMidterm();
		float getFinal();
};

#endif // !CSTUDENT_H
