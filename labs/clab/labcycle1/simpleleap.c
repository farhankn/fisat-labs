#include<stdio.h>
main()
{
  int j;
  printf("Enter Year ");
  scanf("%d",&j);
     if((j%400==0))
       printf("\n %d, is a leap year",j);
       else if((j%400!=0 && j%100!=0 && j%4==0))
	 printf("\n %d is a leap year, ",j);
       else
	 printf("\n %d is not a leap year",j);
}
