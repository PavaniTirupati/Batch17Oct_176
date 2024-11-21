#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	FILE *fd=NULL;
	
	fd = fopen("Test1.txt","r");

	if(fd == NULL)
	{
		perror("fopen: ");
		printf("\n%p\n\n",fd);
		exit(1);
	}
	printf("\nOpened the file successfully %p\n\n",fd);

	fd = fopen("Test2.txt","w");

        if(fd == NULL)
        {
                perror("fopen: ");
                printf("\n%p\n\n",fd);
                exit(1);
        }
        printf("\nOpened the file successfully %p\n\n",fd);
	


	return 0;
}
