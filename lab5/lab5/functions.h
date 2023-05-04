#pragma once
#include "classes.h"
#include <string>

using namespace std;

void fill_students_array(Student*& students, int n);

void calculate_scholarships_array(Student* students, int n);

void show_all_info_about_students(Student* students, int n);

void show_all_info_about_teachers(Teacher* teacher,int  m);

bool is_date_correct(string date);

void find_the_highest_paid_teacher(Teacher* teachers, int m);

Teacher* create_teachers_array(int m);