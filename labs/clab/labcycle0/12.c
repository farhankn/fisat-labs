#include<stdio.h>

main()
{
   int a;
   printf("\nEnter side of Triangle");
   scanf("%d",&a);
   float area;
   area = (1.732050808*a*a)/4;
   printf("\n Area : %f", area);
}

