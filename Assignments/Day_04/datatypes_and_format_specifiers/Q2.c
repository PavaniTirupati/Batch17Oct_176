/* 
DESCRIPTION : Program to read a character ('y', 'Y', 'n', 'N') and display "Yes" or "No"
Date : 05-11-2024
Name : Tirupati Pavani
*/

#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    char choice;

    printf("Enter your choice (Y/y/N/n): ");
    scanf(" %c", &choice);

    // Display result based on input
    switch (choice) {
        case 'y':
        case 'Y':
            printf("Yes\n");
            break;
        case 'n':
        case 'N':
            printf("No\n");
            break;
        default:
            printf("Invalid character\n");
            exit(1);
    }

    return 0;
}

