//Program to find the root of a quadratic equation
#include<stdio.h>
#include<math.h>  //for sqrt()

main()
{
 float a, b, c, x;
 float r1, r2;
 printf("Enter the values of a,b,c in equation ax^2+bx+c: ");
 scanf("%f %f %f", &a, &b, &c);
 x=(b*b)-(4*a*c);

 if (x>0)
  {
   r1=(-b+sqrt(x))/(2*a);
   r2=(-b-sqrt(x))/(2*a);
   printf("Roots are %f and %f",r1 ,r2);
  }

 else if (x==0)
  {
   r1 =(-b)/(2*a);
   printf("Roots are equal and is %f",r1);
  }
 else
  {
   r1 =((-b)/(2*a));
   r2 = sqrt(-x)/(2*a);
   printf("Root1 %f + %f i", r1, r2);  
   printf("\nRoot2 %f - %f i", r1, r2);  
}

}
