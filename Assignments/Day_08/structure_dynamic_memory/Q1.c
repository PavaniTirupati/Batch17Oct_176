#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Define structure for student records
struct student {
    char *name;       // Pointer for dynamically allocated name
    float percentage; // Percentage field
};

// Function prototypes
struct student *parse_records(const char *input, int *record_count);
void display_records(const struct student *records, int record_count);
void free_records(struct student *records, int record_count);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s \"name1,percent1;name2,percent2;...\"\n", argv[0]);
        return 1;
    }

    int record_count = 0;
    struct student *records = parse_records(argv[1], &record_count);

    if (records == NULL) {
        printf("Error parsing records.\n");
        return 1;
    }

    // Display parsed records
    printf("No. of records: %d\n", record_count);
    display_records(records, record_count);

    // Free allocated memory
    free_records(records, record_count);

    return 0;
}

// Function to parse the input string and populate an array of student records
struct student *parse_records(const char *input, int *record_count) {
    char *input_copy = strdup(input); // Create a modifiable copy of the input
    if (!input_copy) {
        printf("Memory allocation failed for input copy.\n");
        return NULL;
    }

    // Count the number of records
    *record_count = 0;
    for (const char *ptr = input; *ptr; ptr++) {
        if (*ptr == ';') {
            (*record_count)++;
        }
    }
    (*record_count)++; // Add one for the last record without a trailing semicolon

    // Allocate memory for records
    struct student *records = (struct student *)malloc(*record_count * sizeof(struct student));
    if (!records) {
        printf("Memory allocation failed for records.\n");
        free(input_copy);
        return NULL;
    }

    // Tokenize the input string by semicolons
    char *token = strtok(input_copy, ";");
    int index = 0;

    while (token != NULL && index < *record_count) {
        // Tokenize each record by commas
        char *name = strtok(token, ",");
        char *percent_str = strtok(NULL, ",");

        if (name && percent_str) {
            // Allocate memory for name
            records[index].name = strdup(name);
            if (!records[index].name) {
                printf("Memory allocation failed for name.\n");
                free(input_copy);
                free_records(records, index);
                return NULL;
            }
            records[index].percentage = atof(percent_str); // Convert percentage to float
        } else {
            printf("Invalid record format: %s\n", token);
            free(input_copy);
            free_records(records, index);
            return NULL;
        }

        token = strtok(NULL, ";");
        index++;
    }

    free(input_copy);
    return records;
}

// Function to display student records
void display_records(const struct student *records, int record_count) {
    for (int i = 0; i < record_count; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("Name: %s, Percentage: %.2f\n", records[i].name, records[i].percentage);
    }
}

// Function to free allocated memory for student records
void free_records(struct student *records, int record_count) {
    for (int i = 0; i < record_count; i++) {
        free(records[i].name); // Free memory allocated for name
    }
    free(records); // Free the array of records
}

