#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 80
#define FAILURE -1
#define SUCCESS 0

// Function to read strings from the file and store them in dynamic memory
int getFileString(char ***text, char *input) {
    FILE *fp;
    int textCount = 0;
    int len = 0;
    char buff[MAX_SIZE];

    fp = fopen(input, "r");

    if (fp != NULL) {
        // Allocate memory for an array of char* (pointers to strings)
        *text = (char **)malloc(sizeof(char*) * (MAX_SIZE + 1));
        if (*text != NULL) {
            while (fgets(buff, MAX_SIZE, fp) != NULL) {
                len = strlen(buff) + 1;
                // Allocate memory for each string (len+1 to include '\0')
                (*text)[textCount] = (char *)malloc(sizeof(char) * len);
                if ((*text)[textCount] != NULL) {
                    // Copy the string into the allocated memory
                    strcpy((*text)[textCount], buff);
                    len -= 2;  // Remove the newline character from the string
                    if (((*text)[textCount])[len] == '\n') {
                        ((*text)[textCount])[len] = '\0';
                    }
                    textCount++;
                } else {
                    printf("\nNot able to allocate memory for string\n");
                    return FAILURE;
                }
            }
        } else {
            printf("\nNot able to allocate memory for text array\n");
            return FAILURE;
        }
        fclose(fp);
        return textCount;
    } else {
        printf("\nFile cannot be opened\n");
        return FAILURE;
    }
}

// Function to display the strings stored in the dynamic array
void display(char **arr, int num) {
    if (arr == NULL) {
        printf("No strings to display.\n");
        return;
    }
    for (int i = 0; i < num; i++) {
        printf("String %d: %s\n", i + 1, arr[i]);
    }
}

// Free the allocated memory for strings
void freeMemory(char **arr, int num) {
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main(int argc, char *argv[]) {
    char **text = NULL;
    int textCount = 0;

    // Ensure correct number of arguments
    if (argc != 2) {
        printf("Error: Please provide the filename as an argument.\n");
        return FAILURE;
    }

    // Call the function to get strings from the file
    textCount = getFileString(&text, argv[1]);

    if (textCount != FAILURE) {
        // Display the content of the file
        display(text, textCount);
    }

    // Free the dynamically allocated memory
    freeMemory(text, textCount);

    return SUCCESS;
}

