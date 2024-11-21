#include <stdio.h>
#include <string.h>  // For string manipulation functions

#define MAX 100
#define SUCCESS 0
#define FAILURE 1

// Function to append the string from appendstr[] to arr[] using pointer
int append(char *ptr, char *appendstr) {
    char *start = ptr;  // Keep track of the start of the array

    // Move ptr to the end of the current string in arr[]
    while (*ptr != '\0') {
        ptr++;  // Move to the next character in arr[]
    }

    // Append the new string to arr[]
    while (*appendstr != '\0') {
        // Check if adding a new character exceeds the array's size
        if ((ptr - start) < MAX - 1) {
            *ptr = *appendstr; // Append character
            ptr++;             // Move pointer forward
            appendstr++;       // Move to the next character in appendstr
        } else {
            // If we reach the limit, stop appending to avoid buffer overflow
            return FAILURE;
        }
    }

    *ptr = '\0';  // Null-terminate the string in arr[]
    return SUCCESS;
}

// Function to display the address in hexadecimal and contents of the pointer
void display(char *ptr) {
    printf("\nAddress of ptr in hexadecimal: 0x%lx\n", (unsigned long)ptr);
    printf("Contents of the memory pointed by ptr: %s\n", ptr);
}

int main() {
    char arr[MAX] = "Learning C";  // Initial string in arr[]
    char *ptr = arr;               // Pointer to arr[]
    char appendstr[] = " in my org";  // String to append

    printf("Initial string in arr: %s\n", arr);
    printf("Address of ptr: 0x%lx\n", (unsigned long)ptr);

    // Append the string
    int ret = append(ptr, appendstr);  // Append the string

    // Display the address and contents after appending
    printf("Address of ptr after appending: 0x%lx\n", (unsigned long)ptr);

    if (ret == SUCCESS) {
        display(ptr);  // Display updated string and address
    } else {
        printf("Failed to append the string.\n");
    }

    return 0;
}

