#include<stdio.h>
void enter(int A[20][20],int m,int n)
{
  
  int i,j;
  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
      scanf("%d",&A[i][j]);
}
main()
{
  int nz=0,r,c,row,nz1=0,S1[20][20],col,i,j,A[20][20],B[20][20],row1,col1,S2[20][20];
  int C[20][20],k1,k2,k3,t1,t2;
  printf("Enter row and col of mat 1:");
  scanf("%d%d",&row,&col);
 printf("Enter the elments of matrix 1:");
  enter(A,row,col);
   printf("Enter row and col of matrix 2:");
  scanf("%d%d",&row1,&col1);
 printf("Enter the elments of matrix 2:");
  enter(B,row1,col1);
  for(r=0;r<row;r++)
    for(c=0;c<col;c++)
      {
	if(A[r][c]!=0)
	  {
	    nz++;
	    S1[nz][0]=r;
	    S1[nz][1]=c;
	    S1[nz][2]=A[r][c];
	  }
      }
  S1[0][0]=row;
  S1[0][1]=col;
  S1[0][2]=nz;

for(r=0;r<row1;r++)
    for(c=0;c<col1;c++)
      {
	if(B[r][c]!=0)
	  {
	    nz1++;
	    S2[nz1][0]=r;
	    S2[nz1][1]=c;
	    S2[nz1][2]=B[r][c];
	  }
      }
  S2[0][0]=row1;
  S2[0][1]=col1;
  S2[0][2]=nz1;


  printf("The triplet representation of matrix 1:");
  for(i=0;i<=nz;i++)
    {printf("\n");
      for(j=0;j<3;j++)
	printf("%d ",S1[i][j]);
    }


  printf("\nThe triplet representation of matrix 2:");
  for(i=0;i<=nz1;i++)
    {printf("\n");
      for(j=0;j<3;j++)
	printf("%d ",S2[i][j]);
    }

  if((S1[0][0]==S2[0][0])&&(S1[0][1]==S2[0][1]))

    {
      t1=S1[0][2];
      t2=S2[0][2];
      k1=1;k2=1;k3=1;
      while((k1<=t1)&&(k2<=t2))
	{
	  if(S1[k1][0]<S2[k2][0])
	    {
	      C[k3][0]=S1[k1][0];
	      C[k3][1]=S1[k1][1];
	      C[k3][2]=S1[k1][2];
	      k3++;
	      k1++;
	    }
	  else if(S1[k1][0]>S2[k2][0])
	    {
	      C[k3][0]=S2[k2][0];
	      C[k3][1]=S2[k2][1];
	      C[k3][2]=S2[k2][2];
	      k3++;
	      k2++;
	    }
	  else  
	     if(S1[k1][1]<S2[k2][1])
	    {
	      C[k3][0]=S1[k1][0];
	      C[k3][1]=S1[k1][1];
	      C[k3][2]=S1[k1][2];
	      k3++;
	      k1++;
	    }
	 else    if(S1[k1][1]>S2[k2][1])
	    {
	      C[k3][0]=S2[k2][0];
	      C[k3][1]=S2[k2][1];
	      C[k3][2]=S2[k2][2];
	      k3++;
	      k2++;
	    }
	 else
	   {
	    C[k3][0]=S1[k1][0];
	      C[k3][1]=S1[k1][1];
	      C[k3][2]=S1[k1][2]+S2[k2][2];
	      k1++;k2++;k3++;
	   }
	}

      while(k1<=t1)
	{
	      C[k3][0]=S1[k1][0];
	      C[k3][1]=S1[k1][1];
	      C[k3][2]=S1[k1][2];
	      k3++;
	      k1++;
	  
}
      while(k2<=t2)
	{
	  C[k3][0]=S2[k2][0];
	      C[k3][1]=S2[k2][1];
	      C[k3][2]=S2[k2][2];
	      k3++;
	      k2++;
}

      C[0][0]=S1[0][0];
      C[0][1]=S1[0][1];
      C[0][2]=k3-1;
      printf("\nThe sum of triplets");

for(i=0;i<=C[0][2];i++)
    {printf("\n");
      for(j=0;j<3;j++)
	printf("%d ",C[i][j]);
    }
    }
  else 
    printf("Addition not possible");
  printf("\n");
}
