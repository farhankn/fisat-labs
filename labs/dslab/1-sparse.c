//Program to Find a Sparse Matrix
#include<stdio.h>

main()
{
  int i,j,r=0,c=0,row,col,nonzero=0,a[10][10],spar[10][10];
  printf("\nEnter the No of Rows and columns of the matrix ");
  scanf("%d%d",&row,&col);
  printf("\nEnter the Elements of the Matrix");
  for(i=0;i<row;i++)
    for(j=0;j<col;j++)
      scanf("%d",&a[i][j]);
  printf("\nThe Entered matrix \n");
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	printf(" %d ",a[i][j]);
      printf("\n");
    }
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  if(a[i][j]!=0)
	    {
	      nonzero++;
	      spar[nonzero][0]=i;
	      spar[nonzero][1]=j;
	      spar[nonzero][2]=a[i][j];
	    }
	}
    }
  spar[0][0]=row;
  spar[0][1]=col;
  spar[0][2]=nonzero;
  
  printf("\nSparse Matrix \n");
  for(i=0;i<nonzero+1;i++)
    {
      for(j=0;j<3;j++)
	printf(" %d ",spar[i][j]);
      printf("\n");
    }
}
