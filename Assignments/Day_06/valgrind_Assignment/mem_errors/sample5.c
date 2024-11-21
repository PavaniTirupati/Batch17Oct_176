#include <stdio.h>

int main()
{
   FILE *fp;

   fp = fopen("test", "w");
   if (fp == NULL)
   {
        printf("Error : Unable to open file\n");
        return 1;
   }

   fprintf(fp, "hello world");

   // Properly close the file pointer
   fclose(fp);

   return 0;
}

