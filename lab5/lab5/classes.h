#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person
{
protected:
	string full_name;
	string date_of_birth;
	int age;
	float monthly_income;
public:
	void calculate_age();
	void calculate_monthly_income(int working_hours,float hourly_fee);
	void show_all_info();

	void set_monthly_income(float income);
	void set_full_name(string full_name);
	void set_date_of_birth(string date);

	string get_full_name();
	string get_date_of_birth();
	int get_age();
	float get_monthly_income();

	Person();
	~Person() {};
};


class Student : public Person
{
private:
	int group_number;
	float average_rating_score;
	string scholarship;
public:
	void set_group_number(int number);
	void set_average_rating_score(float rating_score);
	void set_scholarship(string scholarship_type);


	int get_group_number();
	float get_average_rating_score();
	string get_scholarship();

	void calculate_monthly_income();
	void calculate_scholarship();
	void show_all_info();

	Student();
	~Student(){}

};


class Teacher : public Person
{
private:
	int num_disciplines;
	int total_hours;
	int* num_hours_array;
	string *disciplines_array;	
public:	
	void calculate_monthly_income(float hourly_fee);
	void calculate_total_hours();
	void show_all_info();

	void set_disciplines(string* disciplines);
	void set_num_hours(int* hum_of_hours);
	void set_num_disciplines(int num);



	float get_salary();
	int get_num_disciplines();
	int* get_num_hours_array();
	string* get_disciplines_array();


	Teacher();
	Teacher(int num_disciplines);
	~Teacher();
};
