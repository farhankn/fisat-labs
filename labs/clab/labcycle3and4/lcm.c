/*To find LCM of a number*/
#include<stdio.h>
int gcd(int,int);
main()
{ 
  int a,b,c,l;
  printf("Enter 2 numbers ");
  scanf("%d%d",&a,&b);
  c=gcd(a,b);
  l=(a*b)/c;
  printf("The LCM of %d and %d is %d\n",a,b,l);
}

int gcd(int a,int b)
{ 
  int i,j;
  i=a;j=b;
  while(i!=j)
    {
      if(i>j)
	i=i-j;
      else if(j>i)
        j=j-i;
    }
  return i;
}
  
