/***************************************************************************
*	FILENAME : pack_error.c
*	DESCRIPTION: Demo code for packing error. The program reads and displays the
* 	configuration from an array, for each configuration, 
*	calls a function from utility.c to update
* 	the configuration parameters which  meets the given condition (i.e with module prefix = 'F')
*	As part of configuration update, it should update the prefix from F->G
*	and increment port count by 1.
*****************************************************************************/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<errno.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<fcntl.h>

#include "utility.h"

// Ensure proper packing to prevent alignment issues
#pragma pack(1)

// Configuration parameters of module
typedef struct config
{
	int con;       // Connection count
	char prefix;   // Prefix character
	short port;    // Port number
} CONFIG;

#pragma pack() // Reset default alignment

// Array of configuration of various modules
static CONFIG cfg_arr[] = {
	{10, 'C', 0x1A20},
	{20, 'F', 0x1A20}
};

// Display the contents of the CONFIG structure
void display_config(CONFIG cfg)
{
	printf("\nConfig is:");
	printf("\ncon: %d, prefix: %c, port: %x\n", cfg.con, cfg.prefix, cfg.port);
}

// Read and display the configuration from the array
static int read_config()
{
	int i = 0;
	int max = sizeof(cfg_arr) / sizeof(cfg_arr[0]);

	for (i = 0; i < max; i++)
	{
		display_config(cfg_arr[i]);
	}
	return SUCCESS;
}

/*
 * Check the configuration module prefix. If it is 'F', change it to 'G' and
 * also increment port count by 1.
 */
static int update_config()
{
	int i = 0;
	int max = sizeof(cfg_arr) / sizeof(cfg_arr[0]);

	for (i = 0; i < max; i++)
	{
		update_params(&cfg_arr[i]); // Update using utility function
	}

	return SUCCESS;
}

/*
 * Display the initial configuration and update the configuration of module
 * with prefix as 'F' (i.e., prefix and port count).
 */
int main(int argc, char *argv[])
{
	printf("Initial Configuration:\n");
	read_config();

	printf("\nUpdating Configuration:\n");
	update_config();

	printf("\nUpdated Configuration:\n");
	read_config();

	return SUCCESS;
}

