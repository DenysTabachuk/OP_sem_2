#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;


void FP_enter_file_name(char* filename) {
	cout << "Enter a file name" << endl;
	cin.getline(filename, 200);
}


void FP_file_is_open(FILE* fp, char* filename) {
	if (fp == NULL)
	{
		cout << "Can't open the file " << filename << endl;
		exit(1);
	}
}


void FP_write_or_add_to_file(const char* filename, const char* mode) {
	FILE* fp;
	fp = fopen(filename, mode);
	cout << "Make notes below. Press ESC to stop." << endl;
	char row[200];
	while (true) {

		int esc = _getch();
		if (esc == 27)
			break;

		cin.getline(row, 200);
		fprintf(fp, "%s\n", row);

	}
	fclose(fp);
}


void FP_read_file(char* filename) {
	FILE* fp = fopen(filename, "r");
	FP_file_is_open(fp, filename);

	cout << "Reading the file: " << filename << "\n" << endl;
	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		cout << ch;
	}
	cout << "\n\n" << endl;
	fclose(fp);
}


char* FP_str_delete_spaces(char* str) {
	int lengh = strlen(str);
	int num_spaces = 0;
	for (int i = 0; i < lengh; i++) {
		if (str[i] == ' ') {
			num_spaces++;
			for (int j = i; j < lengh - 1; j++) {
				str[j] = str[j + 1];
			}
		}
	}
	str[lengh - num_spaces] = '\0';
	return str;
}


int FP_count_num_of(char* str, char symbol, int lenght) {
	int counter = 0;
	for (int i = 0; i < symbol; i++) {
		if (str[i] == symbol)
			counter++;
	}
	return counter;
}


int FP_is_quadratic_equation(char* str) {
	char equation[200];

	char term1[10], term2[10], term3[10];
	int num;
	strcpy(equation, str);
	strcpy(equation, FP_str_delete_spaces(equation));
	int lenght = strlen(equation);

	char* ptr = strstr(equation, "x**2");
	if (ptr == NULL) {
		return 0;
	}
	else if (ptr - equation == 0) {
		num = sscanf(equation, "x**2%[^x]x%[^=]=0", term2, term3);
		if (num != 2)
			return 0;
	}
	else {
		num = sscanf(equation, "%[^x]x**2%[^x]x%[^=]=0", term1, term2, term3);
		if (num != 3)
			return 0;
	}


	ptr = strstr(equation, "=0");
	if (ptr == NULL || ptr - equation != lenght - 2)
		return 0;

	for (int i = 0; i < lenght; i++) {
		if (!strchr("+-x*2=", equation[i]) && !isdigit(equation[i]))
			return 0;
	}

	if (strstr(equation, "xx") || strstr(equation, "++") || strstr(equation, "--") || strstr(equation, "+-") || strstr(equation, "-+"))
		return 0;

	if (FP_count_num_of(equation, '*', lenght) > 2 || FP_count_num_of(equation, '=', lenght) > 1 || FP_count_num_of(equation, 'x', lenght) > 2)
		return 0;

	return 1;
}


void FP_insertion_sort(char** str, int n) {
	int i, j;
	char* key;
	for (i = 1; i < n; i++) {
		key = str[i];
		j = i - 1;
		while (j >= 0 && strlen(str[j]) < strlen(key)) {
			str[j + 1] = str[j];
			j = j - 1;
		}
		str[j + 1] = key;
	}
}


int FP_split_string(char* str, char** words, int max_words) {
	const char* delims = " \t\n,.?!-";
	char* word = strtok(str, delims);
	int count = 0;
	while (word != nullptr && count < max_words) {
		words[count] = word;
		++count;
		word = strtok(nullptr, delims);
	}
	return count;
}


