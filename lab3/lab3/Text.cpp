#include <iostream>
#include <string>
#include <iomanip>
#include "Text.h"


void increase_size(Text*& old_objects_array, int& size) {
    Text* new_objects_array = new Text[size + 1];
    for (int i = 0; i < size; i++) {
        new_objects_array[i] = old_objects_array[i];
    }
    delete[] old_objects_array;
    old_objects_array = new_objects_array;
    size++;
}


void add_text(Text*& objects_array, int& num_texts) {
    string title, text;
    cout << "Enter the title of the text:";
    getline(cin, title);
    cout << "\nEnter text:";
    getline(cin, text);
    increase_size(objects_array, num_texts);
    Text new_text(title,text);
    objects_array[num_texts - 1] = new_text;
}


void print_menu1(Text* objetcs_array, int num_texts) {
    cout << "\t\tMenu\n";

    for (int i = 0; i < num_texts; i++) {
        cout << i + 1 << ") " << "Work with " << setw(20) << left << objetcs_array[i].get_title() << endl;
        }

    cout << num_texts + 1 << ") Add new text\n";
    cout << num_texts + 2 << ") Find the symbol that occurs most often in texts\n";
    cout << num_texts + 3 << ") Exit\n";
}


void print_menu2() {
    cout << "1) Read the text\n";
    cout << "2) Add a new line\n";
    cout << "3) Find out the frequency of the symbol\n";
    cout << "4) Find out the number of characters in the text\n";
    cout << "5) exit\n";
}


void print_info() {
    cout << "\t\tInformation about the program\n\n"
        << "This program allows you to create texts, give them titles, add lines to texts,\n"
        << "determine the frequency of the appearance of a certain symbol in the text\n\n";
    system("pause");
}


void menu1(Text*& objects_array,int& num_texts) {
    int choice;
    while (true) {
        system("cls");
        print_menu1(objects_array, num_texts);
        cin >> choice;

        if (choice <= num_texts) {
            cout << "You chose " << objects_array[choice - 1].get_title() << endl;
            menu2(objects_array, num_texts, choice - 1);
        }
        else if (choice == num_texts + 1){
           cin.ignore();
           add_text(objects_array, num_texts);
        }
        else if (choice == num_texts + 2) {
            find_most_frequent_character(objects_array, num_texts);
        }
        else if (choice == num_texts + 3) {
            break;
        }
        else{
            cout << "There is no such menu item\n";
        }
    }
}       


void menu2(Text*& objetcs_array, int& num_texts, int which_text) {
    string str;
    char symbol;
    bool flag = true;
    int choice, num_chars;
    float frequency;

    while (flag) {
        system("cls");
        print_menu2();
        cin >> choice;
        switch (choice) {
        case 1:
            str = objetcs_array[which_text].get_text();
            cout << str << endl;
            break;
        case 2:
            cout << "\nEnter a new line\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, str);
            objetcs_array[which_text].add_new_line(str);
            break;
        case 3:
            cout << "\nThe frequency of which symbol you want to find\n";
            cin >> symbol;
            frequency = objetcs_array[which_text].get_char_frequency(symbol);
            cout << "\nFrequency of \"" << symbol << "\" = " << frequency << endl;
            break;
        case 4:
            num_chars = objetcs_array[which_text].get_num_characters();
            cout << "Total number of characters " << num_chars << endl;
            break;
        case 5:
            flag = false;
            break;
        default:
            cout << "\nThere is no such menu item\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.ignore();
        }
        system("pause");
    }
}



void find_most_frequent_character(Text* texts, int num_texts) {

    int frequency_table[256] = { 0 };     // ініціалізуємо таблицю частотності символів нулями
    for (int i = 0; i < num_texts; i++) {   // проходимось по кожному тексту у масиві
        string text = texts[i].get_text();    // отримуємо текст з поточного об'єкту
        for (int j = 0; j < text.length(); j++) {   // проходимось по кожному символу в тексті
            frequency_table[text[j]]++;     // збільшуємо частотну таблицю для поточного символу
        }
    }

    // знаходимо символ з найбільшою частотою
    char most_frequent_char ;
    int max_frequency = 0;
    for (int i = 0; i < 256; i++) {
        if (frequency_table[i] > max_frequency) {
            most_frequent_char = i;
            max_frequency = frequency_table[i];
        }
    }
    cout << "The most frequent symbol in texts: \"" << most_frequent_char << "\" \n";
    system("pause");
}
