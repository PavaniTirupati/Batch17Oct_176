#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *func();

int main()
{
    char *p = NULL;
    int a = 0; // Initialize 'a' to avoid uninitialized variable error
    int i;
    int arr[10];
    int *pint = NULL;

    // Properly initialize and access array within bounds
    for (i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    if (i + 10 < sizeof(arr) / sizeof(arr[0])) // Ensure index is within bounds
    {
        arr[i + 10] = i + 10;
        printf("\nValue of array at location %d : %d ", i + 10, arr[i + 10]);
    }

    p = (char *)malloc(sizeof(char) * 12);
    if (p == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Properly initialize 'p' before using it
    strcpy(p, "Initialized");
    printf("\n%s", p);

    // Avoid use-after-free by not accessing 'p' after freeing
    free(p);

    // Remove use-after-free error by not accessing p after it's freed
    p = (char *)malloc(sizeof(char) * 12); // Reallocate memory if needed
    if (p != NULL)
    {
        strcpy(p, "hello world");
        printf("\n%s", p);
        free(p);
    }

    // Fix invalid memory access from func()
    pint = (int *)malloc(sizeof(int)); // Dynamically allocate memory
    if (pint != NULL)
    {
        *pint = *func(); // Store the value instead of using the invalid address
        printf("\nValue returned by func: %d", *pint);
        free(pint);
    }

    return 0;
}

int *func()
{
    int *a = (int *)malloc(sizeof(int)); // Dynamically allocate memory
    if (a == NULL)
    {
        perror("Memory allocation failed in func");
        exit(EXIT_FAILURE);
    }
    *a = 5;
    return a;
}

