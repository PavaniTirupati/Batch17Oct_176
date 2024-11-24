/***************************************************************************
 * FILE NAME:     function.c
 * DESCRIPTION:   Definitions of sorting functions for merge sort
 * DATE           : 2024-11-24
 * NAME           : Tirupati Pavani
 ***************************************************************************/

#include "header.h"

/*********************************************************************
 * FUNCTION NAME: merge_sort
 * DESCRIPTION  : Recursively divides the array and merges sorted parts
 * PARAMETERS   : Array of strings, beginning index, and ending index
 * RETURNS      : void
 *********************************************************************/
void merge_sort(char *array[], int BEG, int END) {
    int MID;

    if (BEG < END) {
        MID = (BEG + END) / 2;
        merge_sort(array, BEG, MID);
        merge_sort(array, MID + 1, END);
        merge(array, BEG, MID, END);
    }
}

/*********************************************************************
 * FUNCTION NAME: merge
 * DESCRIPTION  : Merges two sorted parts of the array
 * PARAMETERS   : Array of strings, beginning index, middle index, and ending index
 * RETURNS      : void
 *********************************************************************/
void merge(char *array[], int BEG, int MID, int END) {
    char *temp[MAX];
    int i = BEG, j = MID + 1, k = 0;

    // Merge the two parts into temp array
    while (i <= MID && j <= END) {
        if (strcmp(array[i], array[j]) <= 0) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    // Copy remaining elements from the left part
    while (i <= MID) {
        temp[k++] = array[i++];
    }

    // Copy remaining elements from the right part
    while (j <= END) {
        temp[k++] = array[j++];
    }

    // Copy sorted elements back into the original array
    for (i = BEG, k = 0; i <= END; i++, k++) {
        array[i] = temp[k];
    }
}

/*********************************************************************
 * FUNCTION NAME: display_array
 * DESCRIPTION  : Displays the elements of an array
 * PARAMETERS   : Array of strings and size of the array
 * RETURNS      : void
 *********************************************************************/
void display_array(char *array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", array[i]);
    }
}

