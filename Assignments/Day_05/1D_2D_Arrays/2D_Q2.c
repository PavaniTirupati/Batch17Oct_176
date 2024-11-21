#include <stdio.h>

#define ROWS 3
#define COLS 3

void init(char arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = 'A' + i * COLS + j; // Example initialization
}

int search_update(char arr[ROWS][COLS], char search, char update)
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] == search)
            {
                arr[i][j] = update;
                return 0; // Success
            }
        }
    return 1; // Failure
}

void display(char arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%c ", arr[i][j]);
        printf("\n");
    }
}

int main()
{
    char arr[ROWS][COLS];
    init(arr);

    printf("Array after initialization:\n");
    display(arr);

    char search = 'C', update = 'Z';
    if (search_update(arr, search, update) == 0)
        printf("\nArray after updating '%c' to '%c':\n", search, update);
    else
        printf("\nCharacter '%c' not found.\n", search);

    display(arr);

    return 0;
}

