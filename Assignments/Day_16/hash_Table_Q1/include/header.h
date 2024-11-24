/***************************************************************************
 * 	FILENAME     :    header.h
 * 	DESCRIPTION  :    Contains the node structure definition,
 *                        header files, and function prototypes.
 *      DATE       NAME         REFERENCE      REASON
 *     -------------------------------------------------
 *
 *     Copyright @2015 Aricent
 **************************************************************************/
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************
 *		MACRO_DEFINITIONS
 ************************************************************************/
#define MAX 32
#define HASH_TABLE_SIZE 10
#define SUCCESS 1
#define FAILURE 0

/***************************************************************************
 *		STRUCTURE_DEFINITION
 *************************************************************************/
typedef struct node {
    char *str;
    int count;
    struct node *next;
} HT_node;

/*******************************************************************
 * FUNCTION_PROTOTYPES
 ***********************************************************************/
int Fopen(FILE **, char *, char *);
int Fclose(FILE **);
int read_file(FILE *, HT_node **);
int write_file(FILE *, HT_node **);
int hash_function(char *);
int free_hash(HT_node **);
HT_node *addnew_node(char *);
HT_node *search_node(int, char *, HT_node **);

#endif /* HEADER_H */

