/*
       Desc:to read a number n and to display the cumulative sum of factorial of all numbers upto n . (use for or while)
  
  Input: 4
  
   Ouput: 4!+3!+2!+1! = 33
   */
   #include<stdio.h>
   int main()
 {
     int num,iter1,iter2,fact,cuSum=0;
     printf("Enter a number: ");
     scanf("%d",&num);
     for(iter1 = num; iter1>=1; iter1--)
     {

         fact=1;
         for(iter2=1; iter2<=iter1; iter2++)
             fact *=iter2;
         cuSum +=fact;
     }
     printf("%d\n",cuSum);
     return 0;
 }

