/*************************************************************************
*
*  FILE NAME    : array_pointer.c
*
*  DESCRIPTION  : Finds out the maximum in an array and writes 0 there
*
*  DATE      NAME           REFERENCE          REASON
*
*  1-JUN-10  Sibu           PRISM-3 C FG       Initial Creation.
*  19-NOV-24 Tirupati Pavani Added getmax() to find maximum value in array.
*
*  Copyright 2010, Aricent Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
*                               HEADER FILES
*************************************************************************/
#include <stdio.h>

/*************************************************************************
*                               MACROS
*************************************************************************/
#define MAX 5

/*************************************************************************
*       Function Name   : getmax
*       Description     : Finds the maximum value in the array
*       Input           : Array of integers, size of the array
*       Returns         : Maximum value in the array
*************************************************************************/
int getmax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

/*************************************************************************
*       Function Name   : main
*       Description     : Demonstration of arrays and pointers
*       Returns         : Success or Failure
*************************************************************************/
int main()
{
    int index_1; /* for loop indices */
    int index = 0; /* Stores the index of minimum value */
    int min; /* Variable to keep track of minimum in the array */

    /* 1-d array declaration and initialization */
    int numbers[MAX] = {44, 22, 11, 55, 33};

    min = 99; /* Initialized to maximum 2-digit number */

    /* Displaying the array */
    printf("Initial Array:\n");
    for (index_1 = 0; index_1 < MAX; index_1 += 1)
    {
        printf("%d\t", numbers[index_1]);
    }
    printf("\n");

    /* Searching for the minimum and replacing that with 0 */
    for (index_1 = 0; index_1 < MAX; index_1 += 1)
    {
        if (*(numbers + index_1) < min) /* Checking for minimum */
        {
            min = *(numbers + index_1); /* Replacing min with new less value */
            index = index_1; /* Storing the index */
        }
    }
    *(numbers + index) = 0; /* Replacing minimum value with 0 */

    /* Displaying the array after replacing the minimum with 0 */
    printf("Array after replacing minimum with 0:\n");
    for (index_1 = 0; index_1 < MAX; index_1 += 1)
    {
        printf("%d\t", numbers[index_1]);
    }
    printf("\n");

    /* Finding the maximum value using getmax() */
    int max_value = getmax(numbers, MAX);
    printf("Maximum value in the array: %d\n", max_value);

    return 0;
}

