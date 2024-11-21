#include <stdio.h>
#include <stdlib.h>

int func1(int (*ptr)[3]);
int func2(int **);

int main() {
    int mat[3][3], i, j;
    int k = 0;

    // Initialize the 2D array
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            mat[i][j] = k++;
        }

    printf("Initialized data to:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%p   ", &mat[i][j]);
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\nCalling func1...\n");
    func1(mat);

    printf("\nCalling func2...\n");
    func2((int **)mat);

    return 0;
}

/*
Method #1 (pointer to array, second dimension is explicitly specified)
======================================================================
*/
int func1(int (*ptr)[3]) {
    printf("In func1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Value at ptr[%d][%d] = %d\n", i, j, ptr[i][j]);
        }
    }
    return 0;
}

/*
Method #2 (double pointer, using an auxiliary array of pointers)
=================================================================
With this method, you can create general-purpose routines
if you allocate "index" at runtime.
*/
int func2(int **ptr) {
    printf("In func2:\n");

    // Create an auxiliary array of pointers
    int *aux[3];
    for (int i = 0; i < 3; i++) {
        aux[i] = (int *)ptr + i * 3; // Point to each row
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Value at aux[%d][%d] = %d\n", i, j, aux[i][j]);
        }
    }

    return 0;
}

