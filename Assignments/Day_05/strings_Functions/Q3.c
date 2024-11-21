/*************************************************************************
*
*  FILE NAME    : replace_vowels.c
*
*  DESCRIPTION  : Replaces vowels in a word with "ay".
*
*  DATE      NAME            REFERENCE          REASON
*
*  19-NOV-24 Tirupati Pavani                     Initial creation
*
**************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*************************************************************************
*       Function Name   : replace_vowels
*       Description     : Replace vowels in the input word with "ay".
*       Input           : Word from user
*       Returns         : None
*************************************************************************/
void replace_vowels(char *word) {
    char result[100] = ""; /* To store the updated string */
    char *ptr = result;

    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr("AEIOUaeiou", word[i]) != NULL) {
            *ptr++ = 'a'; /* Add 'a' */
            *ptr++ = 'y'; /* Add 'y' */
        } else {
            *ptr++ = word[i]; /* Copy the consonant */
        }
    }

    *ptr = '\0'; /* Null-terminate the result */
    printf("Updated string: %s\n", result);
}

/*************************************************************************
*       Function Name   : main
*       Description     : Main function to demonstrate replace_vowels
*       Returns         : Success or Failure
*************************************************************************/
int main() {
    char word[41];

    printf("Enter a word (max 40 characters): ");
    scanf("%40s", word);

    replace_vowels(word);

    return 0;
}

