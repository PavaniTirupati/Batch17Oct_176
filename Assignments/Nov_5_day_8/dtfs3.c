/* to read a number in decimal (0-127) and display it in 2 digit hex characer. */

#include <stdio.h>

int main () 
{
	int decimal;

	/*Read a decimal number from the user*/
	printf ("Enter a decimal number (0-127): ");
	scanf ("%d", &decimal);

	// Check if the number is within the valid range
	if (decimal < 0 || decimal > 127) {
	printf ("Invalid input. Please enter a number between 0 and 127. \n");
	return 1;
	}	

	// Display the number in 2-digit hexadecimal format
	printf ("Hexadecimal: %02X\n", decimal);

	return 0;
}
