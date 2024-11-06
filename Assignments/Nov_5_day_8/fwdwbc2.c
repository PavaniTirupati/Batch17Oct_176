#include <stdio.h>

 int main() {
     int N, num;
     int positive_count = 0, negative_count = 0, zero_count = 0;
     int result;

     printf("Enter the number of integers (N): ");
     while (scanf("%d", &N) != 1) {
         printf("Invalid input. Please enter an integer for N: ");
         while (getchar() != '\n');
     }

     for (int i = 0; i < N; i++) {
         printf("Enter integer %d: ", i + 1);
         while ((result = scanf("%d", &num)) != 1) {
             printf("Invalid input. Please enter an integer: ");
             while (getchar() != '\n');
         }

         if (num > 0) {
             positive_count++;
         } else if (num < 0) {
             negative_count++;
         } else {
             zero_count++;
         }
     }

     printf("Positive numbers: %d\n", positive_count);
     printf("Negative numbers: %d\n", negative_count);
     printf("Zeros: %d\n", zero_count);

     return 0;
 }