void FP_connet_the_words(char* sorted_str, char** words, int count) {
	int pos = 0;
	for (int i = 0; i < count; i++) {
		strcpy(&sorted_str[pos], words[i]);
		pos += strlen(words[i]);
		int nextPos = pos;
		while (sorted_str[nextPos] == ' ') { // äîäàòè íàñòóïíèé ñèìâîë, ÿêùî öå íå ðîçä³ëüíèê
			sorted_str[pos] = sorted_str[nextPos];
			pos++;
			nextPos++;
		}
		sorted_str[pos] = ' '; // äîäàòè ïðîá³ë ï³ñëÿ ñëîâà
		pos++;
	}
	sorted_str[pos - 1] = '\0'; // çàì³íèòè îñòàíí³é ïðîá³ë íóëü-ñèìâîëîì


}


void FP_sort_words_by_length(char* str) {
	char* word;
	char* words[100];
	char sorted_str[200];
	int count = FP_split_string(str, words, 100); // ðîçáèâàþ ðÿäîê íà ñëîâà
	FP_insertion_sort(words, count); // â³ñäîðòóâàòè ñëîâà
	FP_connet_the_words(sorted_str, words, count); // çíîâó ðîáëþ ðÿäîê ç³ ñë³â
	strcpy(str, sorted_str);
}


void FP_find_quadraic_equation(char* filename1, char* filename2) {
	FILE* fp = fopen(filename1, "r");
	FILE* fp_eq = fopen(filename2, "w");
	FILE* fp_new = fopen("new_file.txt", "w");

	char str[200];

	FP_file_is_open(fp, filename1);
	FP_file_is_open(fp_eq, filename2);

	while (fgets(str, 200, fp) != NULL) {

		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = '\0';

		if (FP_is_quadratic_equation(str)) {
			fputs(str, fp_eq);
			fputc('\n', fp_eq);
		}
		else {
			FP_sort_words_by_length(str);
		}
		fputs(str, fp_new);
		fputc('\n', fp_new);
	}
	fclose(fp);
	fclose(fp_eq);
	fclose(fp_new);

	int result = remove(filename1);
	if (result == -1) {
		cout << "Error deleting file" << endl;
		exit(1);
	}

	result = rename("new_file.txt", filename1);
	if (result == -1) {
		cout << "Error renaming file" << endl;
		exit(1);
	}
}


void FP_leave_only_coeffs(char* filename) {
	FILE* fp = fopen(filename, "r");
	FILE* fp_new = fopen("new_file.txt", "w");
	FP_file_is_open(fp, filename);
	FP_file_is_open(fp_new, filename);

	char str[20], term1[10], term2[10], term3[10];
	int num;

	while (fgets(str, 20, fp) != NULL) {
		strcpy(str, FP_str_delete_spaces(str));

		char* ptr = strstr(str, "x**2");
		if (ptr - str == 0) {
			num = sscanf(str, "x**2%[^x]x%[^=]=0", term2, term3);
			strcpy(term1, "+1");

		}
		else {
			num = sscanf(str, "%[^x]x**2%[^x]x%[^=]=0", term1, term2, term3);
		}

		if (!strcmp(term1, "-"))
			strcpy(term1, "-1");
		if (isdigit(term1[0])) {
			char new_str[20] = "+";
			strcat(new_str, term1);
			strcpy(term1, new_str);
		}

		if (!strcmp(term2, "-"))
			strcpy(term2, "-1");
		if (!strcmp(term2, "+"))
			strcpy(term2, "+1");

		fputs(term1, fp_new);
		fputc(',', fp_new);
		fputs(term2, fp_new);
		fputc(',', fp_new);
		fputs(term3, fp_new);
		fputc('\n', fp_new);
	}

	fclose(fp_new);
	fclose(fp);

	int result = remove(filename);
	if (result == -1) {
		cout << "Error deleting file" << endl;
		exit(1);
	}

	result = rename("new_file.txt", filename);
	if (result == -1) {
		cout << "Error renaming file" << endl;
		exit(1);
	}
}

