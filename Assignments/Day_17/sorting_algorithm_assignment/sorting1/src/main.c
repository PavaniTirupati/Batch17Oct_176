/***************************************************************************
 * FILE NAME:     main.c
 * DESCRIPTION:   Contains the main function invoking merge sort
 * DATE           : 2024-11-24
 * NAME           : Tirupati Pavani
 ***************************************************************************/

#include "header.h"

/***********************************************************************
 * FUNCTION NAME : main
 * DESCRIPTION   : Reads strings, sorts them using merge sort, and displays results
 *************************************************************************/
int main() {
    char *array[MAX];
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);

    printf("Enter the names (one per line):\n");
    for (int i = 0; i < n; i++) {
        array[i] = (char *)malloc(MAX * sizeof(char));
        scanf("%s", array[i]);
    }

    printf("\nNames before sorting:\n");
    display_array(array, n);

    // Sorting the array
    merge_sort(array, 0, n - 1);

    printf("\nNames after sorting:\n");
    display_array(array, n);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }

    return 0;
}

