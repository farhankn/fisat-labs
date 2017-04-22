#include<stdio.h>
main()
{
  int nz=0,r,c,row,spar[20][20],col,i,j,A[20][20];
  printf("Enter row and col");
  scanf("%d%d",&row,&col);
  printf("Enter the elments of matrix");
  for(i=0;i<row;i++)
    for(j=0;j<col;j++)
      scanf("%d",&A[i][j]);
  
  for(r=0;r<row;r++)
    for(c=0;c<col;c++)
      {
	if(A[r][c]!=0)
	  {
	    nz++;
	    spar[nz][0]=r;
	    spar[nz][1]=c;
	    spar[nz][2]=A[r][c];
	  }
      }
  spar[0][0]=row;
  spar[0][1]=col;
  spar[0][2]=nz;
  printf("The triplet representation of matrix");
  for(i=0;i<=nz;i++)
    {printf("\n");
      for(j=0;j<3;j++)
	printf("%d ",spar[i][j]);
    }
  printf("\n");
}
