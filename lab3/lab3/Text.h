#pragma once
#include <string>

using namespace std;

class Text {
private:
    string text;
    string title;
public:
    Text(string title = "", string text = "") { 
        this->text = text;
        this->title = title;

    }
    ~Text() { 
    }

    void set_title(string entered_title);
    string get_title();
    void add_new_line(string new_text);
    float get_char_frequency(char c);
    int get_num_characters();
    string get_text();
};


void menu1(Text*& objetcs_array, int& num_texts);
void print_menu1(Text* objetcs_array, int num_texts);
void menu2(Text*& objetcs_array, int& num_texts, int which_text);
void print_menu2();
void print_info();
void add_text(Text*& objects_array, int& num_texts);
void increase_size(Text*& old_objects_array, int& size);
void find_most_frequent_character(Text* texts, int num_texts);