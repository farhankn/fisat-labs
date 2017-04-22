//To check whether an entered number is a palidrome
#include<stdio.h>
main()
{
  int number,sum=0,reverse=0,i,remainder,num;
  printf("Enter Number ");
  scanf("%d",&number);
  num = number;
for(i=0 ; number>0; i++)
   {
    remainder=number%10;
    sum=sum+remainder;
    reverse=(reverse*10)+remainder;
    number=number/10;
   }

 if(num==reverse)
   printf("\n%d is a palidrome\n",num);
 else
   printf("\n%d is not a palidrome\n",num);
}
