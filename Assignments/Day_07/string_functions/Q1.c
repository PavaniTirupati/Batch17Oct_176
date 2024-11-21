#include <stdio.h>
#include <string.h>

#define MAX 100

int tokenise(char *arr) {
    char *token;
    int count = 0;

    // Tokenizing the input string
    token = strtok(arr, " ");
    while (token != NULL) {
        printf("Token %d: %s\n", ++count, token);
        token = strtok(NULL, " ");
    }

    return count;
}

int main() {
    char line[MAX];

    printf("Enter a line of text: ");
    fgets(line, MAX, stdin);
    line[strcspn(line, "\n")] = '\0'; // Remove trailing newline character

    int tokenCount = tokenise(line);
    printf("Number of tokens: %d\n", tokenCount);

    return 0;
}

