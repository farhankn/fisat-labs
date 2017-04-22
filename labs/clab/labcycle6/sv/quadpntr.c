#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
  float *a,*b,*c,*r1,*r2,*d,*ri1,*ri2;
	a=(float *)(malloc(sizeof(float)));
	b=(float *)(malloc(sizeof(float)));
	c=(float *)(malloc(sizeof(float)));
	r1=(float *)(malloc(sizeof(float)));
	r2=(float *)(malloc(sizeof(float)));
	d=(float *)(malloc(sizeof(float)));
	ri1=(float *)(malloc(sizeof(float)));
	ri2=(float *)(malloc(sizeof(float))); 
	 printf("\nEnter the coefficients of the quadratic equation:");
  scanf("%f %f %f",a,b,c);
  *d=((*b)*(*b))-(4*(*a)*(*c));
  if(*d==0)
   {
    printf("\nOnly One root and the root is:%f",(-(*b)/(2*(*a))));
   }
  else if(*d>0)
   {
     (*r1)=((-(*b))+(sqrt(*d)))/(2*(*a));
     *r2=((-*b)-(sqrt(*d)))/(2*(*a));
     printf("\nThe equation has 2 roots");
     printf("\nThe roots are:%f & %f\n",r1,r2);
   }
  else
   {  
     printf("\nThe Roots are Imaginary!!!!");
     *ri1=((*b)/(2*(*a)));
     *ri2=(sqrt(-(*d))/(2*(*a)));
     printf("\n The roots are:%f+%fi and %f-%fi\n",*ri1,*ri2,*ri1,*ri2);
   }
}
