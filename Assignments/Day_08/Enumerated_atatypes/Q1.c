#include <stdio.h>

// Define enum for designations
enum Designation {
    E2F = 1, // Software Fresher
    E2,       // Software Engineer
    E3,       // Senior Software Engineer
    E4,       // Team Lead
    E5        // Senior Team Lead
};

// Function to get designation string
const char* getDesignationString(enum Designation designation) {
    switch(designation) {
        case E2F: return "Software Fresher";
        case E2: return "Software Engineer";
        case E3: return "Senior Software Engineer";
        case E4: return "Team Lead";
        case E5: return "Senior Team Lead";
        default: return "Unknown";
    }
}

int main() {
    int inputDesignation;
    
    // Prompt and read the designation from the user
    printf("Enter designation number (1 for E2F, 2 for E2, 3 for E3, 4 for E4, 5 for E5): ");
    scanf("%d", &inputDesignation);
    
    // Validate input
    if (inputDesignation >= E2F && inputDesignation <= E5) {
        enum Designation userDesignation = (enum Designation)inputDesignation;
        printf("Designation: %d\n", userDesignation);
        printf("Designation String: %s\n", getDesignationString(userDesignation));
    } else {
        printf("Invalid designation number!\n");
    }

    return 0;
}

