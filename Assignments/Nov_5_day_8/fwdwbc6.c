/*
  #include <stdio.h>
  
  int main()
  
  {
  
   float cnt = 0, num = 1000;
  
 do

 {

 printf ("\n%d\n%d", num,cnt);

 num /= cnt;

 } while (cnt --);

 return 0;
 }
 */
 #include <stdio.h>

 int main()

 {

 float cnt = 0, num = 1000;

 do

 {

 printf ("\n%f\n%f", num,cnt);

 num /= cnt;

 } while (cnt --); /* End of while */

 return 0;
}

