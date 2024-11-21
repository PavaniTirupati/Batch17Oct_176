#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255
#define MAX_HOST_LENGTH 100
#define MAX_DOMAIN_LENGTH 50

// Structure to hold host and domain names
struct url {
    char *host;
    char *domain;
};

// Function to validate the URL
int isValidURL(char *url) {
    if (url == NULL) return 0;

    // Check for the "http://" or "https://" prefix
    if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0) {
        return 1;
    }
    return 0;
}

// Function to extract host name from the URL
char *gethost(char *url) {
    char *start = url;
    char *host_start = NULL;
    char *host_end = NULL;
    
    // Skip the "http://" or "https://" part
    if (strncmp(url, "http://", 7) == 0) {
        start = url + 7;
    } else if (strncmp(url, "https://", 8) == 0) {
        start = url + 8;
    }

    host_start = start;
    
    // Find the end of the host (i.e., the next '/')
    host_end = strchr(host_start, '/');
    if (host_end == NULL) {
        host_end = host_start + strlen(host_start);
    }
    
    // Allocate memory for the host name and copy it
    size_t len = host_end - host_start;
    char *host = (char *)malloc(len + 1);
    if (host == NULL) {
        printf("Memory allocation failed for host name.\n");
        exit(1);
    }
    strncpy(host, host_start, len);
    host[len] = '\0';

    return host;
}

// Function to extract domain name from the URL
char *getdomain(char *url) {
    char *host = gethost(url);
    
    // Find the last '.' in the host to determine the domain
    char *domain_start = strrchr(host, '.');
    if (domain_start == NULL) {
        free(host);
        return NULL;
    }
    
    // Allocate memory for the domain and copy it
    char *domain = (char *)malloc(strlen(domain_start + 1) + 1);
    if (domain == NULL) {
        printf("Memory allocation failed for domain name.\n");
        free(host);
        exit(1);
    }
    strcpy(domain, domain_start + 1);

    free(host);  // Free the host memory since it's no longer needed
    return domain;
}

// Function to display the structure contents
void display(struct url *obj) {
    if (obj != NULL) {
        printf("Host: %s\n", obj->host);
        printf("Domain: %s\n", obj->domain);
    }
}

// Function to free the dynamically allocated memory in the structure
void freeMemory(struct url *obj) {
    if (obj != NULL) {
        if (obj->host != NULL) {
            free(obj->host);
        }
        if (obj->domain != NULL) {
            free(obj->domain);
        }
    }
}

int main() {
    char url[MAX_URL_LENGTH];

    // Read URL from user
    printf("Enter the URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0;  // Remove the newline character

    // Validate the URL
    if (!isValidURL(url)) {
        printf("Invalid URL. The URL should start with 'http://' or 'https://'.\n");
        return 1;
    }

    // Create a URL structure and extract host and domain
    struct url *urlObj = (struct url *)malloc(sizeof(struct url));
    if (urlObj == NULL) {
        printf("Memory allocation failed for URL structure.\n");
        return 1;
    }

    urlObj->host = gethost(url);
    urlObj->domain = getdomain(url);

    // Display the extracted information
    display(urlObj);

    // Free the allocated memory
    freeMemory(urlObj);
    free(urlObj);

    return 0;
}

