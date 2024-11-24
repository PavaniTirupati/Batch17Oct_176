/***************************************************************************
 *  FILENAME     : main.c
 *  DESCRIPTION  : Main program to read strings from command-line arguments,
 *                 store in hash table, and display their frequencies
 *  DATE         : 2024-11-24
 *  NAME         : Tirupati Pavani
 ***************************************************************************/

#include "header.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string1> <string2> ...\n", argv[0]);
        return 1;
    }

    // Initialize the hash table
    memset(hash_table, 0, sizeof(hash_table));

    // Add each argument to the hash table
    for (int i = 1; i < argc; i++) {
        add_to_hash(argv[i]);
    }

    // Display the hash table
    display_hash_table();

    // Display the frequency of each string
    printf("\nFrequencies of input strings:\n");
    for (int i = 1; i < argc; i++) {
        printf("%s: %d\n", argv[i], get_frequency(argv[i]));
    }

    // Free the hash table
    free_hash_table();

    return 0;
}

