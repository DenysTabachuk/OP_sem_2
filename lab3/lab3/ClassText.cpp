#include <iostream>
#include <string>
#include "Text.h"


float Text::get_char_frequency(char c) {
    int total_chars = text.length();
    int num_characters = 0;

    for (int i = 0; i < total_chars; i++) {
        if (text[i] == c) {
            num_characters++;
        }
    }
    return (total_chars > 0) ? ((float)num_characters / total_chars) : 0;
}


int Text::get_num_characters() {
    return text.length();

}



void Text::add_new_line(string new_text) {
    text += "\n" + new_text;
}


void Text::set_title(string entered_title) {
    title = entered_title;
}


string Text::get_text() {
    if (text.empty())
        cout << "The text is empty.\n";

    return text;
}


string Text::get_title() {
    {
        return title;
    }
}