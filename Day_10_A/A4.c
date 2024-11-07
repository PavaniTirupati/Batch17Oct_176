/* 
File : A4.c
DESCRIPTION : program to rotate array every kth element
Date : 7-11-2024
Name : Tirupati Pavani
*/

#include <stdio.h>

void reverse(int arr[], int start, int end);
void rotateArrayEveryKthElement(int arr[], int size, int k);
int main() {
    int size, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i=0;i<size;i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("\n");
    rotateArrayEveryKthElement(arr, size, k);
    printf("Array after rotating every %d-th element: ", k);
    for (int i=0;i<size;i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
void reverse(int arr[], int start, int end) 
{
    while (start<end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateArrayEveryKthElement(int arr[], int size, int k) 
{
    for (int i=0;i<size;i+=k) 
    {
        int end = (i+k-1 < size) ? (i+k-1) : (size-1);
        reverse(arr, i, end);
    }
}
