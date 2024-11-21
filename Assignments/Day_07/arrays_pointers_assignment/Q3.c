#include <stdio.h>
#include <string.h>

#define MAX 80
#define SUCCESS 1
#define FAILURE 0

// Function to search for a character and insert '_' after it
int search_insert(char name[], char search_char) {
    int len = strlen(name);
    int i;

    // Search for the character in the string
    for (i = 0; i < len; i++) {
        if (name[i] == search_char) {
            // Shift characters to create space for '_'
            for (int j = len; j > i; j--) {
                name[j] = name[j - 1];
            }

            // Insert '_'
            name[i + 1] = '_';
            name[len + 1] = '\0'; // Null-terminate the string
            return SUCCESS;
        }
    }

    return FAILURE; // Character not found
}

int main() {
    char name[MAX] = "ABC";
    char search_char = 'B';

    printf("Original string: %s\n", name);

    int ret = search_insert(name, search_char);

    if (ret == SUCCESS) {
        printf("Updated string: %s\n", name);
    } else {
        printf("Character '%c' not found in the string.\n", search_char);
    }

    return 0;
}

