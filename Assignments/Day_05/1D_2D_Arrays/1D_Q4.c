#include <stdio.h>

#define MAX 100

void init(int arr[], int N, int start)
{
    for (int i = 0; i < N; i++)
        arr[i] = start + i;
}

void update(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        arr[i]++;
}

void display(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[MAX] = {0};
    int N, start;

    printf("Enter number of elements (N): ");
    scanf("%d", &N);
    printf("Enter start value: ");
    scanf("%d", &start);

    init(arr, N, start);
    printf("Array after init: ");
    display(arr, N);

    update(arr, N);
    printf("Array after update: ");
    display(arr, N);

    return 0;
}

