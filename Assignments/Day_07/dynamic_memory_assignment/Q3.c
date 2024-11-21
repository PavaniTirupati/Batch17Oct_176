#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 80

// Function to allocate memory for a double pointer to hold n pointers
char **allocate_array_memory(char **ptr, int n) {
    ptr = (char **)malloc(n * sizeof(char *));
    if (ptr == NULL) {
        printf("Memory allocation failed for array of pointers.\n");
        exit(1);
    }
    return ptr;
}

// Function to allocate memory for an input string and return the pointer
char *allocate_string_memory(char *string) {
    string = (char *)malloc((strlen(string) + 1) * sizeof(char));  // +1 for null terminator
    if (string == NULL) {
        printf("Memory allocation failed for string.\n");
        exit(1);
    }
    return string;
}

// Function to display the stored strings
void display(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("String %d: %s\n", i + 1, arr[i]);
    }
}

// Function to free the memory of the array of strings
void free_array_memory(char **ptr, int n) {
    for (int i = 0; i < n; i++) {
        free(ptr[i]);
    }
    free(ptr);
}

// Function to free the memory of a single string
void free_string_memory(char *ptr) {
    free(ptr);
}

int main() {
    int n;

    // Prompt user for the number of strings to read
    printf("Enter the number of strings (max N): ");
    scanf("%d", &n);
    getchar();  // Consume the newline character left by scanf

    // Allocate memory for the array of pointers to strings
    char **strings = allocate_array_memory(NULL, n);

    int count = 0;
    while (count < n) {
        char input[MAX_STRING_LENGTH];

        printf("Enter string %d: ", count + 1);
        fgets(input, MAX_STRING_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;  // Remove the newline character

        // If input is "end" or "END", stop reading strings
        if (strcmp(input, "end") == 0 || strcmp(input, "END") == 0) {
            break;
        }

        // Allocate memory for the string and store it
        strings[count] = allocate_string_memory(input);
        strcpy(strings[count], input);
        count++;
    }

    // Display the stored strings
    display(strings, count);

    // Free the allocated memory
    free_array_memory(strings, count);

    return 0;
}

