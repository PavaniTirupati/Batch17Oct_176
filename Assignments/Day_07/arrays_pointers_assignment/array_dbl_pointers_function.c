#include <stdio.h>
#include <stdlib.h>

void func1(short mat[][3]);
void func2(short (*ptr)[3]);
void func3(short *);
void func4(short **);
void func5(short *ptr[3]);

int main() {
    short mat[3][3], i, j;

    // Initialize the 2D array
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            mat[i][j] = i * 10 + j;
        }

    printf("Initialized data to:");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            printf("%5.2d", mat[i][j]);
        }
    }
    printf("\n");

    func1(mat);
    func2(mat);
    func3((short *)mat); // Flattened array, cast to single pointer
    func4((short **)mat); // Cast to double pointer
    func5((short **)mat); // Auxiliary array of pointers

    return 0;
}

/* 
Method #1: Explicitly specify the second dimension
=================================================
*/
void func1(short mat[][3]) {
    register short i, j;

    printf("Declare as matrix, explicitly specify second dimension:");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            // Display the element
            printf("%5.2d", mat[i][j]); // TBD1
        }
    }
    printf("\n");
}

/* 
Method #2: Pointer to an array, explicitly specify the second dimension
=======================================================================
*/
void func2(short (*mat)[3]) {
    register short i, j;

    printf("Declare as pointer to column, explicitly specify 2nd dim:");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            // Display the element
            printf("%5.2d", mat[i][j]); // TBD2
        }
    }
    printf("\n");
}

/* 
Method #3: Single pointer with manual offset computation
========================================================
*/
void func3(short *mat) {
    register short i, j;

    printf("Declare as single-pointer, manual offset computation:");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            // Compute the offset manually
            printf("%5.2d", *(mat + i * 3 + j)); // TBD3
        }
    }
    printf("\n");
}

/* 
Method #4: Double pointer with auxiliary pointer array
======================================================
*/
void func4(short **mat) {
    short i, j, *index[3];

    // Initialize the index array
    for (i = 0; i < 3; i++) {
        index[i] = (short *)mat + i * 3; // TBD4
    }

    printf("Declare as double-pointer, use auxiliary pointer array:");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            // Display the element using the index array
            printf("%5.2d", index[i][j]); // TBD5
        }
    }
    printf("\n");
}

/* 
Method #5: Single pointer with auxiliary pointer array
======================================================
*/
void func5(short *mat[3]) {
    short i, j, *index[3];

    // Initialize the index array to point to the rows of the original matrix
    for (i = 0; i < 3; i++) {
        index[i] = (short *)mat + i * 3; // Correctly calculate the row pointer
    }

    printf("Declare as single-pointer, use auxiliary pointer array:");
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            // Access elements using the auxiliary pointer array
            printf("%5.2d", index[i][j]); // Correctly dereference the index array
        }
    }
    printf("\n");
}

