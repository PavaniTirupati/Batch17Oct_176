/*****************************************************************
 *	FILE_NAME    :    main.c
 * 	DESCRIPTION  :    Implements binary search, sort, and line management
 * 	RETURN_TYPE  :    returns success or failure
 * ***************************************************************/
#include "header.h"

int main() {
    char *array[MAX];  // Array to store lines
    char search_line[SIZE];
    int n, i, ret;

    printf("\nHow many lines you want to enter: ");
    scanf("%d", &n);
    getchar(); // Clean buffer

    printf("\nEnter the lines:\n");
    for (i = 0; i < n; i++) {
        get_line(array, i); // Get each line
    }

    printf("\nThe entered lines are:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", array[i]);
    }

    bubble_sort(array, n); // Sort lines

    printf("\nThe sorted lines are:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", array[i]);
    }

    printf("\nEnter the line to be searched and deleted: ");
    fgets(search_line, SIZE, stdin);

    int len = strlen(search_line);
    if ('\n' == search_line[len - 1]) {
        search_line[len - 1] = '\0'; // Replace '\n' with '\0'
    }

    ret = binary_search(array, search_line, n);

    if (ret == FAILURE) {
        printf("\nLine not found.\n");
    } else {
        printf("\nLine found at index: %d\n", ret);
        delete_line(array, &n, ret); // Delete the found line
    }

    printf("\nThe final lines are:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", array[i]);
    }

    write_to_file(array, n, "out.txt"); // Write final lines to file

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(array[i]);
    }

    return SUCCESS;
}

