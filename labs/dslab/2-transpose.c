#include<stdio.h>
main()
{
  int a[10][3],b[10][3],r,c,i,j,m,n,t,q,col,o,p;
  printf("Enter the Rows of Triplet: ");
  scanf("%d",&r);
  printf("\nEnter the Matrix: \n");
  for(i=0;i<r;i++)
    for(j=0;j<3;j++)
      scanf("%d",&a[i][j]);
  printf("\nEntered Matrix: \n");
  for(i=0;i<r;i++)
    {
      for(j=0;j<3;j++)
	printf(" %d ",a[i][j]);
      printf("\n");
    }
  m = a[0][0];
  n = a[0][1];
  t = a[0][2];
  b[0][0]=n;
  b[0][1]=m;
  b[0][2]=t;
  if(t<=0)
    printf("\n No non zero values... Exiting...");
  q=1;
  for(col=o;col<=n-1;col++)
    for(p=1;p<=t;p++)
      if(a[p][1]==col)
	{
	  b[q][0]= a[p][1];
	  b[q][1]=a[p][0];
	  b[q][2]=a[p][2];
	  q=q++;
	}
  
  printf("\nTransposed Triplet: \n");  
  for(i=0;i<r;i++)
    {
      for(j=0;j<3;j++)
	printf(" %d ",b[i][j]);
      printf("\n");
    }
}
