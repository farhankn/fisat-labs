#include<stdio.h>
main()
{
  int a,b; 
  printf("\nEnter base and height of Cylinder");
  scanf("%d %d",&a,&b);
  float area;
  area = 2*3.14*a*b;
  printf("\n Area : %f", area);
}
