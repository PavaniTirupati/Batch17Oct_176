/***********************************************************************
*    FILENAME    : functions.c
*    DESCRIPTION : Contains file handling, hash table, and utility functions.
*
*    DATE         NAME          REFERENCE        REASON
*    -----------------------------------------------------
***************************************************************************/

/**************************HEADER FILE**************************************/
#include "header.h"

/**************************************************************************
*    	FUNCTION NAME  	: Fopen
*    	DESCRIPTION    	: Opens the file, If not found returns error
*	RETURN 		: SUCCESS/FAILURE
**************************************************************************/
int Fopen(FILE **fptr, char *filename, char *mode) {
    *fptr = fopen(filename, mode);
    if (NULL == (*fptr)) {
        return FAILURE;
    }
    return SUCCESS;
}

/**************************************************************************
*    	FUNCTION NAME  	: Fclose
*    	DESCRIPTION    	: Closes the file, If not found returns error
*	RETURN 		: SUCCESS/FAILURE
**************************************************************************/
int Fclose(FILE **fptr) {
    int ret = fclose(*fptr);
    return (ret != 0) ? FAILURE : SUCCESS;
}

/**************************************************************************
*    	FUNCTION NAME  	: read_file
*    	DESCRIPTION    	: Reads the file for each word and store in hash table
*	RETURN 		: SUCCESS/FAILURE
**************************************************************************/
int read_file(FILE *fptr, HT_node **hash_table) {
    char str[MAX];
    int key = 0;
    HT_node *ret_node;

    memset(str, 0, MAX);

    while (EOF != fscanf(fptr, "%s", str)) {
        key = hash_function(str);
        ret_node = search_node(key, str, hash_table);

        if (NULL == ret_node) {
            ret_node = addnew_node(str);
            if (NULL == ret_node) {
                return FAILURE;
            }

            if (NULL == hash_table[key]) {
                hash_table[key] = ret_node;
            } else {
                ret_node->next = hash_table[key];
                hash_table[key] = ret_node;
            }
        } else {
            ret_node->count += 1;
        }

        memset(str, 0, MAX);
    }
    return SUCCESS;
}

/**************************************************************************
*    	FUNCTION NAME  	: write_file
*    	DESCRIPTION    	: Reads the hash table and store words with frequency
*	RETURN 		: SUCCESS/FAILURE
**************************************************************************/
int write_file(FILE *fptr, HT_node **hash_table) {
    int index;
    HT_node *curr;

    for (index = 0; index < HASH_TABLE_SIZE; index++) {
        for (curr = hash_table[index]; NULL != curr; curr = curr->next) {
            if (fprintf(fptr, "%s %d\n", curr->str, curr->count) < 0) {
                return FAILURE;
            }
        }
    }
    return SUCCESS;
}

/**************************************************************************
*    	FUNCTION NAME  	: hash_function
*    	DESCRIPTION    	: Calculates index value
*	RETURN 		: SUCCESS/FAILURE
**************************************************************************/
int hash_function(char *str) {
    int index, sum = 0;
    for (index = 0; index < strlen(str); index++) {
        sum += str[index];
    }
    return sum % HASH_TABLE_SIZE;
}

/**************************************************************************
*     	FUNCTION NAME : addnew_node
*	DESCRIPTION   : Creates a new node
*	RETURN        : Address of new node (node*)
**************************************************************************/
HT_node *addnew_node(char *str) {
    HT_node *new = calloc(1, sizeof(HT_node));
    if (!new) {
        printf("Memory Allocation Failure\n");
        return NULL;
    }

    new->str = calloc(strlen(str) + 1, sizeof(char));
    if (!new->str) {
        printf("Memory Allocation Failure\n");
        free(new);
        return NULL;
    }

    strcpy(new->str, str);
    new->count = 1;
    new->next = NULL;
    return new;
}

/*************************************************************************
*     	FUNCTION NAME : search_node
*	DESCRIPTION   : Searches hash table for input word
*	RETURN        : Address of node found or NULL
**************************************************************************/
HT_node *search_node(int key, char *str, HT_node **hash_table) {
    HT_node *temp;
    for (temp = hash_table[key]; temp != NULL; temp = temp->next) {
        if (strcmp(temp->str, str) == 0) {
            return temp;
        }
    }
    return NULL;
}

/*************************************************************************
*     	FUNCTION NAME : free_hash
*	DESCRIPTION   : Frees hash table for allocated memory
*	RETURN        : SUCCESS/FAILURE
**************************************************************************/
int free_hash(HT_node **hash_table) {
    int index;
    HT_node *temp;

    for (index = 0; index < HASH_TABLE_SIZE; index++) {
        while (hash_table[index]) {
            temp = hash_table[index];
            hash_table[index] = temp->next;
            free(temp->str);
            free(temp);
        }
    }
    return SUCCESS;
}

