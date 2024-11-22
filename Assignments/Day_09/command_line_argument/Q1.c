/* DESCRIPTION : Program to handle server configuration using command-line arguments and update functionality
   Date : 12-11-2024
   Name : Tirupati Pavani
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

#define SUCCESS 0
#define FAILURE -1
#define MAX_NAME_LEN 40
#define PORT_MIN 1024
#define PORT_MAX 65535

// Structure to hold server configuration
struct server {
    char name[MAX_NAME_LEN];
    char ip[INET_ADDRSTRLEN];
    unsigned short port;
};

// Function to display the server configuration
void display(struct server *servercfg) {
    printf("\nServer Configuration:\n");
    printf("Name: %s\n", servercfg->name);
    printf("IP Address: %s\n", servercfg->ip);
    printf("Port: %u\n", servercfg->port);
}

// Function to update server configuration
int update(struct server *servercfg) {
    printf("\nUpdating Server Configuration:\n");

    printf("Enter new name: ");
    if (scanf("%39s", servercfg->name) != 1) return FAILURE;

    printf("Enter new IP address: ");
    if (scanf("%15s", servercfg->ip) != 1 || inet_pton(AF_INET, servercfg->ip, NULL) != 1) return FAILURE;

    printf("Enter new port number: ");
    if (scanf("%hu", &servercfg->port) != 1 || servercfg->port < PORT_MIN || servercfg->port > PORT_MAX) return FAILURE;

    return SUCCESS;
}

// Function to validate the command-line arguments
int validate_arguments(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <name> <IP address> <port number>\n", argv[0]);
        return FAILURE;
    }

    if (strlen(argv[1]) >= MAX_NAME_LEN) {
        fprintf(stderr, "Error: Name exceeds maximum length (%d).\n", MAX_NAME_LEN);
        return FAILURE;
    }

    if (inet_pton(AF_INET, argv[2], NULL) != 1) {
        fprintf(stderr, "Error: Invalid IP address format.\n");
        return FAILURE;
    }

    int port = atoi(argv[3]);
    if (port < PORT_MIN || port > PORT_MAX) {
        fprintf(stderr, "Error: Port number must be between %d and %d.\n", PORT_MIN, PORT_MAX);
        return FAILURE;
    }

    return SUCCESS;
}

int main(int argc, char *argv[]) {
    struct server servercfg;

    // Validate command-line arguments
    if (validate_arguments(argc, argv) == FAILURE) {
        return FAILURE;
    }

    // Store validated values into the structure
    strncpy(servercfg.name, argv[1], MAX_NAME_LEN - 1);
    servercfg.name[MAX_NAME_LEN - 1] = '\0';
    strncpy(servercfg.ip, argv[2], INET_ADDRSTRLEN - 1);
    servercfg.ip[INET_ADDRSTRLEN - 1] = '\0';
    servercfg.port = (unsigned short)atoi(argv[3]);

    // Display initial configuration
    display(&servercfg);

    // Update configuration
    if (update(&servercfg) == SUCCESS) {
        printf("\nUpdated Configuration:\n");
        display(&servercfg);
    } else {
        fprintf(stderr, "Error updating configuration.\n");
    }

    return SUCCESS;
}

