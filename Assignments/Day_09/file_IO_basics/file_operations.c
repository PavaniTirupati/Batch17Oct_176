// file_operations.c

#include "file_operations.h"

int read_integer_file(FILE *fptr, int *num) {
    if (fscanf(fptr, "%d", num) != 1) {
        return -1;  // Error reading integer from file
    }
    return 0;  // Success
}

int read_string_file(FILE *fptr, char *str) {
    if (fgets(str, 80, fptr) == NULL) {
        return -1;  // Error reading string from file
    }
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';
    return 0;  // Success
}

void write_to_output_file(FILE *fptr, int num, const char *str) {
    fprintf(fptr, "%d%s\n", num, str);
}

void display_merged_file(FILE *fptr) {
    rewind(fptr);  // Go to the start of the file
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fptr)) {
        printf("%s", buffer);
    }
}

