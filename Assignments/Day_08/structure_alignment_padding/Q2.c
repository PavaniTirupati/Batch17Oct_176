/************************************************************************
 *	A demo program which sets module name and port count to fixed values
 *  Then retrieves and displays the set values using get_portcount() and 
 *  get_module() functions. Fixed errors in get_portcount.
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MODULE_LENGTH   10
#define FAILURE             1
#define SUCCESS             0
#define MAX_MODULE_NAME     20

// Macro for safe free
#define FREE(x)        \
    if (x)             \
    {                  \
        free(x);       \
        x = NULL;      \
    }

// Configuration structure
typedef struct config
{
    char *module;
    int portcount;
} CONFIG;

// Set the configuration
int setconfig(CONFIG *cfg, int portcnt, char *mname)
{
    int ret = FAILURE;

    cfg->module = (char *)malloc(sizeof(char) * (strlen(mname) + 1));
    if (cfg->module)
    {
        strcpy(cfg->module, mname);
        cfg->portcount = portcnt;

        printf("\nsetconfig: module: %s, portcount: %d\n", cfg->module, cfg->portcount);
        ret = SUCCESS;
    }
    return ret;
}

// Displays the contents of the pointer in hex bytes
void dump_hex(char *buf, size_t sz)
{
    size_t i = 0;
    char *ptr = buf;

    printf("\nDump_hex:\n");
    for (i = 0; i < sz; i++)
    {
        printf("%02x ", *(ptr + i));
    }
    printf("\nEnd of Data, sz: %d, i: %d\n", (int)sz, (int)i);
}

// Retrieve the port count
int get_portcount(void *cfg)
{
    CONFIG *cfgp = (CONFIG *)cfg;
    int portcnt = cfgp->portcount; // Direct access to portcount field
    printf("\nget_portcount: port: %d\n", portcnt);
    return portcnt;
}

// Retrieve the module
char *get_module(void *cfg)
{
    CONFIG *cfgp = (CONFIG *)cfg;
    char *module = (char *)cfgp->module;

    if (module)
    {
        printf("\nget_module: %s\n", module);
    }
    return module;
}

// Displays the contents of the CONFIG structure
void displ(void *cfg)
{
    int portcnt = get_portcount(cfg);
    char *mod = get_module(cfg);

    printf("\nReading config: Module: %s, Portcount: %d\n", mod, portcnt);
}

int main()
{
    CONFIG *cfg = NULL;
    int ret = FAILURE;

    // Allocate and initialize the config structure
    cfg = (CONFIG *)malloc(sizeof(CONFIG));
    if (cfg == NULL)
    {
        printf("\nMemory allocation failed\n");
        exit(FAILURE);
    }
    memset(cfg, 0, sizeof(CONFIG));

    // Set the configuration
    printf("\nTo set the config: module: DNS, portcount: 20\n");
    ret = setconfig(cfg, 20, "DNS");

    if (ret == SUCCESS)
    {
        // Display the current configuration
        displ(cfg);
    }
    else
    {
        printf("\nFailed to set the configuration\n");
    }

    // Free allocated memory
    FREE(cfg->module);
    FREE(cfg);

    return SUCCESS;
}

