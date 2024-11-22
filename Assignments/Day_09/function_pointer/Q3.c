/* DESCRIPTION: Program to invoke a function pointer to a calculator function 
   and pass an integer value with user input for the second argument.
   Date: 2024-11-22
   Name: Tirupati Pavani
*/

#include <stdio.h>

// Function definitions
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return y != 0 ? x / y : 0; } // Avoid divide by zero

// Function to invoke any function pointer
int invokefunc(int (*func)(int, int), int val1) {
    int val2;
    printf("Enter the second integer: ");
    scanf("%d", &val2);
    return func(val1, val2);
}

// Main function
int main() {
    char operation;
    int val1 = 10, result = 0;
    int (*func_ptr)(int, int) = NULL;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Assign the appropriate function pointer
    switch (operation) {
        case '+': func_ptr = add; break;
        case '-': func_ptr = sub; break;
        case '*': func_ptr = multiply; break;
        case '/': func_ptr = divide; break;
        default:
            printf("Invalid operation!\n");
            return 1;
    }

    // Invoke the function and display the result
    result = invokefunc(func_ptr, val1);
    printf("Result: %d\n", result);

    return 0;
}

