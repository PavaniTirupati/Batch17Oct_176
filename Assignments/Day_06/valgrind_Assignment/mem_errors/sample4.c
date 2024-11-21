#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for 3 integers
    int *p = (int *)malloc(sizeof(int) * 3);
    if (NULL == p)
        exit(EXIT_FAILURE);

    // Properly initialize allocated memory
    *p = 1;
    *(p + 1) = 2;
    *(p + 2) = 3;

    // Remove out-of-bounds access
    // If more memory is required, reallocate memory instead
    printf("p[0]: %d\n", *p);
    printf("p[1]: %d\n", *(p + 1));
    printf("p[2]: %d\n", *(p + 2));

    // Free allocated memory
    free(p);

    return 0;
}

