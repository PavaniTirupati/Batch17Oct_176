/* DESCRIPTION : Program to implement a log() function to handle variable arguments and print formatted outputs
   Date : 12-11-2024
   Name : Tirupati Pavani
*/

#include <stdio.h>
#include <stdarg.h>

// Log function to display all input arguments as per their type
void log(const char *format, ...) {
    va_list args;
    va_start(args, format);

    vfprintf(stdout, format, args);
    va_end(args);
}

int main() {
    int count = 10;
    char prefix = 'h';
    char label[] = "India";

    // Example usage of log()
    log("count:%d, prefix:%c, label:%s\n", count, prefix, label);

    return 0;
}

