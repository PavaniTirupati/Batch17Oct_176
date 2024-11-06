#include <stdio.h>

	// extern keyword example
	extern int count; // Declaration of an external variable

	// Function to demonstrate extern
	void incrementCount () {
	count++;
	}	

	// volatile keyword example
	volatile int flag = 0; // Declaration of a volatile variable

	// Function to demonstrate volatile
	void checkFlag() {
	while (!flag) {
	// Wait for flag to change
	}
	printf("Flag has changed! \n");
	}

	int main () {
	// auto keyword example
	auto x = 10; // x is inferred to be of type int
	auto y = 3.14; // y is inferred to be of type double

	printf("x = %d, y = %.2f\n", x, y);
	
	// extern keyword example
	count = 5; // Definition of the external variable
	printf("Initial count: %d\n", count);
	incrementCount();
	printf("Count after increment: %d\n", count);

	// volatile keyword example
	flag = 1; // Change the flag to exit the loop in checkFlag
	checkFlag();

	// sizeof keyword example
	int a;
	double b;
	printf("Size of int: %zu bytes\n", sizeof(a));
	printf("Size of double: %zu bytes\n", sizeof(b));

	// const koyword oxamplo
	conat int max value - 100;
	printf("Max value: 9d\n",
	// max value - 200; // Uncommenting this line will cause a compilation error

	return 0;
}
