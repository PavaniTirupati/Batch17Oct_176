/* DESCRIPTION : To print the triangle pattern
Date : 7-11-2024
Name : Tirupati Pavani
File : A1.c
*/

#include <stdio.h>

void alphabetTriangle(int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%*c", n - i + 1, ' ');
        for (int j = 1; j <= i; j++) 
        {
            printf("%c", 'A' + j - 1);
        }
        for (int j = i - 1; j >= 1; j--)
        {
            printf("%c", 'A' + j - 1);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of rows for the triangles: ");
    scanf("%d", &n);
    alphabetTriangle(n);
    printf("\n");
    printf("Number Triangle:\n");
    
    return 0;
}
