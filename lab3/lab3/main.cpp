#include <iostream>
#include "Text.h"

using namespace std;


int main() {
    int num_texts = 0;
    Text* objects_array = new Text[num_texts];
    print_info();
    menu1(objects_array, num_texts);
    delete[] objects_array;
    return 0;
}