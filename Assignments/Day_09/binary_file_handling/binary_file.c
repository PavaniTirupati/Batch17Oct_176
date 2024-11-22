/* DESCRIPTION: Fixed program to handle binary file operations with proper alignment.
   Date: 2024-11-22
   Name: Tirupati Pavani
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store name and age
typedef struct {
    char *name;    // Pointer to dynamically allocate name
    unsigned int age;
} Person;

#define FILENAME "out.bin"

void writeToFile(Person *persons, int count);
void readFromFile(int count);

int main() {
    int i, count = 2; // Number of entries
    Person persons[count];

    // Step 1: Read names and ages
    for (i = 0; i < count; i++) {
        persons[i].name = (char *)malloc(21 * sizeof(char)); // Allocate memory for name
        if (persons[i].name == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        printf("Enter name %d (max 20 chars): ", i + 1);
        scanf("%20s", persons[i].name); // Read name
        printf("Enter age %d: ", i + 1);
        scanf("%u", &persons[i].age);  // Read age
    }

    // Step 2: Write to binary file
    writeToFile(persons, count);

    // Step 3: Read from binary file and display
    readFromFile(count);

    // Step 4: Free allocated memory
    for (i = 0; i < count; i++) {
        free(persons[i].name);
    }

    return 0;
}

// Function to write names and ages to a binary file
void writeToFile(Person *persons, int count) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        unsigned int nameLength = strlen(persons[i].name) + 1; // Include null terminator

        // Write name length
        fwrite(&nameLength, sizeof(unsigned int), 1, file);
        // Write name
        fwrite(persons[i].name, sizeof(char), nameLength, file);
        // Write age
        fwrite(&persons[i].age, sizeof(unsigned int), 1, file);
    }

    fclose(file);
    printf("\nData successfully written to %s\n", FILENAME);
}

// Function to read names and ages from a binary file
void readFromFile(int count) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    printf("\nReading data from file:\n");
    for (int i = 0; i < count; i++) {
        unsigned int nameLength;
        char *name;
        unsigned int age;

        // Read name length
        fread(&nameLength, sizeof(unsigned int), 1, file);
        // Allocate memory for the name
        name = (char *)malloc(nameLength);
        if (name == NULL) {
            perror("Memory allocation failed");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        // Read name
        fread(name, sizeof(char), nameLength, file);
        // Read age
        fread(&age, sizeof(unsigned int), 1, file);

        // Display name and age
        printf("Name: %s, Age: %u\n", name, age);

        // Free allocated memory
        free(name);
    }

    fclose(file);
}

