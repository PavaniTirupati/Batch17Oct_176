/* 
DESCRIPTION : Program to convert a decimal number (0-127) into 2-digit hexadecimal
Date : 05-11-2024
Name : Tirupati Pavani
*/

#include <stdio.h>

int main() {
    int number;

    // Input number
    printf("Enter a number (0-127): ");
    scanf("%d", &number);

    // Validate range
    if (number < 0 || number > 127) {
        printf("Invalid input! Please enter a number between 0 and 127.\n");
        return 1;
    }

    // Convert to hexadecimal
    printf("Hexadecimal representation: %02X\n", number);

    return 0;
}

