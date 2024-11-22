/* DESCRIPTION : Program to read, update, and display employee details
   Date : 7-11-2024
   Name : Tirupati Pavani
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum for employee designation
typedef enum {
    E2F = 1, // Software Fresher
    E2,      // Software Engineer
    E3,      // Senior Software Engineer
    E4,      // Team Lead
    E5       // Senior Team Lead
} Designation;

// Structure to store employee details
typedef struct {
    char *name; // Dynamically allocated
    unsigned int age;
    Designation designation;
} EMP;

// Function prototypes
void read(EMP *emp);
void display(EMP emp);
int update(EMP *emp);
EMP copy(EMP emp);

int main() {
    EMP employee;        // Single employee instance
    EMP copied_employee; // For testing the copy function

    // Read employee details
    printf("\nReading Employee Details:\n");
    read(&employee);

    // Display employee details
    printf("\nDisplaying Employee Details:\n");
    display(employee);

    // Update employee details
    printf("\nUpdating Employee Details:\n");
    if (update(&employee)) {
        printf("Employee record updated successfully!\n");
        display(employee);
    } else {
        printf("Update failed.\n");
    }

    // Copy employee details
    printf("\nCopying Employee Record:\n");
    copied_employee = copy(employee);
    printf("Copied Employee Details:\n");
    display(copied_employee);

    // Free allocated memory
    free(employee.name);
    free(copied_employee.name);

    return 0;
}

// Function to read employee details
void read(EMP *emp) {
    char buffer[51]; // Temporary buffer for name input

    printf("Enter name (max 50 characters): ");
    scanf(" %[^\n]", buffer);

    // Allocate memory for the name dynamically
    emp->name = (char *)malloc(strlen(buffer) + 1);
    if (!emp->name) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(emp->name, buffer);

    printf("Enter age: ");
    scanf("%u", &emp->age);

    printf("Enter designation (1 for E2F, 2 for E2, 3 for E3, 4 for E4, 5 for E5): ");
    int designation_input;
    scanf("%d", &designation_input);
    emp->designation = (Designation)designation_input;
}

// Function to display employee details
void display(EMP emp) {
    printf("Name: %s\n", emp.name);
    printf("Age: %u\n", emp.age);
    printf("Designation: ");
    switch (emp.designation) {
        case E2F: printf("Software Fresher\n"); break;
        case E2:  printf("Software Engineer\n"); break;
        case E3:  printf("Senior Software Engineer\n"); break;
        case E4:  printf("Team Lead\n"); break;
        case E5:  printf("Senior Team Lead\n"); break;
        default:  printf("Unknown\n");
    }
}

// Function to update employee details
int update(EMP *emp) {
    char buffer[51]; // Temporary buffer for name input

    printf("Update name (current: %s): ", emp->name);
    scanf(" %[^\n]", buffer);

    // Reallocate memory for the updated name
    char *new_name = (char *)realloc(emp->name, strlen(buffer) + 1);
    if (!new_name) {
        printf("Memory allocation failed!\n");
        return 0; // Failure
    }
    emp->name = new_name;
    strcpy(emp->name, buffer);

    printf("Update age (current: %u): ", emp->age);
    scanf("%u", &emp->age);

    printf("Update designation (current: ");
    switch (emp->designation) {
        case E2F: printf("E2F"); break;
        case E2:  printf("E2"); break;
        case E3:  printf("E3"); break;
        case E4:  printf("E4"); break;
        case E5:  printf("E5"); break;
        default:  printf("Unknown");
    }
    printf("): ");
    int designation_input;
    scanf("%d", &designation_input);
    emp->designation = (Designation)designation_input;

    return 1; // Success
}

// Function to copy employee details
EMP copy(EMP emp) {
    EMP new_emp;

    // Allocate memory for the name in the new structure
    new_emp.name = (char *)malloc(strlen(emp.name) + 1);
    if (!new_emp.name) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(new_emp.name, emp.name);

    // Copy other fields
    new_emp.age = emp.age;
    new_emp.designation = emp.designation;

    return new_emp;
}

