//Program to add two polynomials using array.
#include<stdio.h>
struct poly
{
  int c,e;
}p1[50],p2[50],p3[50];

void main()
{
  int t1,t2,k3=0,k1=0,k2=0,j,i;
  printf("Enter the number of elements in first polynomial:");
  scanf("%d",&t1);
  printf("Enter the elements in first polynomial:\n");
  for(i=0,j=t1-1;j>=0;j--,i++)
    {
      printf("Coefficient  of X^%d:",j);
      scanf("%d",&p1[i].c);
      p1[i].e=j;
      
    }
  printf("The first polynomial is as follows:\n");
  for(j=0;j<t1;j++)
    {
      
	 printf("%dX^%d",p1[j].c,p1[j].e);
	 if((j+1)!=t1)
	   printf("+");
	 else
	   printf("=0\n");
	
    }
  printf("Enter the number of elements in second polynomial:");
  scanf("%d",&t2);
  printf("Enter the elements in second polynomial:\n");
  for(i=0,j=t2-1;j>=0;j--,i++)
    {
      printf("Coefficient  of X^%d:",j);
      scanf("%d",&p2[i].c);
      p2[i].e=j;
     
    }
 printf("The second polynomial is as follows:\n");
 for(j=0;j<t2;j++)
   {
    
	 printf("%dX^%d",p2[j].c,p2[j].e);
	 if((j+1)!=t2)
	   printf("+");
	 else
	   printf("=0\n");
	
   }
 while((k1<t1) && (k2<t2))
   {
     if(p1[k1].e==p2[k2].e)
       {
	 p3[k3].e=p1[k1].e;
	 p3[k3].c=p1[k1].c+p2[k2].c;
	 k1++;
	 k2++;	     
	 k3++;
       }
     else if(p1[k1].e>p2[k2].e)
       { 
	 p3[k3].e=p1[k1].e;
	 p3[k3].c=p1[k1].c;
	 k1++;
	 k3++; 
       }
     else if(p1[k1].e<p2[k2].e)
       {
	 p3[k3].e=p2[k2].e;
	 p3[k3].c=p2[k2].c;
	 k2++;	     
	 k3++;
       }
   }
 while(k1<t1)
   {
     p3[k3].e=p1[k1].e;
     p3[k3].c=p1[k1].c;
     k1++;
     k3++;
   }
 while(k2<t2)
   {
     p3[k3].e=p2[k2].e;
     p3[k3].c=p2[k2].c;
     k2++;	     
     k3++;
   }
 printf("The sum of the polynomials is as follows:\n");
 for(j=0;j<k3;j++)
   {

	 printf("%dX^%d",p3[j].c,p3[j].e);
	 if((j+1)!=k3)
	   printf("+");
	 else
	   printf("=0\n");
       }

}
