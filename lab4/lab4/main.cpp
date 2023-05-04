#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;


int main() {
    print_info();

    vector B1 = create_vector_with_parameters();

    vector B2 = create_vector_with_default_constructor();

    vector B3 = create_vector_with_copy_constructor(B1);

    increment_polar_angle(B1);

    if (B2 != B3) {
        cout << "\n\n\nVectors B2 and B3 are non-collinear.\n";
    }
    else {
        cout << "\n\n\nVectors  B2 and B3 are collinear.\n";
    }
    return 0;
}