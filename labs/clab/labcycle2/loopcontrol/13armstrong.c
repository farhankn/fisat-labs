//Program to check whether number is armstrong number
#include<stdio.h>
#include<math.h>
main()
{
  int number,sum=0,i,remainder,x,temp;
  printf("Enter Number ");
  scanf("%d",&number);
  temp=number;  
  for(i=0 ; number>0; i++)
    {
     remainder=number%10;
     x=pow(remainder,3);
     sum=sum+x;
     number=number/10;
    }
  if(sum==temp)
    printf("%d is an Armstrong number\n",temp);
  else
    printf("\n %d is not an Armstrong number",temp);
}
