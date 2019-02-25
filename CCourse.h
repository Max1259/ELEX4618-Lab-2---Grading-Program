#include "pch.h"
#include "CStudent.h"
#include <vector>

#ifndef CCOURSE_H
#define CCOURSE_H

using namespace std;

class CCourse {
	private:
		vector<CStudent> students_in_class;
	public:
		CCourse() {}
		~CCourse() {}
		void add_student();
		void edit_student();
		float final_grade(int n);
		void print_grades();
		void delete_student();
		void save_class();
		void load_class();
};

#endif // !CCOURSE_H
