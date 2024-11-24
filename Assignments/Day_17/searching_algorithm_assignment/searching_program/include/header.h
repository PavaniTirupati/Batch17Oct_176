/******************************************************************
 *	FILE_NAME   : header.h
 * 	DESCRIPTION : the file contains the header files,
 *                     macro definitions, and function prototypes
 ******************************************************************/

/**********************HEADER_FILES*********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************
 * 			  MACRO DEFINITIONS
 * **************************************************************************/
#define MAX 100
#define SIZE 200
#define SUCCESS 1
#define FAILURE 0

/********************************************************************
 * 		FUNCTION_PROTOTYPES
 * *****************************************************************/
int get_line(char *array[], int i);
int binary_search(char *array[], char *find, int n);
int bubble_sort(char *array[], int n);
void delete_line(char *array[], int *n, int index);
void write_to_file(char *array[], int n, const char *filename);

