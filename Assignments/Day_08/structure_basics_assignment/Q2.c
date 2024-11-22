/* DESCRIPTION : Program to handle an array of employee structures
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
void free_employee_memory(EMP *emp);

int main() {
    int i, num_employees = 3;
    EMP employees[num_employees]; // Array of structures

    // Read details for each employee
    printf("\nReading Employee Details for %d Employees:\n", num_employees);
    for (i = 0; i < num_employees; i++) {
        printf("\nEmployee %d:\n", i + 1);
        read(&employees[i]);
    }

    // Display details for each employee
    printf("\nDisplaying Employee Details for %d Employees:\n", num_employees);
    for (i = 0; i < num_employees; i++) {
        printf("\nEmployee %d:\n", i + 1);
        display(employees[i]);
    }

    // Free allocated memory
    for (i = 0; i < num_employees; i++) {
        free_employee_memory(&employees[i]);
    }

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

// Function to free dynamically allocated memory for an employee
void free_employee_memory(EMP *emp) {
    free(emp->name);
    emp->name = NULL; // Avoid dangling pointer
}

