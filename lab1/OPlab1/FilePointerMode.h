#pragma once
#include <cstdio>

void FP_enter_file_name(char* filename);
void FP_file_is_open(FILE* fp, char* filename);
void FP_write_or_add_to_file(const char* filename, const char* mode);
void FP_read_file(char* filename);
void  FP_leave_only_coeffs(char* filename);
void FP_sort_words_by_length(char* str);
void FP_build_sorted_string(char** words, int word_count, char* sorted_str, int max_len);
void FP_find_quadraic_equation(char* filename1, char* filename2);
char* FP_str_delete_spaces(char* str);
int FP_is_quadratic_equation(char* str);

