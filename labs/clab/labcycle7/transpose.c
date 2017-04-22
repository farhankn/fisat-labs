//Transpose of a matrix using pointers and functions

#include<stdio.h>
#include<stdlib.h>
void matranspose(int *a,int *m,int *n);
main()
{
  int *a,*m,*n,i,j,*b;
  m=(int*)malloc(sizeof(int));
  n=(int*)malloc(sizeof(int));
  a=(int*)malloc(sizeof(int)*(*m)*(*n));
  b=(int*)malloc(sizeof(int)*(*m)*(*n));
  printf("\nEnter the row and column index\n");
  scanf("%d%d",m,n);
  printf("\nEnter the elements in the matrix\n");
  for(i=0;i<*m;i++)
    for(j=0;j<*n;j++)
      scanf("%d",(a+(i*(*n))+j));
  printf("\nThe entered matrix is\n");
  for(i=0;i<*m;i++)
    {
      for(j=0;j<*n;j++)
      	  printf(" %d",*(a+(i*(*n))+j));
	  printf("\n");
    }
  printf("\nthe Transpose Matrix is\n");
  matranspose(a,m,n);
}


void matranspose(int *a,int *m,int *n)
{
  
  int *b,i,j;
  b=(int*)malloc(sizeof(int)*(*m)*(*n));
  for(i=0;i<*m;i++)
    {
      for(j=0;j<*n;j++)
	{   
	  *(b+(j*(*m))+i)=*(a+(i*(*n))+j);
	}	       
    }
  
  for(i=0;i<*n;i++)
    {
      for(j=0;j<*m;j++)
        printf(" %d ",*(b+(i*(*m)+j)));
      printf("\n");
    }
}