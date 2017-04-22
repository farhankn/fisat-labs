//Program to find the Triple Representation of the Transpose of a Sparse Matrix.
#include<stdio.h>
void main()
{
  int a[20][5],b[20][5],i,m,n,j,t,p,q;
  printf("Enter the number of non-zero elements in the Sparse Matrix:");
  scanf("%d",&t);
  printf("Enter the Triple form of the Sparse matrix:");
  for(i=0;i<=t;i++)
    {
      for(j=0;j<3;j++)
	scanf("%d",&a[i][j]);
    }
  printf("Triple Representation of the sparse matrix is a s follows:\n");
  for(i=0;i<=t;i++)
    {
      for(j=0;j<3;j++)
	printf("%d\t",a[i][j]);
      printf("\n");
    }
  m=a[0][0];
  n=a[0][1];
  b[0][1]=m;
  b[0][0]=n;
  b[0][2]=t;
  if(t<=0)
    {
      printf("The sparse  matrix is empty.");
    }
  q=1;
  for(i=0;i<=n-1;i++)
    {
      for(p=1;p<=t;p++)
	{
	  if(a[p][1]==i)
	    {
	      b[q][0]=a[p][1];
	      b[q][1]=a[p][0];
	      b[q][2]=a[p][2];
	      q=q+1;
	    }
	}
    }
	
  printf("The Transpose is as follows:\n");
      for(i=0;i<=t;i++)
	{
	  for(j=0;j<3;j++)
	    printf("%d\t",b[i][j]);
	  printf("\n");
	}
}

