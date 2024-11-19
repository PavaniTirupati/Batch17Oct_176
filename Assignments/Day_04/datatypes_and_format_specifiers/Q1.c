/* 
DESCRIPTION : Program to read user details and display them
Date : 05-11-2024
Name : Tirupati Pavani
*/

#include <stdio.h>

int main() {
    char username[126];  // Maximum length 125 (+1 for null terminator)
    int age;
    float salary;
    short designation;   // For values {1, 2, 3, 4, 5, 6}
    char gender;

    // Input from the user
    printf("Enter username (max 125 characters): ");
    scanf("%125s", username);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter salary: ");
    scanf("%f", &salary);
    printf("Enter designation code (1-6): ");
    scanf("%hd", &designation);
    printf("Enter gender (M/F): ");
    scanf(" %c", &gender);

    // Output
    printf("\nUser Information:\n");
    printf("Username: %s\n", username);
    printf("Age: %d\n", age);
    printf("Salary: %.2f\n", salary);
    printf("Designation Code: %hd\n", designation);
    printf("Gender: %c\n", gender);

    return 0;
}

