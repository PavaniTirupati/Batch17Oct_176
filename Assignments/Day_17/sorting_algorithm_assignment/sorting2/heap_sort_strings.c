#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_ARR_SIZE 100

// Function to swap two strings
void swap(char arr[][MAX_STR_LEN], int i, int j) {
    char temp[MAX_STR_LEN];
    strcpy(temp, arr[i]);
    strcpy(arr[i], arr[j]);
    strcpy(arr[j], temp);
}

// To heapify a subtree rooted with node i
void heapify(char arr[][MAX_STR_LEN], int n, int i) {
    int largest = i;          // Initialize largest as root
    int l = 2 * i + 1;        // left = 2*i + 1
    int r = 2 * i + 2;        // right = 2*i + 2

    // If left child is larger than root (lexicographically)
    if (l < n && strcmp(arr[l], arr[largest]) > 0)
        largest = l;

    // If right child is larger than largest so far
    if (r < n && strcmp(arr[r], arr[largest]) > 0)
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr, i, largest); // Swap strings
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

// Main function to do heap sort
void heapSort(char arr[][MAX_STR_LEN], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr, 0, i);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print array
void printArray(char arr[][MAX_STR_LEN], int n) {
    for (int i = 0; i < n; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    char arr[MAX_ARR_SIZE][MAX_STR_LEN];
    int n;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter the strings (one per line):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    printf("\nOriginal array:\n");
    printArray(arr, n);

    // Function call
    heapSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}

