// file_operations.h

#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>

int read_integer_file(FILE *fptr, int *num);
int read_string_file(FILE *fptr, char *str);
void write_to_output_file(FILE *fptr, int num, const char *str);
void display_merged_file(FILE *fptr);

#endif // FILE_OPERATIONS_H

