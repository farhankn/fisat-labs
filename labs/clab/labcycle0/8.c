//Find Quotient and Remainder
#include<stdio.h>

main()
{
 int a,b;
 float q,r;
 printf("\n Program to Find quotient and remainder two numbers");
 printf("\nEnter two numbers");
 scanf("%d %d", &a, &b);
 q=a/b;
 r=a%b;
 printf("\nThe Quotient is %f and remainder is %f \n",q,r);
}
