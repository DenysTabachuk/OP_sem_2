#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "BinaryFile.h"


using namespace std;



void enter_file_name(string& file_name){
	cout << "Enter a file name: ";
	getline(cin, file_name);
}


void create_file(string& file_name) {
	ofstream file(file_name, ios::binary);
	file.close();
}


int count_time_difference(int hours1, int hours2, int minutes1, int minutes2) {
    return abs(hours1 * 60 + minutes1 - hours2 * 60 - minutes2);
}



void calculate_end_time(lesson* l){
    string hours_str = string(l->start_time).substr(0, 2);
    string minutes_str = string(l->start_time).substr(3, 2);

    int hours = stoi(hours_str);
    int minutes = stoi(minutes_str);

    hours++;
    minutes += 45;
    if (minutes > 59) {
        minutes -= 60;
        hours++;
    }
    hours_str = to_string(hours);
    minutes_str = to_string(minutes);
    if (hours < 10)  hours_str = "0" + hours_str;
    if (minutes < 10) minutes_str = "0" + minutes_str;

    string end_time = hours_str + ":" + minutes_str;
    strcpy(l->end_time, end_time.c_str());
}


int is_time_free(lesson* l) {
    if (l->end_time[0] == '\0') return 1;

    int start_hours = stoi(string(l->start_time).substr(0, 2));
    int start_minutes = stoi(string(l->start_time).substr(3, 2));
    int end_minutes = stoi(string(l->end_time).substr(3, 2));
    int end_hours = stoi(string(l->end_time).substr(0, 2));

    int time_difference=count_time_difference(start_hours, end_hours, start_minutes, end_minutes);
    if (start_hours < end_hours || (start_hours == end_hours && start_minutes <= (end_minutes ))) {
        cout << "It is not possible to set a lesson for this time" << endl;
        return 0;
    }
    else if (time_difference < 5) {
        cout << "The break cannot be shorter than 5 minutes" << endl;
        return 0;
    }
    else if (time_difference > 45) {
        cout << "The break cannot be longer than 45 minutes" << endl;
        return 0;
    }
    else {
        return 1;
    }
}


int is_time_correct(lesson* l) {
    if (strlen(l->start_time) < 4)
        return 0;
    else if (strlen(l->start_time) == 4) {
        char zero[6] = "0";
        strcat(zero, l->start_time);
        strcpy(l->start_time, zero);
    }

    if (l->start_time[2] != ':')
        return 0;

    char hours[3], minutes[3];
    strncpy(hours, l->start_time, 2);
    hours[2] = '\0'; // Додати символ кінця рядка до масиву hours
    strncpy(minutes, l->start_time + 3, 2);
    minutes[2] = '\0'; // Додати символ кінця рядка до масиву minutes

    int hour = atoi(hours);
    int minute = atoi(minutes);
    
    if (hour < 0 || hour >23 || minute < 0 || minute > 59)
        return 0;

    return 1;
}


void add_subjects_to_schedule(string& file_name, lesson* last_lesson) {
    ofstream file;
    file.open(file_name, ios::binary | ios::app);
    if (!file.is_open()) {
        cout << "Failed to open file for writing\n";
        return;
    }

    cout << "Enter the name of the subject you want to add to the schedule\n";
    cin.getline(last_lesson->subject_name, 20);

    cout << "Now enter the class start time:\n";

    do {
        cin.getline(last_lesson->start_time, 6);
        while (!is_time_correct(last_lesson)) {
            cout << "The time entered is incorrect, try again\n";
            cin.getline(last_lesson->start_time, 6);
        }
    } while (!is_time_free(last_lesson));
    calculate_end_time(last_lesson);

    file.write(reinterpret_cast<char*>(last_lesson), sizeof(lesson));

    file.close();
}


void read_the_schedule(string& file_name, lesson* l) {
    ifstream file(file_name, ios::binary);
    cout << "\n\n\tSchedule\n\n";
    while (file.read((char*)l, sizeof(lesson))) {
        cout << setw(30)<< left << l->subject_name << setw(8) << l->start_time << setw(8) << l->end_time << endl;
    }
    file.close();
}