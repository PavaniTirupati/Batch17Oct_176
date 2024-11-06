/*
  DESC:Write a program to continuously read a string of maximum length 80 chars, End the program if string is END, else convert to upper case, display and     continue. (use while)
  */
   #include<stdio.h>
   #include<string.h>
   #include<ctype.h>
  
  #define SUCCESS 0;
  #define EXIT 1;

 int main()
 {
     char str[81];
     while(1)
     {
         printf("Enter a string max 80 characters:");
         fgets(str,sizeof(str),stdin);
         str[strcspn(str,"\n")]='\0';
         if(strcmp(str,"END")==0)
         {
             break;
         }
         for(int iter =0;str[iter] !='\0';iter++)
         {
             str[iter]=toupper(str[iter]);
         }
         printf("uppercase: %s\n",str);
     }
     printf("Program terminated\n");
     return 0;
} 


