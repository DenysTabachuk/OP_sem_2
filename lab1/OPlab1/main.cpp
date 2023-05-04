#include <iostream>
#include <string>
#include <conio.h>
#include "FilePointerMode.h"
#include "FileStreamMode.h"

using namespace std;

int main(int argc, char** argv) {

	if (argc == 2) {
		if (!strcmp(argv[1], "-mode FilePointer")) {
			cout << "You chose FilePointer modå\n\n\n" << endl;
			print_info();
			char filename1[20];
			char filename2[20];
			FP_enter_file_name(filename1);
			FP_enter_file_name(filename2);
			FP_write_or_add_to_file(filename1, "w");
			while (true) {
				FP_read_file(filename1);
				FP_find_quadraic_equation(filename1, filename2);
				FP_read_file(filename1);
				FP_read_file(filename2);
				FP_leave_only_coeffs(filename2);
				FP_read_file(filename2);
				cout << "That's all ? or maybe you want to add something to the file with records?" << endl;
				cout << "Press \"esc\" to exit, else press \"enter\"" << endl;
				if (int ch = _getch() == 27)
					break;
				FP_write_or_add_to_file(filename1, "a");
			}
		}
		else if (!strcmp(argv[1], "-mode FileStream")) {
			cout << "You chose FileStream mode\n\n\n" << endl;

			print_info();
			string filename1 = get_filename();
			string filename2 = get_filename();
			write_to_file(filename1, 'w');
			while (true) {
				read_from_file(filename1);
				file_procesing(filename1, filename2);
				read_from_file(filename2);
				leave_only_coefficients(filename2);
				read_from_file(filename1);
				read_from_file(filename2);
				cout << "That's all ? or maybe you want to add something to the file with records?" << endl;
				cout << "Press \"esc\" to exit, else press \"enter\"" << endl;
				if (int ch = _getch() == 27)
					break;
				write_to_file(filename1, 'a');
			}
		}
		else {
			cout << "Such parameters do not exist. Try \"-mode FilePointer\" \nor \"-mode FileStream\"" << endl;
		}
	}
	else {
		cout << "Error. Try running the program with parameter \"-mode FilePointer\" \nor \"-mode FileStream\"" << endl;
	}

	return 0;
}
