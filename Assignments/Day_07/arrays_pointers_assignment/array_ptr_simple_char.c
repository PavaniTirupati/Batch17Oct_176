/*************************************************************************
*
*  FILE NAME    : array_ptr_simple_char.c
*
*  DESCRIPTION  : Program to demonstrate access of 2D char array using ptr
*
*  DATE    NAME    REFERENCE          REASON
*
*  16-Aug 2020    Krithiga       Initial creation
*  
*  Copyright 2020, Altran
*
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for 2D character array program
*
* RETURNS: Nothing
**************************************************************************/
int main() {
    char arr[3][5] = {"ABCD", "EFGH", "IJKL"}; // Initialize a 2D character array

    {
        // TBD1: Pointer to the 2D character array
        char (*ptr)[5] = arr;

        // Print all rows using the pointer
        printf("Using char (*ptr)[5]:\n");
        for (int i = 0; i < 3; i++) {
            printf("Row %d: %s\n", i, ptr[i]);
        }
    }

    {
        // TBD2: Access specific characters using the pointer
        char (*ptr)[5] = arr;

        printf("\nAccess specific characters:\n");
        printf("arr[1][2] = %c\n", ptr[1][2]); // Output: G
        printf("arr[2][0] = %c\n", ptr[2][0]); // Output: I
    }

    {
        // TBD3: Modify elements in the 2D array
        char (*ptr)[5] = arr;

        // Modify characters using the pointer
        ptr[0][0] = 'X'; // Change the first character of the first row
        ptr[1][3] = 'Y'; // Change the fourth character of the second row

        printf("\nModified array:\n");
        for (int i = 0; i < 3; i++) {
            printf("Row %d: %s\n", i, ptr[i]);
        }
    }

    {
        // TBD4: Traverse characters in reverse order
        char (*ptr)[5] = arr;

        printf("\nTraverse characters in reverse order for each row:\n");
        for (int i = 0; i < 3; i++) {
            printf("Row %d: ", i);
            for (int j = 3; j >= 0; j--) { // Reverse loop
                printf("%c", ptr[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

