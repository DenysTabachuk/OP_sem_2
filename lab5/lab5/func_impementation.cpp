#include "functions.h"
#include <iostream>

using namespace std;

void fill_students_array(Student*& students, int n) {
    string full_name, date_of_birth;
    int group_number;
    float average_rating_score;

  
    for (int i = 0; i < n; i++) {
        cout << "\n\n\nEnter the student's full name:";
        cin.ignore();
        getline(cin, full_name);
      
   
        do {
            cout << "\nEnter the student's date of birth (in format DD.MM.YYYY):";
            cin >> date_of_birth;
        } while (!is_date_correct(date_of_birth)); 
      

        cout << "\nEnter the group number:";
        cin >> group_number;
        while (group_number < 0) {
            cout << "Invalid input. Please enter a positive integer value:";
            cin >> group_number;
        }
        

        cout << "\nEnter the student's average rating score (from 0 to 100):";
        cin >> average_rating_score;
        while (average_rating_score < 0 || average_rating_score > 100) {
            cout << "Invalid input. Please enter a value between 0 and 100:";
            cin >> average_rating_score;
        }



        students[i].set_full_name(full_name);
        students[i].set_date_of_birth(date_of_birth);
        students[i].set_group_number(group_number);
        students[i].set_average_rating_score(average_rating_score);
        students[i].calculate_scholarship();
        students[i].calculate_age();
        students[i].calculate_monthly_income();
    }
}


void calculate_scholarships_array(Student* students, int n) {
	for (int i = 0; i < n; i++) {
		students[i].calculate_scholarship();
	}
}


void show_all_info_about_students(Student* students, int n) {
    cout << "\n\t\t\tStudents info\n";
	for (int i = 0; i < n; i++) {
		cout << "--------------------------------\n";
		students[i].show_all_info();
	}
    cout << "\n\n\n";
}


void show_all_info_about_teachers(Teacher* teachers, int  m){
    cout << "\n\n\t\t\tTeacher\n";
    for (int i = 0; i < m; i++) {
        cout << "--------------------------------\n";
        teachers[i].show_all_info();
    }
    cout << "\n\n\n";
} 


bool is_date_correct(string date) {
    
    if (date.length() != 10 || date[2] != '.' || date[5] != '.') {
        cout << "\nIncorrect format. Try again.\n";
        return false;
    }

 
    string day_str = date.substr(0, 2);
    string month_str = date.substr(3, 2);
    string year_str = date.substr(6, 4);

   
    int day = stoi(day_str);
    int month = stoi(month_str);
    int year = stoi(year_str);

   
    if (month < 1 || month > 12) {
        cout << "\nInvalid month. Try again.\n";
        return false;
    }

   
    int max_day = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        max_day = 30;
    }
    else if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            max_day = 29;
        }
        else {
            max_day = 28;
        }
    }
    if (day < 1 || day > max_day) {
        cout << "\nInvalid day. Try again.\n";
        return false;
    }

    return true;
}


Teacher* create_teachers_array(int m) {
    string full_name, date_of_birth;
    int num_of_subjects;
    float hourly_fee;
    
    Teacher* teachers = new Teacher[m];

    cout << "Enter the teacher's salary per hour:";
    cin >> hourly_fee;

   

    for (int i = 0; i < m; i++) {
        cout << "\nEnter the teacher's full name:";
        cin.ignore();
        getline(cin, full_name);
    
        do {
            cout << "\nEnter the teacher's date of birth: ";
            cin >> date_of_birth;
        } while (!is_date_correct(date_of_birth));
      


        cout << "\nEnter the number of subjects taught by the teacher: ";
        cin >> num_of_subjects;
     
    
     
        string* disciplines = new string[num_of_subjects];
        int* num_of_hours = new int[num_of_subjects];

        for (int j = 0; j < num_of_subjects; j++) {
            cout << "\nEnter the name of the discipline: ";
            cin.ignore();
            getline(cin, disciplines[j]);

            cout << "\nEnter number of hours per month: ";
            cin >> num_of_hours[j];
        }


        teachers[i].set_full_name(full_name);
        teachers[i].set_date_of_birth(date_of_birth);
        teachers[i].set_num_disciplines(num_of_subjects);
        teachers[i].set_disciplines(disciplines);
        teachers[i].set_num_hours(num_of_hours);
        teachers[i].calculate_monthly_income(hourly_fee);
        teachers[i].calculate_age();
    }

    return teachers;
}


void find_the_highest_paid_teacher(Teacher* teachers, int m){
    float max = teachers[0].get_monthly_income();
    int index = 0;
    for (int i = 1; i < m; i++) {
        if (max < teachers[i].get_monthly_income()) {
            max = teachers[i].get_monthly_income();
            index = i;
        }
    }
    
    cout << teachers[index].get_full_name() << " has the highest monthly salary "
        << teachers[index].get_monthly_income() << " UAH\n"
        << "Teacher's age " << teachers[index].get_age() << endl;
}


