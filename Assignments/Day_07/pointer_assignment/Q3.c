#include <stdio.h>
#include <stdlib.h>

#define MAX 80

// Swap integers by pointer
void swap_nums(int *x, int *y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

// Swap pointers to string
void swap_pointers(char **x, char **y) {
    char *tmp;
    tmp = *x;
    printf("\n swap_pointers: x, y is %p %p, tmp=x: %p\n", *x, *y, tmp);
    printf("\n swap_pointers: x, y is %s %s, tmp=x: %s\n", *x, *y, tmp);
    *x = *y;
    *y = tmp;
    printf("\n swap_pointers: x, y after swap is %s %s\n", *x, *y);
}

int test_swap_char() {
    char arr1[MAX] = "ABC";
    char arr2[MAX] = "DEFGH";

    char *s1 = arr1;
    char *s2 = arr2;

    printf("\n s1, s2 address before swap is %p %p\n", s1, s2);

    // Swap the pointers
    swap_pointers(&s1, &s2);

    printf("\n s1, s2 address after swap is %p %p\n", s1, s2);
    printf(" s1, s2 values after swap: %s %s\n", s1, s2);

    return 0;
}

int test_swap_num() {
    int a = 3, b = 4;

    // Swap the numbers using pass by pointer
    swap_nums(&a, &b);
    printf("a is %d\n", a);
    printf("b is %d\n", b);
    return 0;
}

/**************************************************************************
 *
 * FUNCTION NAME: main
 *
 * DESCRIPTION: main function to demonstrate pass by value 
 * and pass by reference  
 *
 * RETURNS: int
 **************************************************************************/
int main() {
    // Swap 2 numbers
    test_swap_num();

    // Swap two string pointers
    test_swap_char();

    return 0;
}

