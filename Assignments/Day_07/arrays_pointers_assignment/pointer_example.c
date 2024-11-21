#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[] = "ABC";

    // Fix 1: No need for explicit cast
    char *ptr = arr;  
    printf("%p %p", (void*)arr, (void*)ptr); // Cast to (void*) to avoid warnings in printf
    printf("\n 1 %c %c", *ptr, *(ptr+1));

    char msg[][5] = {"AB", "gh", "er"};
    
    // Fix 2: Correct the pointer type to match msg's type
    char (*ptr2)[5];
    
    ptr2 = msg; // No need for &msg[0], msg decays to pointer to first element
    printf("\n%p %p", (void*)msg, (void*)ptr2);
    printf("\n 2 %c %c", (*ptr2)[0], (*ptr2)[1]);

    return 0;
}

