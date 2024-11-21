/*************************************************************************
*
*  FILE NAME    : custom_strncat.c
*
*  DESCRIPTION  : Implementation of custom strncat function.
*
*  DATE      NAME            REFERENCE          REASON
*
*  19-NOV-24 Tirupati Pavani                     Initial creation
*
**************************************************************************/
#include <stdio.h>
#include <string.h>

/*************************************************************************
*       Function Name   : custom_strncat
*       Description     : Concatenate `n` characters from src to dest
*       Input           : Destination string, Source string, Number of characters
*       Returns         : Pointer to destination string
*************************************************************************/
char *custom_strncat(char *dest, const char *src, size_t n) {
    char *ptr = dest + strlen(dest); /* Move pointer to end of dest */
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        *ptr++ = src[i];
    }

    *ptr = '\0'; /* Null-terminate dest */
    return dest;
}

/*************************************************************************
*       Function Name   : main
*       Description     : Main function to demonstrate custom_strncat
*       Returns         : Success or Failure
*************************************************************************/
int main() {
    char dest[50] = "Hello, ";
    char src[] = "World!";
    size_t n = 3;

    printf("Before concatenation: %s\n", dest);
    custom_strncat(dest, src, n);
    printf("After concatenation: %s\n", dest);

    return 0;
}

