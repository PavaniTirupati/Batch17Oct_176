/*
demo on structures

*/

#include <stdio.h>
#include <string.h>

struct Employee
{
	char eName[20];
	char eGender;
	char eAddress[20];
	int eId;
	float eSal;
};

typedef struct Employee EMP;


void getDetails(EMP [],int);
void dispDetails(EMP [], int);
void searchById(EMP[], int, int);
void searchByLname(EMP[],int,const char*);
void searchBySalaryRange(EMP[], int,float, float);
void updateLName(EMP[], int, int, const char*);  

int main()
{

	EMP e1;
	EMP e[3];
	int i;

	getDetails(e,3);
	dispDetails(e,3);

	

	printf("\n\n");
	return 0;

}

void getDetails(EMP e[], int n)
{
	int i;

	printf("\nEnter Employee Details\n");
	for(i=0;i<n;i++)
	{
		printf("\nName: ");
		scanf("%s",e[i].eName);
		printf("\nID: ");
		scanf("%d",&e[i].eId);
		printf("\nGender: ");
		scanf(" ");
		scanf("%c",&e[i].eGender);
		printf("\nAddress: ");
		scanf("%s",e[i].eAddress);
		printf("\nSalary: ");
		scanf("%f",&e[i].eSal);

	}
}

void dispDetails(EMP e[], int n)
{
	int i;
	printf("\nEmployee Details are\n");
	for(i=0;i<n;i++){
		printf("\n=========================\n");
		printf("\nID: %d",e[i].eId);
		printf("\nName: %s",e[i].eName);
		printf("\nGender: %c",e[i].eGender);
		printf("\nAddress: %s",e[i].eAddress);
		printf("\nSalary: %f",e[i].eSal);
		printf("\n=========================\n");
	}
}
void searchById(EMP e[], int n, int id) {
    int i, found = 0;

    for (i = 0; i < n; i++) {
        if (e[i].eId == id) {
            printf("\nEmployee Found with ID %d:\n", id);
            printf("ID: %d\n", e[i].eId);
            printf("Name: %s\n", e[i].eName);
            printf("Gender: %c\n", e[i].eGender);
            printf("Address: %s\n", e[i].eAddress);
            printf("Salary: %.2f\n", e[i].eSal);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void searchByLname(EMP[], int,const char*lastName)
{
	int i, found = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(e[i].eName, lastName) == 0) {
            printf("\nEmployee Found with Last Name %s:\n", lastName);
            printf("ID: %d\n", e[i].eId);
            printf("Name: %s\n", e[i].eName);
            printf("Gender: %c\n", e[i].eGender);
            printf("Address: %s\n", e[i].eAddress);
            printf("Salary: %.2f\n", e[i].eSal);
            found = 1;
        }
    }
    if (!found) {
        printf("Employee with Last Name %s not found.\n", lastName);
    }
}

void searchBySalaryRange(EMP[], int,float, float)
{
	int i, found = 0;
    printf("\nEmployees with Salary between %.2f and %.2f:\n", minSalary, maxSalary);
    for (i = 0; i < n; i++) {
        if (e[i].eSal >= minSalary && e[i].eSal <= maxSalary) {
            printf("ID: %d\n", e[i].eId);
            printf("Name: %s\n", e[i].eName);
            printf("Gender: %c\n", e[i].eGender);
            printf("Address: %s\n", e[i].eAddress);
            printf("Salary: %.2f\n", e[i].eSal);
            printf("=========================\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No employees found with salary in the given range.\n");
    }
}

void updateLName(EMP e[], int n, int id, const char *newLName) {
    int i, found = 0;
    for (i = 0; i < n; i++) {
        if (e[i].eId == id) {
            printf("Updating Last Name for Employee ID %d\n", id);
            strcpy(e[i].eName, newLName);  // Update the employee's last name
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found. Last Name not updated.\n", id);
    }
}

void menu() {
    printf("\n--- Employee Management System ---\n");
    printf("1. Display Employee Details\n");
    printf("2. Search Employee by ID\n");
    printf("3. Search Employee by Last Name\n");
    printf("4. Search Employees by Salary Range (6000 - 10000)\n");
    printf("5. Update Employee Last Name\n");
    printf("6. Exit\n");
}
















