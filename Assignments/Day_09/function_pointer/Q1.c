#include <stdio.h>

// Function declarations
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return y != 0 ? x / y : 0; } // Avoid divide by zero

// Main function
int main() {
    char input;
    int x, y, result = 0;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &input);
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    // Define function pointer
    int (*operation)(int, int) = NULL;

    // Map input to corresponding function
    switch (input) {
        case '+': operation = add; break;
        case '-': operation = sub; break;
        case '*': operation = multiply; break;
        case '/': operation = divide; break;
        default:
            printf("Invalid operation!\n");
            return 1;
    }

    // Invoke function using the pointer
    result = operation(x, y);
    printf("Result: %d\n", result);

    return 0;
}

