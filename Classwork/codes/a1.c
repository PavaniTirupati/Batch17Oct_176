#include <stdio.h>

int main()
{
	int n, itr;

	printf("\nEnter n value\n");
	scanf("%d",&n);

	for(itr = 1;itr<n;itr++)
	{
		printf("%d, ",((itr*itr)-1));
	}
	printf("%d",((itr*itr)-1));
	return 0;
}
