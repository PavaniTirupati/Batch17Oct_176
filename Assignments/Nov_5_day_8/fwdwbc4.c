 /*
      Desc:to run the program with a large value say 255. Check the output? Is it correct? Fix the issue observed.
  
   */
   #include<stdio.h>
   int main()
   {
          long double fact=1;
          long double count,num;
        printf("Enter a number:");
        scanf("%Lf",&num);
        for(count = 1;count <= num;count++)
        {
                fact = fact * count;
        }
        printf("factorial of %Lf is :%Lf \n",num,fact);
        return 0;
}

