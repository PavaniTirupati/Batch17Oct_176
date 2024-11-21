#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 80

// Function to process the input string, tokenize it, and concatenate the words with '_'
char *process_string(char *line) {
    char *result = (char *)malloc(MAX_LENGTH * sizeof(char));  // Allocate memory for the concatenated string
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit if memory allocation fails
    }

    char *token = strtok(line, " ");  // Tokenize the string using space as a delimiter
    strcpy(result, token);  // Copy the first word into the result string

    // Iterate through the rest of the tokens and concatenate them with '_'
    while ((token = strtok(NULL, " ")) != NULL) {
        strcat(result, "_");  // Add underscore
        strcat(result, token);  // Concatenate the next word
    }

    return result;  // Return the concatenated string
}

int main() {
    char line[MAX_LENGTH];

    // Read the line of text from the user
    printf("Enter a line of text (max 80 characters): ");
    fgets(line, MAX_LENGTH, stdin);
    line[strcspn(line, "\n")] = 0;  // Remove the newline character if present

    // Process the string and get the concatenated result
    char *concatenated_string = process_string(line);

    // Display the concatenated string
    printf("Concatenated string: %s\n", concatenated_string);

    // Free the dynamically allocated memory for the concatenated string
    free(concatenated_string);

    return 0;
}

