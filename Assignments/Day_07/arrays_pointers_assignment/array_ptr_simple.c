#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define a 2D array with 3 rows and 4 columns
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Using a pointer to an array of 4 integers
    int (*ptr)[4] = arr; // Points to the first row

    // Access and print the contents of the array using the pointer
    for (int i = 0; i < 3; i++) { // Iterate over rows
        printf("Row %d: ", i);
        for (int j = 0; j < 4; j++) { // Iterate over columns
            printf("%d ", ptr[i][j]); // Access element
        }
        printf("\n");
    }

    // Incrementing the pointer to move to the next row
    ptr++; // Now points to the second row
    printf("\nAccessing the second row using pointer arithmetic:\n");
    for (int j = 0; j < 4; j++) {
        printf("%d ", (*ptr)[j]);
    }
    printf("\n");

    return 0;
}

