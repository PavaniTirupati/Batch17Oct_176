/* to read a user choice as 'y' or 'Y' or 'n' or 'N' and display read choice as "Yes" or "No" according to the input received. */

#include <stdio.h>

int main ()
{
	char choice;

	// Read user input
	printf ("Enter your choice (y/Y/n/N): ");
	scanf (" %c", &choice) ; // Note the space before %c to consume any leftover newline character

	// Check the input and display the corresponding message
	if (choice == 'y' || choice == 'Y') {
	printf ("Yes\n");
	} else if (choice == 'n' || choice == 'N') {
	printf ("No\n");
	} else {
	printf ("Invalid character\n");
	}

	return 0;
}
