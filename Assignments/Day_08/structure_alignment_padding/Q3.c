/************************************************************************
 *  A demo program to demonstrate memory alignment issue and fix bus error.
 *  Allocates heap memory for the configuration structure, initializes it 
 *  with given parameters, and avoids memory alignment issues.
 *  Includes fixes for memory leaks.
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAILURE   1
#define SUCCESS   0

// Configuration structure of type A modules
typedef struct config_a
{
    int id;
    int pkgcount;
} CONFIG_A;

// Enables checking for alignment errors (if supported)
int enable_alignment_errors()
{
#if defined(__GNUC__)
# if defined(__i386__)
    /* Enable Alignment Checking on x86 */
    __asm__("pushf\norl $0x40000,(%esp)\npopf");
# elif defined(__x86_64__) 
    /* Enable Alignment Checking on x86_64 */
    __asm__("pushf\norl $0x40000,(%rsp)\npopf");
# endif
#endif
    return SUCCESS;
}

// Performs initialization
void init()
{
    enable_alignment_errors();
}

/*
 * Allocates memory for CONFIG_A, initializes it with given parameters,
 * and returns the pointer to the structure.
 */
CONFIG_A *set_config_a(int id, int pkgc)
{
    // Allocate memory for CONFIG_A
    CONFIG_A *config = (CONFIG_A *)malloc(sizeof(CONFIG_A));
    if (!config)
    {
        printf("Memory allocation failed!\n");
        exit(FAILURE);
    }

    // Initialize fields
    config->id = id;
    config->pkgcount = pkgc;

    // Display initialized values
    printf("\nset_config_a: id = %d, pkgcount = %d\n", config->id, config->pkgcount);

    return config;
}

// Test function to demonstrate usage of set_config_a
void testfunction()
{
    int id = 34;
    int pkg = 45;

    // Get configuration
    CONFIG_A *config = set_config_a(id, pkg);

    // Display configuration
    printf("\nConfiguration: id = %d, pkgcount = %d\n", config->id, config->pkgcount);

    // Free allocated memory
    free(config);
}

int main()
{
    // Initialize the system
    init();

    // Set configuration and test
    testfunction();

    return SUCCESS;
}

