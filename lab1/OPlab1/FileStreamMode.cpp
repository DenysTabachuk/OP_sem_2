#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;


string get_filename() {
    string filename;
    cout << "\nEnter a file name" << endl;
    getline(cin, filename);
    return filename;
}


void write_to_file(string filename, char mode) {
    ofstream fout;
    if (mode == 'w')
        fout.open(filename);
    else
        fout.open(filename, ios::app);

    if (!fout.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        exit(1);
    }

    char ch;
    string input;
    cout << "\nEnter data to write to file: " << filename << " .Press ESC to stop." << endl;

    while ((ch = _getch()) != 27) {
        getline(cin, input);
        fout << input;
        fout << '\n';
    }
    fout.close();
}


void read_from_file(string filename) {
    ifstream fin;
    fin.open(filename);

    if (!fin.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        exit(1);
    }

    string line;
    cout << "\nNow file " << filename << " contents: " << endl;
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    cout << "\n\n\n" << endl;
    fin.close();
}


string remove_spaces(string line) {
    string no_space_line = "";
    for (int i = 0; i < size(line); i++) {
        if (line[i] != ' ')
            no_space_line += line[i];
    }
    return no_space_line;
}


int num_of_x(string line) {
    int counter = 0;
    for (int i = 0; i < size(line); i++) {
        if (line[i] == 'x')
            counter++;
    }
    return counter;
}


bool is_quadratic_equation(string line) {
    line = remove_spaces(line);
    int index;

    if ((index = line.find("x**2")) == -1) // перевіряємо наявінсть x^2
        return false;
    else if (1 > num_of_x(line) || num_of_x(line) > 2)//перевіряємо кількість 
        return false;
    else if (line.find("xx") != -1 || line.find("--") != -1 || line.find("++") != -1)
        return false;
    else if ((index = line.find("=0")) == -1 || index + 2 != size(line)) // перевіряємо наявність =0 та розташоване воно вкінці
        return false;
    else
        line.erase(index, 2);

    index = line.find("x**2");
    line.erase(index, 4);

    for (int i = 0; i < size(line); i++) {
        if (line[i] == 'x' && i + 1 < size(line) && isdigit(line[i + 1])) // перевіряє чи одразу після х не стоїть цифра, наприклад "x4"
            return false;

        if (!isdigit(line[i]) && line[i] != '+' && line[i] != '-' && line[i] != 'x') //перевціряю на символи, які не можуть бути  в квадратному рівнянні
            return false;
    }

    return true;
}


string* split(string line, int& arr_size) {
    string* words = new string[20];
    int index;
    arr_size = 0;
    while ((index = line.find_first_of(",.!? ")) != -1) {
        words[arr_size].insert(0, line, 0, index);

        arr_size++;
        line.erase(0, index + 1);
    }
    words[arr_size++] = line;
    return words;
}


void insertion_sort_str(string* arr, int size_arr) {
    for (int i = 1; i < size_arr; i++) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && size(arr[j]) < size(key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void sort_by_num_of_characters(string& line) {
    int arr_size;
    string* words = split(line, arr_size);
    insertion_sort_str(words, arr_size);
    line = "";
    for (int i = 0; i < arr_size; i++) {
        line = line + words[i] + " ";
    }
    while (line[0] == ' ') line.erase(0, 1);
}


void file_procesing(string filename1, string filename2) {
    ifstream fin;
    ofstream fout_eq, fout_new_file;

    fin.open(filename1);
    if (!fin.is_open()) {
        cout << "Unable to open file: " << filename1 << endl;
        exit(1);
    }

    fout_eq.open(filename2);
    if (!fout_eq.is_open()) {
        cout << "Unable to open file: " << filename2 << endl;
        exit(1);
    }

    string new_file_name = "new_file.txt";
    fout_new_file.open(new_file_name);
    if (!fout_new_file.is_open()) {
        cout << "Unable to create new file" << endl;
        exit(1);
    }


    string  line;

    while (getline(fin, line))
    {
        if (is_quadratic_equation(line)) {
            fout_eq << line << endl;
        }
        else {
            sort_by_num_of_characters(line);
        }
        fout_new_file << line << endl;
    }
    fin.close();
    fout_eq.close();
    fout_new_file.close();

    int result = remove(filename1.c_str());
    if (result == -1) {
        cout << "File deletion error" << endl;
        exit(1);
    }

    result = rename(new_file_name.c_str(), filename1.c_str());
    if (result == -1) {
        cout << "Rename error" << endl;
        exit(1);
    }
}


string find_coeff(string& line, string x) {
    string coeff = "";
    int index, start_index;
    index = start_index = line.find(x);


    if (start_index == 0) {
        coeff = "+1";
    }
    else {
        while (index != 0 && (line[index] != '-' && line[index] != '+')) {
            index--;
            coeff = line[index] + coeff;
        }
    }
    if (x == "x**2") start_index += 3;
    line.erase(index, start_index + 1 - index);

    if (coeff == "+") coeff = "+1";
    if (coeff == "-") coeff = "-1";
    if (coeff == "") coeff = "0";
    if (isdigit(coeff[0])) coeff.insert(0, "+");

    return coeff;
}


void leave_only_coefficients(string filename) {
    ifstream fin;
    ofstream fout, fout_new_file;
    fin.open(filename);
    string new_file_name = "new_file.txt";

    fout_new_file.open(new_file_name);

    if (!fin.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        exit(1);
    }

    if (!fout_new_file.is_open()) {
        cout << "Unable to create new file" << endl;
        exit(1);
    }

    string line, a, b, c;
    while (getline(fin, line))
    {
        line = remove_spaces(line);
        a = find_coeff(line, "x**2");
        line.find("x") == string::npos ? b = "0" : b = find_coeff(line, "x");
        line.erase(line.find("0") - 1, 2);
        line.empty() ? c = "0" : c = line;
        fout_new_file << a << "," << b << "," << c << endl;
    }

    fin.close();
    fout_new_file.close();

    int result = remove(filename.c_str());
    if (result == -1) {
        cout << "File creation error" << endl;
        exit(1);
    }

    result = rename(new_file_name.c_str(), filename.c_str());
    if (result == -1) {
        cout << "Rename error" << endl;
        exit(1);
    }
}

void print_info() {
    cout << "\t\t\t\tINFO" << endl;
    cout << "This program allows you to create 2 files. In the first, you will write down " << endl;
    cout << "some data. Then the program will process this file. If the string is a " << endl;
    cout << "quadratic equation, it will overwrite this equation in the second file." << endl;
    cout << "If the file is not a quadratic equation, it will sort the words in this line" << endl;
    cout << "in descending order of length. Then the program will process the 2nd file" << endl;
    cout << "and leave only the coefficients of the equation.\n\n\n" << endl;
}

