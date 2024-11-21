#include <stdio.h>

// Define a structure to store Person details
struct Person {
    char name[100];   // Name of the person (max 100 characters)
    unsigned int age; // Age of the person (max 100)
};

int main() {
    struct Person person1;
    
    // Assign values to the person details
    snprintf(person1.name, sizeof(person1.name), "John Doe"); // Assign name
    person1.age = 30; // Assign age

    // Display person details
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);

    return 0;
}

