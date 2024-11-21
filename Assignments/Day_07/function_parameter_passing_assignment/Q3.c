#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 80

// Function to extract and return the username from the email ID
char *getuser(char input[]) {
    static char username[MAX_LENGTH];
    char *atSign = strchr(input, '@');  // Find the '@' symbol in the email

    if (atSign == NULL) {
        return NULL;  // Invalid email format
    }

    int len = atSign - input;  // Calculate length of the username
    if (len == 0) {
        return NULL;  // Username cannot be empty
    }

    strncpy(username, input, len);  // Copy the username part
    username[len] = '\0';  // Null-terminate the string

    return username;  // Return the username
}

// Function to extract and return the host from the email ID
char *gethost(char input[]) {
    static char host[MAX_LENGTH];
    char *atSign = strchr(input, '@');  // Find the '@' symbol in the email

    if (atSign == NULL) {
        return NULL;  // Invalid email format
    }

    char *dot = strchr(atSign + 1, '.');  // Find the first dot after the '@'
    if (dot == NULL) {
        return NULL;  // Invalid format: no dot after the '@'
    }

    int len = dot - (atSign + 1);  // Calculate length of the host
    if (len == 0) {
        return NULL;  // Host cannot be empty
    }

    strncpy(host, atSign + 1, len);  // Copy the host part
    host[len] = '\0';  // Null-terminate the string

    return host;  // Return the host
}

// Function to extract and return the domain name from the email ID
char *getdomain(char input[]) {
    static char domain[MAX_LENGTH];
    char *dot = strrchr(input, '.');  // Find the last dot in the email

    if (dot == NULL) {
        return NULL;  // Invalid email format
    }

    if (dot == input + strlen(input) - 1) {
        return NULL;  // Domain cannot be empty (e.g., 'example@domain.')
    }

    strcpy(domain, dot + 1);  // Copy everything after the dot
    return domain;  // Return the domain
}

// Function to check if the domain is ".com" or ".edu"
int isValidDomain(char input[]) {
    char *domain = getdomain(input);

    if (domain == NULL) {
        return 0;  // Invalid domain
    }

    if (strcmp(domain, "com") == 0 || strcmp(domain, "edu") == 0) {
        return 1;  // Valid domain
    }

    return 0;  // Invalid domain
}

int main() {
    char email[MAX_LENGTH];
    
    printf("Enter your email address: ");
    fgets(email, MAX_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0;  // Remove the newline character

    // Validate and extract parts of the email
    char *username = getuser(email);
    char *host = gethost(email);
    char *domain = getdomain(email);
    int validDomain = isValidDomain(email);

    // Check if the email is valid
    if (username == NULL || host == NULL || domain == NULL || !validDomain) {
        printf("Invalid email address.\n");
    } else {
        printf("Valid email address.\n");
        printf("Username: %s\n", username);
        printf("Host: %s\n", host);
        printf("Domain: %s\n", domain);
    }

    return 0;
}

