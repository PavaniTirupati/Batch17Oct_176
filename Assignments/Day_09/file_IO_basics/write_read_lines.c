#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 80

// Function to write a line to the file
int write(FILE *fptr, char *line) {
    if (fptr == NULL || line == NULL) {
        return -1;  // Error: invalid file pointer or line
    }

    // Write the line to the file and return success
    fprintf(fptr, "%s\n", line);
    return 0;  // Success
}

// Function to read a line from the file
int read(FILE *fptr, char *linebuf) {
    if (fptr == NULL || linebuf == NULL) {
        return -1;  // Error: invalid file pointer or buffer
    }

    // Read the line from the file and return success
    if (fgets(linebuf, MAX_LINE_LENGTH, fptr) != NULL) {
        return 0;  // Success
    }
    
    return -1;  // Error: unable to read from file
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        // Validate the number of arguments
        printf("Error: Please provide exactly two lines of text as command-line arguments.\n");
        return 1;
    }

    // Open the file for writing
    FILE *fptr = fopen("fout.txt", "w");
    if (fptr == NULL) {
        printf("Error: Unable to open fout.txt for writing.\n");
        return 1;
    }

    // Write the two lines to the file
    if (write(fptr, argv[1]) != 0 || write(fptr, argv[2]) != 0) {
        printf("Error: Failed to write to the file.\n");
        fclose(fptr);
        return 1;
    }

    fclose(fptr);
    printf("Data successfully written to fout.txt\n");

    // Open the file for reading
    fptr = fopen("fout.txt", "r");
    if (fptr == NULL) {
        printf("Error: Unable to open fout.txt for reading.\n");
        return 1;
    }

    char linebuf[MAX_LINE_LENGTH];
    printf("\nReading data from fout.txt:\n");

    // Read and display the content of the file
    while (read(fptr, linebuf) == 0) {
        printf("%s", linebuf);
    }

    fclose(fptr);

    return 0;
}

