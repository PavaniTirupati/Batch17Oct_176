#include <stdio.h>
#include <string.h>

void sort(char arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char arr[] = "xaybz";
    int size = strlen(arr);

    sort(arr, size);

    printf("Sorted array: %s\n", arr);

    return 0;
}

