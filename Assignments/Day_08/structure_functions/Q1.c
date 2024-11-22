#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char *name;          // Changed name to a pointer
    float percentage;
};

// Function prototypes
char *read_update_name(char *name);
float read_update_percentage(float *percentage);
void display_student(const struct student *record);
void free_student(struct student *record);

int main() {
    struct student record;
    record.id = 1;

    // Dynamically allocate memory for name
    record.name = (char *)malloc(100 * sizeof(char)); // Assuming max name length is 100
    if (!record.name) {
        printf("Memory allocation failed for name.\n");
        return 1;
    }

    // Read and update name
    printf("Enter name: ");
    read_update_name(record.name);

    // Read and update percentage
    printf("Enter percentage: ");
    read_update_percentage(&record.percentage);

    // Display student record
    display_student(&record);

    // Free allocated memory
    free_student(&record);

    return 0;
}

// Function to read and update name
char *read_update_name(char *name) {
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline
    return name;
}

// Function to read and update percentage
float read_update_percentage(float *percentage) {
    scanf("%f", percentage);
    return *percentage;
}

// Function to display student record
void display_student(const struct student *record) {
    printf("\n--- Student Record ---\n");
    printf("Id: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Percentage: %.2f\n", record->percentage);
}

// Function to free allocated memory for name
void free_student(struct student *record) {
    if (record->name) {
        free(record->name);
        record->name = NULL; // Avoid dangling pointer
    }
}

