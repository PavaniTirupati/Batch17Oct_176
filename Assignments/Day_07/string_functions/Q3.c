#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 40

void replace_vowels(char *word) {
    char result[MAX_WORD_LEN * 3] = ""; // Allocate space for "ay" replacements
    char *ptr = word;

    while (*ptr) {
        if (strchr("aeiouAEIOU", *ptr)) {
            strncat(result, "ay", 2); // Append "ay" for vowels
        } else {
            strncat(result, ptr, 1); // Append the consonant
        }
        ptr++;
    }

    strcpy(word, result); // Update the original word
}

int main() {
    char word[MAX_WORD_LEN];

    printf("Enter a word (max length %d): ", MAX_WORD_LEN);
    scanf("%s", word);

    replace_vowels(word);
    printf("Updated word: %s\n", word);

    return 0;
}

