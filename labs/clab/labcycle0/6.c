//Swapping without Temporary Variable	
#include<stdio.h>

main()
{
 int a,b;
 printf("\n Program to swap two numbers");
 printf("\nEnter two numbers");
 scanf("%d %d", &a, &b);
 a=a+b;
 b=a-b;
 a=a-b;
 printf("\nThe numbers after swapping is %d %d \n", a,b);
}
