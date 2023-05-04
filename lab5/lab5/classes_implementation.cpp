#define _CRT_SECURE_NO_WARNINGS

#include "classes.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <Windows.h>


using namespace std;


//Person
void Person::set_full_name(string full_name) {
	this->full_name = full_name;
}

void Person::set_date_of_birth(string date) {
	date_of_birth = date;
}

void Person::set_monthly_income(float income) {
	monthly_income = income;
}



string Person::get_date_of_birth() {
	return date_of_birth;
}

string Person::get_full_name() {
	return full_name;
}

int Person::get_age() {
	return age;
}

float Person::get_monthly_income(){
	return monthly_income;
}




void Person::calculate_monthly_income(int working_hours, float hourly_fee) {
	monthly_income = working_hours * hourly_fee;
}

void Person::calculate_age() {
	SYSTEMTIME current_date;
	GetSystemTime(&current_date);

	int year, month, day;
	sscanf(date_of_birth.c_str(), "%d.%d.%d", &day, &month, &year);

	int years = current_date.wYear - year;

	int months = current_date.wMonth + (12 - month);
	if (months < 12)
		years--;

	if (months >= 12)
		months -= 12;
	
	age = years;
}

void Person::show_all_info() {
	cout << "Full name: " << get_full_name() << endl;
	cout << "Date of bitrh: " << get_date_of_birth() << endl;
	cout << "Salary :" << monthly_income << endl;
}


Person::Person() {
	full_name = "name not entered";
	date_of_birth = "no date entered";
	monthly_income = 0;
	age = 0;
}






//Student

void Student::set_group_number(int number) {
	group_number = number;
}

void Student::set_average_rating_score(float rating_score) {
	average_rating_score = rating_score;
}

void Student::set_scholarship(string scholarship_type) {
	scholarship = scholarship_type;
}



int Student::get_group_number() {
	return group_number;
}

float Student::get_average_rating_score() {
	return average_rating_score;
}

string Student::get_scholarship() {
	return scholarship;
}


void Student::calculate_monthly_income() {
	if (scholarship == "not calculated" || scholarship == "missing") {
		monthly_income = 0;
	}
	else if (scholarship == "increased") {
		monthly_income = 2700;
	}
	else if (scholarship == "regular") {
		monthly_income = 2000;
	}
}

void Student::calculate_scholarship() {
	if (average_rating_score >= 95)
		scholarship = "increased";
	else if (85 <= average_rating_score && average_rating_score < 95)
		scholarship = "regular";
	else
		scholarship = "missing";
}

void Student::show_all_info() {
	cout << "Full name: " << get_full_name() << endl;
	cout << "Date of bitrh: " << get_date_of_birth() << endl;
	cout << "Age: " << get_age() << endl;;
	cout << "Group number: " << get_group_number() << endl;
	cout << "Average rating score: " << get_average_rating_score() << endl;
	cout << "Scholarship: " << get_scholarship() << " " << get_monthly_income() << endl;
}

Student::Student() {
	group_number = 0;
	average_rating_score = 0;
	scholarship = "Not calculated";
}










//Teacher

void Teacher::calculate_monthly_income(float hourly_fee) {
	if (num_hours_array != nullptr) {
		for (int i = 0; i < num_disciplines; i++) {
			monthly_income += num_hours_array[i] * hourly_fee;
		}
	}
	else {
		monthly_income = 0;
	}
}

void Teacher::show_all_info() {
	cout << "Full name: " << get_full_name() << endl;
	cout << "Date of bitrh: " << get_date_of_birth() << endl;
	cout << "Age: " << get_age() << endl;
	for (int i = 0; i < num_disciplines; i++) {
		cout << disciplines_array[i] << " : " << num_hours_array[i] << endl;

	}
	cout << "Salary :" << monthly_income << endl;
}

void Teacher::calculate_total_hours(){
	total_hours = 0;
	if (num_hours_array != nullptr) {
		for (int i = 0; i < num_disciplines; i++) {
			total_hours += num_hours_array[i];
		}
	}
}



void Teacher::set_disciplines(string* disciplines) {
	// виділення пам'яті для disciplines_array
	disciplines_array = new string[num_disciplines];
	for (int i = 0; i < num_disciplines; i++) {
		disciplines_array[i] = disciplines[i];
	}
}

void Teacher::set_num_hours(int* hum_of_hours) {
	num_hours_array = new int[num_disciplines];
	for (int i = 0; i < num_disciplines; i++) {
		num_hours_array[i] = hum_of_hours[i];
	}
}

void Teacher::set_num_disciplines(int num) {
	num_disciplines = num;
}



int Teacher::get_num_disciplines() {
	return num_disciplines;
}

int* Teacher::get_num_hours_array() {
	return num_hours_array;
}

string* Teacher::get_disciplines_array() {
	return disciplines_array;
}




Teacher::Teacher()
{
	num_disciplines = 0;
	total_hours = 0;
	num_hours_array = nullptr;
	disciplines_array = nullptr;
}

Teacher::Teacher(int num_disciplines) {
	if (num_disciplines < 0) {
		cout << "\nError, unable to create array with dimension less than 0.\n";
		exit(1);
	}

	this->num_disciplines = num_disciplines;
	disciplines_array = new string[num_disciplines];
	num_hours_array = new int[num_disciplines];

	num_disciplines = 0;
	total_hours = 0;
	monthly_income = 0;

	for (int i = 0; i < num_disciplines; i++) {
		disciplines_array[i] = "";
		num_hours_array[i] = 0;
	}
}

Teacher::~Teacher() {
	if (disciplines_array != nullptr) {
		delete[] disciplines_array;
	}
	if (num_hours_array != nullptr) {
		delete[] num_hours_array;
	}
}
