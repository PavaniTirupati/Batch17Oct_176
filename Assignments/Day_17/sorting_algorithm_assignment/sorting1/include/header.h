/***************************************************************************
 * FILE NAME:     header.h
 * DESCRIPTION:   All declarations of the function for various sorting techniques
 * DATE           : 2024-11-24
 * NAME           : Tirupati Pavani
 ***************************************************************************/

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************************
 * MACRO DECLARATIONS
 ***************************************************************************/
#define MAX 30
#define SUCCESS 1
#define FAILURE 0

/***************************************************************************
 * FUNCTION DECLARATIONS
 ***************************************************************************/
void merge_sort(char *array[], int BEG, int END);
void display_array(char *array[], int n);

#endif

