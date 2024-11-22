/*************************************************************************
*  FILE NAME    : find_max.c
*  DESCRIPTION  : Finds out the maximum of set arguments. It demonstrates
*                 how stdarg macros are used to implement functions with
*                 variable number of arguments, including finding the
*                 longest string.
*  DATE      NAME    REFERENCE          REASON
*  7-NOV-2024  Tirupati Pavani  Assignment         Added max_len_string
**************************************************************************/
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/*****************************************************************************
*                       MACROS
*****************************************************************************/
#define MAX 10
#define END "END"

/*****************************************************************************
*                       FUNCTION PROTOTYPES
*****************************************************************************/
static int args_maximum(int, ...);
char *max_len_string(const char *, ...);

/**************************************************************************
* FUNCTION NAME: args_maximum
* DESCRIPTION: Finds out the maximum of integer arguments
* RETURNS: Maximum integer from the arguments
**************************************************************************/
int args_maximum(int first_val, ...) {
    va_list arg_list; 
    int temp = 0, maximum = first_val;  

    va_start(arg_list, first_val);

    while ((temp = va_arg(arg_list, int)) != END) {
        if (temp > maximum) {
            maximum = temp;
        }
    }

    va_end(arg_list);
    return maximum;
}

/**************************************************************************
* FUNCTION NAME: max_len_string
* DESCRIPTION: Finds the string with the maximum length among variable arguments
* RETURNS: Pointer to the string with maximum length
**************************************************************************/
char *max_len_string(const char *first_str, ...) {
    va_list arg_list;
    const char *current_str = first_str;
    const char *max_str = first_str;

    va_start(arg_list, first_str);

    while (strcmp(current_str, END) != 0) {
        if (strlen(current_str) > strlen(max_str)) {
            max_str = current_str;
        }
        current_str = va_arg(arg_list, const char *);
    }

    va_end(arg_list);
    return (char *)max_str;
}

/******************************************************************************
* FUNCTION NAME   : main
* DESCRIPTION     : Calls the max functions and displays the result 
* RETURNS         : Success or Failure
*******************************************************************************/
int main() {
    char *ptr = max_len_string("hi", "hello", "How", " Are", "END");

    printf("The string with maximum length is: %s\n", ptr);

    return 0;
}

