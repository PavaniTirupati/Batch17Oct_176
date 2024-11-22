/* DESCRIPTION: Program to handle server configurations
   Date: 2024-11-22
   Name: Tirupati Pavani
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CFG 5      // Maximum number of configurations
#define MAX_LEN 50     // Maximum length of name

typedef struct config {
    char *ipaddress;   // Pointer to a dotted IP address string
    char name[MAX_LEN]; // Server name
    unsigned short port; // Port number
} CONFIG;

// Global arrays for input and output configurations
CONFIG cfgarr_in[MAX_CFG];
CONFIG cfgarr_out[MAX_CFG];

// Function Prototypes
int read_store_cfg(CONFIG cfgarr[], int count);
void display(CONFIG cfgarr[], int count);
void write_to_file(CONFIG cfgarr[], int count);
void read_from_file(CONFIG cfgarr[], int count);

int main() {
    int count;

    // Step 1: Read configurations
    printf("Enter the number of configurations (max %d): ", MAX_CFG);
    scanf("%d", &count);
    if (count > MAX_CFG || count <= 0) {
        printf("Invalid number of configurations.\n");
        return -1;
    }

    if (read_store_cfg(cfgarr_in, count) != 0) {
        printf("Failed to read configurations.\n");
        return -1;
    }

    // Step 2: Display input configurations
    printf("\nInput Configurations:\n");
    display(cfgarr_in, count);

    // Step 3: Write to binary file
    write_to_file(cfgarr_in, count);

    // Step 4: Read from binary file
    read_from_file(cfgarr_out, count);

    // Step 5: Display output configurations
    printf("\nOutput Configurations (Read from file):\n");
    display(cfgarr_out, count);

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(cfgarr_in[i].ipaddress);
        free(cfgarr_out[i].ipaddress);
    }

    return 0;
}

// Function to read and store configurations
int read_store_cfg(CONFIG cfgarr[], int count) {
    for (int i = 0; i < count; i++) {
        cfgarr[i].ipaddress = (char *)malloc(16 * sizeof(char)); // Allocate memory for IP address
        if (cfgarr[i].ipaddress == NULL) {
            perror("Memory allocation failed");
            return -1;
        }

        printf("Enter details for configuration %d:\n", i + 1);
        printf("IP Address (dotted notation): ");
        scanf("%15s", cfgarr[i].ipaddress);
        printf("Name: ");
        scanf("%49s", cfgarr[i].name);
        printf("Port: ");
        scanf("%hu", &cfgarr[i].port);
    }
    return 0;
}

// Function to display configurations
void display(CONFIG cfgarr[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Configuration %d:\n", i + 1);
        printf("IP Address: %s\n", cfgarr[i].ipaddress);
        printf("Name: %s\n", cfgarr[i].name);
        printf("Port: %hu\n", cfgarr[i].port);
    }
}

// Function to write configurations to a binary file
void write_to_file(CONFIG cfgarr[], int count) {
    FILE *file = fopen("out.bin", "wb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        unsigned int ipLen = strlen(cfgarr[i].ipaddress) + 1; // Include null terminator

        fwrite(&ipLen, sizeof(unsigned int), 1, file); // Write IP length
        fwrite(cfgarr[i].ipaddress, sizeof(char), ipLen, file); // Write IP address
        fwrite(cfgarr[i].name, sizeof(char), MAX_LEN, file);    // Write name
        fwrite(&cfgarr[i].port, sizeof(unsigned short), 1, file); // Write port
    }

    fclose(file);
    printf("\nData successfully written to out.bin\n");
}

// Function to read configurations from a binary file
void read_from_file(CONFIG cfgarr[], int count) {
    FILE *file = fopen("out.bin", "rb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        unsigned int ipLen;

        fread(&ipLen, sizeof(unsigned int), 1, file); // Read IP length
        cfgarr[i].ipaddress = (char *)malloc(ipLen);  // Allocate memory for IP address
        if (cfgarr[i].ipaddress == NULL) {
            perror("Memory allocation failed");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        fread(cfgarr[i].ipaddress, sizeof(char), ipLen, file); // Read IP address
        fread(cfgarr[i].name, sizeof(char), MAX_LEN, file);    // Read name
        fread(&cfgarr[i].port, sizeof(unsigned short), 1, file); // Read port
    }

    fclose(file);
}

