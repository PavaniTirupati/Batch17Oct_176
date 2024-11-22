/* DESCRIPTION: Program to define an array of function pointers for basic arithmetic
   operations and invoke them based on user input.
   Date: 2024-11-22
   Name: Tirupati Pavani
*/

#include <stdio.h>

// Function definitions
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return y != 0 ? x / y : 0; } // Avoid divide by zero

// Main function
int main() {
    char operation;
    int x, y, result = 0;
    
    // Array of function pointers
    int (*func_ptrs[4])(int, int) = {add, sub, multiply, divide};

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    // Select function based on operation
    switch (operation) {
        case '+': result = func_ptrs[0](x, y); break;
        case '-': result = func_ptrs[1](x, y); break;
        case '*': result = func_ptrs[2](x, y); break;
        case '/': result = func_ptrs[3](x, y); break;
        default:
            printf("Invalid operation!\n");
            return 1;
    }

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}

