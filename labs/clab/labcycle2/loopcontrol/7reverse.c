#include<stdio.h>
main()
{
  int number,sum=0,reverse=0,i,remainder;
  printf("Enter Number ");
  scanf("%d",&number);
  for(i=0 ; number>0; i++)
   {
    remainder=number%10;
    sum=sum+remainder;
    reverse=(reverse*10)+remainder;
    number=number/10;
   }
  printf("\n Reversed Number is %d ands sum of digits is %d\n",reverse,sum);
}
