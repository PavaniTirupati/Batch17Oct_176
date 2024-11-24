/***************************************************************************
 *  FILENAME     : header.h
 *  DESCRIPTION  : Contains the structure definitions and function prototypes
 *  DATE         : 2024-11-24
 *  NAME         : Tirupati Pavani
 ***************************************************************************/

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 10
#define MAX_STR_LEN 128

typedef struct HashNode {
    char *key;
    int frequency;
    struct HashNode *next;
} HashNode;

HashNode *hash_table[HASH_TABLE_SIZE]; // Global hash table

int hash(char *str);
int add_to_hash(char *str);
int get_frequency(char *str);
void display_hash_table();
void free_hash_table();

#endif

