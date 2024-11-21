#include <stdio.h>

// Define a typedef structure for Putty server configuration
typedef struct {
    char serverName[100];
    char ipAddress[15];    // IP address in the format x.x.x.x
    int port;              // Port number
    int connectionTimeout; // Timeout in seconds
    char protocol[10];     // Protocol type (e.g., SSH, Telnet)
} PuttyServerConfig;

int main() {
    // Create a structure variable and initialize with user-defined values
    PuttyServerConfig config = {
        "PuttyServer01",      // Server name
        "192.168.1.10",       // IP address
        22,                   // Port number
        60,                   // Connection timeout (in seconds)
        "SSH"                 // Protocol type
    };

    // Display the configuration
    printf("Putty Server Configuration:\n");
    printf("Server Name: %s\n", config.serverName);
    printf("IP Address: %s\n", config.ipAddress);
    printf("Port: %d\n", config.port);
    printf("Connection Timeout: %d seconds\n", config.connectionTimeout);
    printf("Protocol: %s\n", config.protocol);

    return 0;
}

