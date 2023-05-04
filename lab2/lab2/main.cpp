#include <iostream>
#include <string>
#include <conio.h>
#include "BinaryFile.h"
    
using namespace std;




int main()
{
    lesson last_lesson;
    string file_name;
    char ch;

    enter_file_name(file_name);
    cout << "Do you want to open an existing schedule (+) or create a new one? (-)\n" << endl;
    do {
       ch = _getch();
        if (ch == '-')
            create_file(file_name);
      if (ch == '+')
            read_the_schedule(file_name, &last_lesson);
    } while (ch != '+' && ch != '-');


    do {
        add_subjects_to_schedule(file_name, &last_lesson);
        cout << "\n\nPress esc to stop, else enter\n\n";
    } while (_getch() != 27);

    read_the_schedule(file_name, &last_lesson);

    cout << "\nThat's all ? Do you want to complete the table? Press esc to exit, else enter" << endl;
    while (_getch() != 27) {
        add_subjects_to_schedule(file_name, &last_lesson);
        read_the_schedule(file_name, &last_lesson);
        cout << "\nThat's all ? Do you want to complete the table? Press esc to exit, else enter" << endl;
    }

    return 0;
}


