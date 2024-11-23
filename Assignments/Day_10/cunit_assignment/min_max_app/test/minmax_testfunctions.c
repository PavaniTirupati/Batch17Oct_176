/*******************************************************************************
* File Name:minmax_testfunctions.c
* Purpose: Contains test function for getMin() and getMax()
*******************************************************************************/

#include <CUnit.h>
#include <min_max.h>
#include <string.h>

void Mytestfunction_min(void)
{
    int arr[] = {10, 90, 7, 8};
    int min = getMin(arr, 4);

    CU_ASSERT(min == 7);
    printf("\nMin: %d\n", min);
}

void Mytestfunction_max(void)
{
    int arr[] = {10, 90, 7, 8};
    int max = getMax(arr, 4);

    CU_ASSERT(max == 90);
    printf("\nMax: %d\n", max);
}

void Mytestfunction_longest(void)
{
    char str1[] = "Hello";
    char str2[] = "World!";
    char *result = getLongest(str1, str2);

    CU_ASSERT_STRING_EQUAL(result, "World!");

    char *res_null = getLongest(NULL, str2);
    CU_ASSERT_STRING_EQUAL(res_null, "World!");

    char *res_both_null = getLongest(NULL, NULL);
    CU_ASSERT_PTR_NULL(res_both_null);

    printf("\nLongest String Test Completed.\n");
}

