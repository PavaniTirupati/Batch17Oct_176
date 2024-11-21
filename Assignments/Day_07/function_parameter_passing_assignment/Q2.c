#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

// Function to read string, extract characters at odd indices, and return the extracted string
void read_extract_characters(char *input_str, char *output_str);

int main() {
    char input_str[MAX_LENGTH], output_str[MAX_LENGTH];
    
    // Read a string from user
    printf("Enter a string (max 50 characters): ");
    fgets(input_str, MAX_LENGTH, stdin);
    // Remove newline character if any
    input_str[strcspn(input_str, "\n")] = 0;

    // Extract characters at odd indices
    read_extract_characters(input_str, output_str);

    // Display the extracted string
    printf("Extracted string: %s\n", output_str);
    
    return 0;
}

// Function to extract characters from odd indices
void read_extract_characters(char *input_str, char *output_str) {
    int j = 0;
    
    // Loop through the input string and extract characters at odd indices
    for (int i = 1; input_str[i] != '\0'; i += 2) {
        output_str[j++] = input_str[i];
    }
    output_str[j] = '\0';  // Null terminate the output string
}

