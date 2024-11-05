	#include <stdio.h>
	#include <stdlib.h>
	#define SUCCESS 0
	#define FAILURE -1
	#define True 1
	#define False 0

	int displayMenu();

	int main()
	{
		int ch;
		int flag = 0;
		while(True)
		{
			flag = 0;
			//ch = displayMenu();
			switch(displayMenu())
			{
				case 1 :
					printf("\nAddition function Executed\n");
					break;
				case 2 :
					printf("\nSubraction function Executed\n");
					break;
				case 3 :
					printf("\nMul function Executed\n");
					break;
				case 4 :
					printf("\nDivision function Executed\n");
					break;
				case 5 :
					printf("\nExiting from the application\n");
					//exit(SUCCESS);
					flag = 1;
					break;
				default :
					printf("\nEnter the correct choice\n");
					break;
			}
			if(flag==1)
				break;
		}
		printf("\nProgram Ended\n");
		return SUCCESS;
	}
	
	int displayMenu()
	{
		int choice;
		
		printf("\nPress,");
		printf("\n1. Addition");
		printf("\n2. Subraction");
		printf("\n3. Mul");
		printf("\n4. Division");
		printf("\n5. Exit");
		printf("\nChoice");
		scanf("%d", &choice);
		
		return choice;
	}
