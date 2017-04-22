#include<stdio.h>
main()
{
  int nz=0,r,c,row,p,S[20][20],col,i,j,A[20][20],B[20][20],m,n,t,q;
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
	    S[nz][0]=r;
	    S[nz][1]=c;
	    S[nz][2]=A[r][c];
	  }
      }
  S[0][0]=row;
  S[0][1]=col;
  S[0][2]=nz;
  printf("The triplet representation of matrix");
  for(i=0;i<=nz;i++)
    {printf("\n");
      for(j=0;j<3;j++)
	printf("%d ",S[i][j]);
    }
      m=S[0][0];
      n=S[0][1];
      t=S[0][2];
      B[0][0]=n;
      B[0][1]=m;
      B[0][2]=t;
      q=1;
      for(c=0;c<n;c++)
	for(p=1;p<=t;p++)
	  if(S[p][1]==c)
	    {
	      B[q][0]=S[p][1];
	      B[q][1]=S[p][0];
	      B[q][2]=S[p][2];
	      q++;
}
      printf("\nThe transpose of triplet");
      for(i=0;i<=nz;i++)
	{
	  printf("\n");
	  for(j=0;j<3;j++)
	    printf("%d ",B[i][j]);
}
      printf("\n");

}
