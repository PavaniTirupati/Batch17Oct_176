// main.c

#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"

#define MAX_STRING_LEN 80

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: Please provide exactly three file names as arguments.\n");
        return 1;
    }

    // Open the input files
    FILE *int_file = fopen(argv[1], "r");
    if (int_file == NULL) {
        perror("Error opening integer file");
        return 1;
    }

    FILE *str_file = fopen(argv[2], "r");
    if (str_file == NULL) {
        perror("Error opening string file");
        fclose(int_file);
        return 1;
    }

    // Open the output file
    FILE *out_file = fopen(argv[3], "w");
    if (out_file == NULL) {
        perror("Error opening output file");
        fclose(int_file);
        fclose(str_file);
        return 1;
    }

    int num;
    char str[MAX_STRING_LEN];

    // Merge the contents from the two input files into the output file
    while (read_integer_file(int_file, &num) == 0 && read_string_file(str_file, str) == 0) {
        write_to_output_file(out_file, num, str);
    }

    // Display the merged content
    printf("Merged File Content:\n");
    display_merged_file(out_file);

    // Close all files
    fclose(int_file);
    fclose(str_file);
    fclose(out_file);

    return 0;
}

