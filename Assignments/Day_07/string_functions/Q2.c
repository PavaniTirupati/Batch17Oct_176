#include <stdio.h>

char *my_strncat(char *dest, const char *src, size_t n) {
    char *destStart = dest;

    // Move to the end of the destination string
    while (*dest != '\0') {
        dest++;
    }

    // Append up to n characters from src
    while (n-- && *src != '\0') {
        *dest++ = *src++;
    }

    *dest = '\0'; // Null-terminate the result

    return destStart;
}

int main() {
    char dest[50] = "Hello, ";
    char src[] = "World!";
    size_t n = 3;

    printf("Before concatenation: %s\n", dest);
    my_strncat(dest, src, n);
    printf("After concatenation: %s\n", dest);

    return 0;
}

