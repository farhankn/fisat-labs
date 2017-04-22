//Addition of Sparse Matrix
#include<stdio.h>
main()
{
  int a[10][3],b[10][3],c[10][3],r1,r2,t1,t2,k1,k2,k3,i,j;
  printf("Enter the nonzero elements of Triplet 1: ");
  scanf("%d",&r1);
  printf("\nEnter the Matrix: \n");
  for(i=0;i<r1+1;i++)
    for(j=0;j<3;j++)
      scanf("%d",&a[i][j]);
  printf("Enter the nonzero elements of Triplet 2: ");
  scanf("%d",&r2);
  printf("\nEnter the Matrix: \n");
  for(i=0;i<r2+1;i++)
    for(j=0;j<3;j++)
      scanf("%d",&b[i][j]);
  printf("\nEntered Matrix1: \n");
  for(i=0;i<r1+1;i++)
    {
      for(j=0;j<3;j++)
	printf(" %d ",a[i][j]);
      printf("\n");
    }
  printf("\nEntered Matrix2: \n");
  for(i=0;i<r2+1;i++)
    {
      for(j=0;j<3;j++)
	printf(" %d ",b[i][j]);
      printf("\n");
    }
  
  if((a[0][0]==b[0][0])&&(a[0][1]==b[0][1]))
    {
      t1=a[0][2];
      t2=b[0][2];
      k1=k2=k3=1;
      while(k1<=t1&&k2<=t2)
	{
	  if(a[k1][0]<b[k2][0])
	    {
	      c[k3][0]=a[k1][0];
	      c[k3][1]=a[k1][1];
	      c[k3][2]=a[k1][2];
	      k1++;
	      k3++;
	    }
	  else if(a[k1][0]>b[k2][0])
	    {
	      c[k3][0]=b[k2][0];
	      c[k3][1]=b[k2][1];
	      c[k3][2]=b[k2][2];
	      k3++;
	      k2++;
	    }
	  else if(a[k1][0]==b[k2][0])
	    {
	      if(a[k1][1]<b[k2][1])
		{
		  c[k3][0]=a[k1][0];
		  c[k3][1]=a[k1][1];
		  c[k3][2]=a[k1][2];
		  k3++;
		  k1++;
		}
	      else if(a[k1][1]>b[k2][1])
		{
		  c[k3][0]=b[k2][0];
		  c[k3][1]=b[k2][1];
		  c[k3][2]=b[k2][2];
		  k3++;
		  k2++;
		}
	      else if(a[k1][1]==b[k2][1])
		{
		  c[k3][0]=a[k1][0];
		  c[k3][1]=a[k1][1];
		  c[k3][2]=a[k1][2]+b[k2][2];
		  k3++;
		  k2++;
		  k1++;
		}
	    }
	}//Closing of While loop
	  while(k1<=t1)
	    {
	      c[k3][0]=a[k1][0];
	      c[k3][1]=a[k1][1];
	      c[k3][2]=a[k1][2];
	      k3++;
	      k1++;
	    }
	  while(k2<=t2)
	    {
	      c[k3][0]=b[k2][0];
	      c[k3][1]=b[k2][1];
	      c[k3][2]=b[k2][2];
	      k2++;
	      k1++;
	    }
	  
	  c[0][0]=a[0][0];
	  c[0][1]=a[0][1];
	  c[0][2]=k3-1;
	  
	  //Display of Matrix
	  printf("\nSparse Matrix after Addition: \n");
	  for(i=0;i<k3;i++)
	    {
	      for(j=0;j<3;j++)
		printf(" %d ",c[i][j]);
	      printf("\n");
	    }
	  
    }//Closing of if
  else
    printf("\nAddition Cannot be Performed\n");
  
}//End of Program
