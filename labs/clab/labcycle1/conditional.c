//Program to find largest of three numbers using conditional operator
#include<stdio.h>
main()
{
  int a,b,c;
  printf("Enter three numbers");
  scanf("%d %d %d",&a,&b,&c);
  if((a>b) ? (a>c) ? printf("\n is the largest",a) : printf("\n %d is the largest",c) : ((b>c) ? printf("\n%d is the largest",b) : printf("\n%d is the largest",c)));
}
