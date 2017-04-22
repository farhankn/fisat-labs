//Program to Find the Largest and Smallest number in a Matrix
#include<stdio.h>
#include<stdlib.h>
int matrix(int *,int n,int m);
main()
{
  int *a,i,j,m,n;
  
  printf("Enter the size n  and m:");
  scanf("%d%d",&n,&m);
  a=(int *)malloc(sizeof(int)*n*m);
  printf("\nEnter the elements: ");
  for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
	{
	  scanf("%d",(a+i*m+j));
	}      
    }
 
  matrix(a,n,m);
}
int matrix(int *a,int n,int m)
{
  int i,j,largest,small;
  largest=*a;
  small=*a;
  for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
	{
	  if(largest<*(a+i*m+j))
	    largest=*(a+i*m+j);
	}
    }
  for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
	{
	  if(small>*(a+i*m+j))
	    small=*(a+i*m+j);
	}
    }
  printf("\nLargest element is %d\n",largest);
  printf("\nSmallest element is %d\n",small);
}
