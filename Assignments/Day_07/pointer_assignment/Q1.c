#include <stdio.h>
#include <stdint.h> // For uintptr_t

void display(int *ptr) {
    printf("\nAddress of the pointer in hexadecimal: 0x%lx\n", (uintptr_t)ptr);
    printf("Contents of the memory pointed by pointer: %d\n", *ptr);
}

int main() {
    char arr[] = "hello hi";  // Correctly declared as a character array
    int *ptr = (int *)arr;   // Casting char array to int pointer for demonstration

    printf("sizeof ptr: %zu, sizeof arr: %zu\n", sizeof(ptr), sizeof(arr));
    display(ptr);

    return 0;
}

