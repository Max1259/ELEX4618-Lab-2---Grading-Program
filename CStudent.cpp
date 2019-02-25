#include "pch.h"
#include "CStudent.h"
#include "CCourse.h"
#include <string>

using namespace std;

CStudent::CStudent(string n, float l, float q, float m, float f) {
	student_number = n;
	lab_grade = l;
	quiz_grade = q;
	midterm_grade = m;
	final_exam_grade = f;
}

string CStudent::getStudent() {
	return student_number;
}

float CStudent::getLab() {
	return lab_grade;
}

float CStudent::getQuiz() {
	return quiz_grade;
}

float CStudent::getMidterm() {
	return midterm_grade;
}

float CStudent::getFinal() {
	return final_exam_grade;
}