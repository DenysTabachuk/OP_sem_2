#pragma once
#include <string>

using namespace std;

int num_of_x(string line);
bool is_quadratic_equation(string line);
void write_to_file(string filename, char mode);
void read_from_file(string filename);
void file_procesing(string filename1, string filename2);
void print_info();
void  insertion_sort_str(string* arr, int size_arr);
void leave_only_coefficients(string filename);
string get_filename();
string remove_spaces(string line);
string find_coeff(string& line, string x);
string* split(string line, int& arr_size);
