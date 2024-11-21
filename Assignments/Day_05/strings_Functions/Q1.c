/*************************************************************************
*
*  FILE NAME    : string_tokenise.c
*
*  DESCRIPTION  : Tokenize a line of text into words and display them.
*
*  DATE      NAME            REFERENCE          REASON
*
*  19-NOV-24 Tirupati Pavani                     Initial creation
*
**************************************************************************/
#include <stdio.h>
#include <string.h>

/*************************************************************************
*       Function Name   : tokenise
*       Description     : Tokenize and display tokens
*       Input           : A string of text
*       Returns         : Number of tokens
*************************************************************************/
int tokenise(char *arr) {
    char *token;
    int count = 0;

    /* Tokenizing the string */
    token = strtok(arr, " ");
    while (token != NULL) {
        printf("Token: %s\n", token);
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

/*************************************************************************
*       Function Name   : main
*       Description     : Main function to demonstrate tokenisation
*       Returns         : Success or Failure
*************************************************************************/
int main() {
    char input[256];
    int token_count;

    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin);

    /* Removing newline character if present */
    input[strcspn(input, "\n")] = '\0';

    token_count = tokenise(input);
    printf("Number of tokens: %d\n", token_count);

    return 0;
}

