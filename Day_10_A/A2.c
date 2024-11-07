/* 
File : A2.c
DESCRIPTION : Program to find nth number made of given four digits 1, 4,6 and 9 as the only digits.
Date : 7-11-2024
Name : Tirupati Pavani
*/

#include <stdio.h>

void findNthNumber(int N);

int main() 
{
    int T, N;
    
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    for (int i = 0; i < T; i++) 
    {
        printf("Enter the value of N: ");
        scanf("%d", &N);

        findNthNumber(N);
    }

    return 0;
}

void findNthNumber(int N) 
{
    int digits[] = {1, 4, 6, 9};
    int result[10];  
    int index = 0;
    
    while (N > 0) 
    {
        int remainder = (N - 1) % 4;  
        result[index++] = digits[remainder];  
        N = (N - 1) / 4; 
    }

    printf("The %d-th number made of digits 1, 4, 6, 9 is: ", N);
    for (int i = index - 1; i >= 0; i--) 
    {
        printf("%d", result[i]); 
    }
    printf("\n");
    
}