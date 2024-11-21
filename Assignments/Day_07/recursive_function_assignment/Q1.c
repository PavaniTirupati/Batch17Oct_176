#include <stdio.h>

int maxDepth = 0; // Global variable to track maximum depth

void factorial_recursive(int n, int depth) {
    if (depth > maxDepth) {
        maxDepth = depth; // Update maximum depth
    }

    if (n == 0 || n == 1) {
        printf("Factorial computation completed at depth: %d\n", depth);
        return;
    }

    factorial_recursive(n - 1, depth + 1);
}

int main() {
    int num;

    printf("Enter a number to calculate factorial: ");
    scanf("%d", &num);

    factorial_recursive(num, 1);

    printf("Maximum stack depth reached: %d\n", maxDepth);

    return 0;
}

