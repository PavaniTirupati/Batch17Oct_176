/*  sample2.c : A C program example for practising runtime memory errors
 *  analysis
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main()
{
    char *data1, *data2, *tmp;
    int i;

    // Allocate memory for data1 and check for success
    data1 = (char *)malloc(SIZE * sizeof(char));
    if (NULL == data1)
        exit(EXIT_FAILURE);

    printf("Please input your username (max 15 characters): ");
    scanf("%15s", data1); // Prevent buffer overflow by limiting input

    // Allocate memory for data2 and check for success
    data2 = (char *)malloc(SIZE * sizeof(char));
    if (NULL == data2)
    {
        free(data1); // Free previously allocated memory before exiting
        exit(EXIT_FAILURE);
    }

    tmp = data1;

    // Safely copy data1 to data2
    for (i = 0; i < SIZE - 1 && *tmp != '\0'; i++) // Check for end of string
    {
        data2[i] = *(tmp++);
    }
    data2[i] = '\0'; // Ensure null-termination

    printf("data2 :%s:\n", data2);

    // Remove invalid memory access for tmp by resetting it to the start of data1
    tmp = data1;
    printf("tmp :%s:\n", tmp);

    // Free allocated memory
    free(data1);
    free(data2);

    return 0;
}

