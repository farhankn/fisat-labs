//Swapping using Temporary Variable	
#include<stdio.h>

main()
{
 int a,b,c;
 printf("\n Program to swap two numbers");
 printf("\nEnter two numbers");
 scanf("%d %d", &a, &b);
 c=a;
 a=b;
 b=c;
 printf("\nThe numbers after swapping is %d %d \n", a,b);
}
