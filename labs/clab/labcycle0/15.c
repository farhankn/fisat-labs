//Find largest of three numbers
#include<stdio.h>

main()
{
 int a,b,c;
 printf("\n Program to Find largest of three numbers");
 printf("\nEnter two numbers");
 scanf("%d %d %d", &a, &b, &c);
 if (a>b && a>c)
 {
   printf("%d is largest\n", a);
   if (b>a && b>c)
   printf("%d is largest\n", b);
 }
 else
  printf("%d is largest\n", c);
}

