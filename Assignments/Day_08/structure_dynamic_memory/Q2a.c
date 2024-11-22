/* DESCRIPTION : program to manipulate student records by searching, updating, deleting, and copying
   Date : 7-11-2024
   Name : Tirupati Pavani
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

struct student {
    char *name;
    int percentage;
};

// Function to search for a name and replace it with a user-defined name
char *search_update(char *searchstr, char *replacestr, struct student *records, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].name, searchstr) == 0) {
            free(records[i].name);
            records[i].name = strdup(replacestr);
            return records[i].name;
        }
    }
    return NULL;
}

// Function to search and delete a record with a given name or percentage
int delete_record(char *searchstr, int percent, struct student **records, int *count) {
    for (int i = 0; i < *count; i++) {
        if (strcmp((*records)[i].name, searchstr) == 0 || (*records)[i].percentage == percent) {
            free((*records)[i].name);
            for (int j = i; j < *count - 1; j++) {
                (*records)[j] = (*records)[j + 1];
            }
            (*records) = realloc(*records, (*count - 1) * sizeof(struct student));
            (*count)--;
            return SUCCESS;
        }
    }
    return FAILURE;
}

// Function to search for a name and create a copy of the record if found
int copy(char *name, struct student **newstudent, struct student *records, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            *newstudent = malloc(sizeof(struct student));
            (*newstudent)->name = strdup(records[i].name);
            (*newstudent)->percentage = records[i].percentage;
            return SUCCESS;
        }
    }
    return FAILURE;
}

// Helper function to display records
void display_records(struct student *records, int count) {
    for (int i = 0; i < count; i++) {
        printf("Record %d: Name: %s, Percentage: %d\n", i + 1, records[i].name, records[i].percentage);
    }
}

// Main function to test the functionalities
int main() {
    int record_count = 3;
    struct student *records = malloc(record_count * sizeof(struct student));

    // Initializing records
    records[0].name = strdup("user1");
    records[0].percentage = 90;
    records[1].name = strdup("user2");
    records[1].percentage = 80;
    records[2].name = strdup("user3");
    records[2].percentage = 70;

    printf("Initial Records:\n");
    display_records(records, record_count);

    // Testing search and update
    printf("\nUpdating 'user2' to 'user22':\n");
    char *updated_name = search_update("user2", "user22", records, record_count);
    if (updated_name) {
        printf("Name updated to: %s\n", updated_name);
    } else {
        printf("Name not found for update.\n");
    }
    display_records(records, record_count);

    // Testing delete
    printf("\nDeleting record with name 'user22':\n");
    if (delete_record("user22", -1, &records, &record_count) == SUCCESS) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record not found for deletion.\n");
    }
    display_records(records, record_count);

    // Testing copy
    printf("\nCopying record with name 'user3':\n");
    struct student *copied_record = NULL;
    if (copy("user3", &copied_record, records, record_count) == SUCCESS) {
        printf("Copied Record: Name: %s, Percentage: %d\n", copied_record->name, copied_record->percentage);
        free(copied_record->name);
        free(copied_record);
    } else {
        printf("Record not found for copying.\n");
    }

    // Free memory
    for (int i = 0; i < record_count; i++) {
        free(records[i].name);
    }
    free(records);

    return 0;
}

