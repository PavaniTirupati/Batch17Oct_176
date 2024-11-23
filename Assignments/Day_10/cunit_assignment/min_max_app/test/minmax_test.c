#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../include/min_max.h"

// Function to test getMin()
void test_getMin()
{
    int arr[] = {10, 90, 7, 8};
    int result = getMin(arr, 4);
    assert(result == 7);
    printf("test_getMin: Passed\n");
}

// Function to test getMax()
void test_getMax()
{
    int arr[] = {10, 90, 7, 8};
    int result = getMax(arr, 4);
    assert(result == 90);
    printf("test_getMax: Passed\n");
}

// Function to test getLongest()
void test_getLongest()
{
    char str1[] = "Hello";
    char str2[] = "World!";
    char *result = getLongest(str1, str2);
    assert(strcmp(result, "World!") == 0);

    char *result_null = getLongest(NULL, str2);
    assert(strcmp(result_null, "World!") == 0);

    char *result_both_null = getLongest(NULL, NULL);
    assert(result_both_null == NULL);

    printf("test_getLongest: Passed\n");
}

int main()
{
    test_getMin();
    test_getMax();
    test_getLongest();

    printf("All tests passed successfully.\n");
    return 0;
}

