/*
 * file : code1.c
 * Name : Tirupati Pavani
 * Description : To get and display the employee details 
 * Date : 11-11-2024
 */

#include<stdio.h>
#include<stdlib.h>

struct employee{
	char eName[20];
	int eID;
	char eGender;
	char eAddress[20];
	float eSal;
};

typedef struct employee emp;
void getDetails(emp [],int);
void displayDetails(emp[], int);

int main(){

	int n;
	printf("Enter the number of employees : ");
	scanf("%d",&n);

	emp *e = (emp *)malloc(n * sizeof(emp));
	
	getDetails(e,n);
	displayDetails(e,n);

	free(e);
	return 0;
}

void getDetails(emp e[],int n){
	int i;
	for(i=1;i<=n;i++){
		printf("\nEnter employee %d name : ",i);
		scanf("%s",e[i].eName);
		printf("\nEnter employee %d ID : ",i);
		scanf("%d",&e[i].eID);
		printf("\nEnter employee %d gender : ",i);
		scanf(" ");
		scanf("%c",&e[i].eGender);
		printf("\nEnter employee %d address : ",i);
		scanf("%s",e[i].eAddress);
		printf("\nEnter employee %d salary : ",i);
		scanf("%f",&e[i].eSal);
		printf("\n");
	}
}

void displayDetails(emp e[], int n){
	int i;
	printf("The employee details are : \n");
	for(int i=1;i<=n;i++){
		printf("Employee %d name is : %s\n",i,e[i].eName);
		printf("Employee %d ID is : %d\n",i,e[i].eID);
		printf("Employee %d gender is : %c\n",i,e[i].eGender);
		printf("Employee %d address is : %s\n",i,e[i].eAddress);
		printf("Employee %d address is : %f\n",i,e[i].eSal);
		printf("\n");
	}
}
