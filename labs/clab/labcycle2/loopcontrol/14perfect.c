//To check whether a number is perfect number or not
#include<stdio.h>
main()
{
  int number,i,perfect=0;
  printf("Enter Number ");
  scanf("%d",&number);
  for(i=1 ; i<=(number/2); i++)
   {
     if(number%i==0)
       perfect+=i;
   }
     if (number==perfect)
      printf("%d is a perfect number",number);
     else
      printf("%d is not a perfect number",number);
}
