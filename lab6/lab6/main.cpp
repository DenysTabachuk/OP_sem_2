#include <iostream>
#include "List.h"


using namespace std;



int main() {
    cout << "Enter the container type (\"int\", \"double\", \"string\", \"char\") or \"esc\" to exit:\n ";
    string type;
    cin >> type;
    bool validType = false;

    while (!validType) {
        if (type == "int") {
            DoublyLinkedList<int> list;
            menu(list); 
            break;
        }
        else if (type == "double") {
            DoublyLinkedList<double> list;
            menu(list);
            break;
        }
        else if (type == "string") {
            DoublyLinkedList<string> list;
            menu(list);
            break;
        }
        else if (type == "char") {
            DoublyLinkedList<char> list;
            menu(list);
            break;
        }
        else if (type == "esc") {
            return 0;
        }
        else {
            cout << "Unsupported container type" << endl;
        }
    }

    return 0;
}

