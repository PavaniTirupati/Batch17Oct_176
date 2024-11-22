#include <stdio.h> // Required for printf and scanf
#include <stdlib.h> // Required for NULL

// Function definitions
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return y != 0 ? x / y : 0; } // Avoid divide by zero

// Function to return function pointer based on input character
int (*getaddr(char mychar))(int, int) {
    switch (mychar) {
        case '+': return add;
        case '-': return sub;
        case '*': return multiply;
        case '/': return divide;
        default: return NULL;
    }
}

// Main function
int main() {
    char input;
    int x, y, result = 0;
    int (*operation)(int, int) = NULL;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &input);
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    // Get function pointer
    operation = getaddr(input);
    if (operation == NULL) {
        printf("Invalid operation!\n");
        return 1;
    }

    // Invoke function using the pointer
    result = operation(x, y);
    printf("Result: %d\n", result);

    return 0;
}

