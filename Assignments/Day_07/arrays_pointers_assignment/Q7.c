#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read and display alternate characters from the string at a given row
void read_displaystring(char arr[][10], int row) {
    if (row < 0 || row >= 5) {
        printf("Invalid row index.\n");
        return;
    }

    char *str = arr[row]; // Access the string at the given row
    printf("String at row %d: %s\n", row, str);

    printf("Alternate characters: ");
    for (int i = 0; str[i] != '\0'; i += 2) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Function to reverse the string at a given row and return the reversed string
char *reverse(char arr[][10], int row) {
    if (row < 0 || row >= 5) {
        printf("Invalid row index.\n");
        return NULL;
    }

    char *str = arr[row];
    size_t len = strlen(str);

    // Allocate memory for the reversed string
    char *reversed = (char *)malloc((len + 1) * sizeof(char));
    if (!reversed) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Reverse the string
    for (size_t i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';

    return reversed; // Return the reversed string
}

int main() {
    char arr[][10] = {"Word", "Excel", "PowerPoint", "Pdf", "Paint"};

    // Part (a): Display alternate characters
    int row;
    printf("Enter the row index to read (0-4): ");
    scanf("%d", &row);
    read_displaystring(arr, row);

    // Part (b): Reverse the string and display the reversed string
    char *reversedStr = reverse(arr, row);
    if (reversedStr) {
        printf("Reversed string: %s\n", reversedStr);
        free(reversedStr); // Free allocated memory
    }

    return 0;
}

