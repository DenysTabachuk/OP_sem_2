#pragma once
#include <string>

using namespace std;

struct lesson {
    char start_time[6]="";
    char end_time[6]="";
    char subject_name[20]="";
};

void enter_file_name(string& file_name);
void create_file(string& file_name);
void add_subjects_to_schedule(string& file_name, lesson* last_lesson);
void read_the_schedule(string& file_name, lesson* l);

