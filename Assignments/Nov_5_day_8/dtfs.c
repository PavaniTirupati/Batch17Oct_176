/*to read the following information at run time and to display. Choose appropriate data type and format specifier. */

#include <stdio.h>

int main () {
char username [126]; // 125 characters + 1 for null terminator
int age;
float salary;
short designation_code;
char gender;

// Reading the information
printf("Nter username (max 125 characters): ");
fgets (username, sizeof (username), stdin);

printf ("Enter age: ");
scanf ("%d", &age);

printf ("Enter salary: ");
scanf ("%f", &salary);

printf ("Enter designation code (1-6) : ");
scanf ("%hd", &designation_code);

printf ("Enter gender (M/F) : ");
scanf (" %c", &gender) ; // Note the space before %c to consume any leftover newline character

// Displaying the information
printf ("\nUser Information:\n");
printf ("Username: %s", username); // fgets includes the newline character
printf("Age: %d\n", age);
printf ("Salary: %.2f\n", salary);
printf ("Designation Code: %hd\n", designation_code);
printf ("Gender: %c\n", gender);

return 0;

}	
