/***************************************************************************
 *  FILENAME     : functions.c
 *  DESCRIPTION  : Contains the hash table function implementations
 *  DATE         : 2024-11-24
 *  NAME         : Tirupati Pavani
 ***************************************************************************/

#include "header.h"

/* Hash function to calculate index based on string key */
int hash(char *str) {
    int sum = 0;
    while (*str) {
        sum += *str++;
    }
    return sum % HASH_TABLE_SIZE;
}

/* Add a string to the hash table */
int add_to_hash(char *str) {
    int key = hash(str);
    HashNode *current = hash_table[key];
    while (current) {
        if (strcmp(current->key, str) == 0) {
            current->frequency++;
            return 1; // Incremented frequency
        }
        current = current->next;
    }

    // If not found, add a new node
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        return 0;
    }
    new_node->key = strdup(str);
    new_node->frequency = 1;
    new_node->next = hash_table[key];
    hash_table[key] = new_node;
    return 1; // Successfully added
}

/* Get the frequency of a string */
int get_frequency(char *str) {
    int key = hash(str);
    HashNode *current = hash_table[key];
    while (current) {
        if (strcmp(current->key, str) == 0) {
            return current->frequency;
        }
        current = current->next;
    }
    return 0; // Not found
}

/* Display the contents of the hash table */
void display_hash_table() {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        HashNode *current = hash_table[i];
        while (current) {
            printf("(%s, %d) -> ", current->key, current->frequency);
            current = current->next;
        }
        printf("NULL\n");
    }
}

/* Free all memory allocated for the hash table */
void free_hash_table() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashNode *current = hash_table[i];
        while (current) {
            HashNode *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
        hash_table[i] = NULL;
    }
}

