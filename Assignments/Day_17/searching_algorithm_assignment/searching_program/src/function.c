/*****************************************************************
 *      FILENAME    : function.c
 *      DESCRIPTION : This file contains functions for line input, sorting, searching, deletion, and file writing.
 * ****************************************************************/
#include "header.h"

/*******************************************************************
 *        FUNCTION NAME: get_line
 *        DESCRIPTION: Gets a line from standard input into the i-th
 *        	       element of the array
 *        ARGUMENTS:   Array of strings and index
 *        RETURNS:  returns SUCCESS or FAILURE
 ******************************************************************/
int get_line(char *array[], int i) {
    int len;
    char buff[SIZE];

    memset(buff, 0, SIZE); // Initialize buffer

    fgets(buff, SIZE - 1, stdin); // Get input from user
    len = strlen(buff);
    if ('\n' == buff[len - 1]) { // Replace '\n' with '\0'
        buff[len - 1] = '\0';
    }

    // Allocate memory for the i-th array element
    array[i] = (char *)malloc((len + 1) * sizeof(char));

    if (NULL == array[i]) {
        printf("Memory Allocation Failed\n");
        return FAILURE;
    }
    strcpy(array[i], buff); // Copy buffer to array[i]

    return SUCCESS;
}

/******************************************************************
 *        FUNCTION NAME:     bubble_sort
 *        DESCRIPTION:       Sorts the list of strings provided
 *        ARGUMENTS:         Array of strings and number of strings
 *        RETURNS:           SUCCESS after sorting
 ******************************************************************/
int bubble_sort(char *array[], int n) {
    int i, j;
    int SWAP;
    char *temp;

    for (i = 0; i < (n - 1); i++) {
        SWAP = 0;
        for (j = 0; j < (n - 1 - i); j++) {
            if (strcmp(array[j], array[j + 1]) > 0) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                SWAP = 1;
            }
        }
        if (0 == SWAP) {
            break;
        }
    }
    return SUCCESS;
}

/******************************************************************
 *   FUNCTION NAME:    binary_search
 *   DESCRIPTION:      Searches for an element in the given list
 *   ARGUMENTS:        Array of strings, search string, and number of elements
 *   RETURNS:          Index of element or FAILURE
 ******************************************************************/
int binary_search(char *array[], char *find, int n) {
    int BEG = 0;
    int END = n - 1;
    int MID;

    while (BEG <= END) {
        MID = (BEG + END) / 2;

        int cmp = strcmp(find, array[MID]);
        if (cmp == 0) {
            return MID;
        }
        if (cmp < 0) {
            END = MID - 1;
        } else {
            BEG = MID + 1;
        }
    }

    return FAILURE;
}

/******************************************************************
 *   FUNCTION NAME:    delete_line
 *   DESCRIPTION:      Deletes the line at the specified index
 *   ARGUMENTS:        Array of strings, pointer to size, index
 *   RETURNS:          None
 ******************************************************************/
void delete_line(char *array[], int *n, int index) {
    free(array[index]); // Free memory for the deleted line
    for (int i = index; i < (*n) - 1; i++) {
        array[i] = array[i + 1];
    }
    (*n)--; // Reduce the count of lines
}

/******************************************************************
 *   FUNCTION NAME:    write_to_file
 *   DESCRIPTION:      Writes the array of lines to a file
 *   ARGUMENTS:        Array of strings, number of lines, filename
 *   RETURNS:          None
 ******************************************************************/
void write_to_file(char *array[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s\n", array[i]);
    }

    fclose(file);
}

