#include <stdio.h>
#include <string.h>

// Macro to sort a character array
#define SORT_CHAR_ARRAY(arr, len)         \
    do {                                  \
        for (int i = 0; i < (len) - 1; i++) { \
            for (int j = 0; j < (len) - i - 1; j++) { \
                if ((arr)[j] > (arr)[j + 1]) {       \
                    char temp = (arr)[j];            \
                    (arr)[j] = (arr)[j + 1];         \
                    (arr)[j + 1] = temp;             \
                }                                    \
            }                                        \
        }                                            \
    } while (0)

int main() {
    char arr[] = "programming";
    int len = strlen(arr);

    printf("Original array: %s\n", arr);

    SORT_CHAR_ARRAY(arr, len);

    printf("Sorted array: %s\n", arr);

    return 0;
}
