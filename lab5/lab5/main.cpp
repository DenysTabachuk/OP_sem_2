#define _CRT_SECURE_NO_WARNINGS
#include "classes.h"
#include "functions.h"
#include <iostream>


using namespace std;

int main() {
	int n, m;
	cout << "Enter the number of students - n and the number of teachers - m (n m):";
	cin >> n >> m;

	Student* students_array = new Student[n];
	fill_students_array(students_array, n);
	calculate_scholarships_array(students_array, n);
	show_all_info_about_students(students_array, n);

	Teacher* teachers_array = create_teachers_array(m);
	show_all_info_about_teachers(teachers_array, m);
	find_the_highest_paid_teacher(teachers_array, m);

	delete[] students_array;
	delete[] teachers_array;
}