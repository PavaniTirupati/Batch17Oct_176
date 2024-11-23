/******************************************************************************
* File Name: min_max.c
* Purpose: Demo code. Contains functions getMin(), getMax(), and getLongest().
*******************************************************************************/
#include <string.h>
#include <stdlib.h>

#define MIN(x, y) \
    x < y ? x : y

#define MAX(x, y) \
    x > y ? x : y

// Find minimum in the given array
int getMin(int arr[], int n) 
{ 
    int res = arr[0]; 
    for (int i = 1; i < n; i++) 
        res = MIN(res, arr[i]); 
    return res; 
}

// Find maximum in the given array
int getMax(int arr[], int n) 
{ 
    int res = arr[0]; 
    for (int i = 1; i < n; i++) 
        res = MAX(res, arr[i]); 
    return res; 
}

// Return the longest string between two given strings
char *getLongest(char *s1, char *s2)
{
    if (!s1 && !s2) return NULL; // Both strings are NULL
    if (!s1) return s2;         // s1 is NULL
    if (!s2) return s1;         // s2 is NULL
    return (strlen(s1) >= strlen(s2)) ? s1 : s2;
}

