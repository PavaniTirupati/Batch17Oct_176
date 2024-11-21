#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main()
{
    char *data1, *data2;
    int i;

    do
    {
        data1 = (char *)malloc(SIZE * sizeof(char));
        if (NULL == data1)
            exit(EXIT_FAILURE);

        printf("Please enter your user name: ");
        scanf("%15s", data1); // Limit input to avoid buffer overflow

        if (!strcmp(data1, "quit"))
        {
            free(data1); // Free memory for data1 before breaking
            break;
        }

        data2 = (char *)malloc(SIZE * sizeof(char));
        if (NULL == data2)
        {
            free(data1); // Free previously allocated memory for data1
            exit(EXIT_FAILURE);
        }

        for (i = 0; i < SIZE; i++)
        {
            data2[i] = data1[i];
        }

        printf("data2 :%s:\n", data2);

        free(data2); // Free memory for data2 after usage
        free(data1); // Free memory for data1 before the next iteration
    } while (1);

    return 0;
}

