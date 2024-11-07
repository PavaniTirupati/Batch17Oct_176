/* 
File : A3.c
DESCRIPTION : program to find the  n-th number made of prime digits
Date : 7-11-2024
Name : Tirupati Pavani
*/

#include <stdio.h>

void findNthNumber(int N);
int main() {
    int T, N;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);
    for (int i=0;i<T;i++) {
        printf("Enter the value of N: ");
        scanf("%d", &N);
        findNthNumber(N);
    }

    return 0;
}

void findNthNumber(int N) 
{
    int primeDigits[] = {2, 3, 5, 7};
    int result[10]; 
    int index = 0;
    while (N>0) 
    {
        int remainder = (N - 1) % 4;  
        result[index++] = primeDigits[remainder]; 
        N = (N-1)/4;  
    }

    printf("The %d-th number made of prime digits is: ", N);
    for (int i=index-1;i>=0;i--) {
        printf("%d", result[i]);  
    }
    printf("\n");
}

