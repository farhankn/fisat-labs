//Program to add the triplet representation of two sparse matrices.
#include<stdio.h>
void main()
{
  int i,j,a[20][4],b[20][4],c[20][4],t1,t2,k1,k2,k3;
  printf("Enter the number of elements in first matrix:");
  scanf("%d",&t1);
  printf("Enter the Triplet form of First matrix:");
  for(i=0;i<=t1;i++)
    for(j=0;j<3;j++)
      scanf("%d",&a[i][j]);
  printf("The first matrixis as follows:\n");
  for(i=0;i<=t1;i++)
    {
      for(j=0;j<3;j++)
	{
	  printf("%d\t",a[i][j]);
	}
      printf("\n");
    }
  printf("Enter the number of elements of second matrix:");
  scanf("%d",&t2);
  printf("Enter the Triplet form of Second matrix:");
  for(i=0;i<=t2;i++)
    for(j=0;j<3;j++)
      scanf("%d",&b[i][j]);
  printf("The Second matrix is as follows:\n");
  for(i=0;i<=t2;i++)
    {
      for(j=0;j<3;j++)
	{
	  printf("%d\t",b[i][j]);
	}
      printf("\n");
    }
  if((a[0][0]==b[0][0])||(a[0][1]==b[0][1]))
    {
      k1=1;
      k2=1;
      k3=1;
      while((k1<=t1) && (k2<=t2))
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
	      k2++;
	      k3++;
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
		  k2++;
		  k3++;
		}
	      else if(a[k1][1]==b[k2][1])
		{
		  c[k3][0]=a[k1][0];
		  c[k3][1]=a[k1][1];
		  c[k3][2]=a[k1][2]+b[k2][2];
		  k1++;
		  k2++;
		  k3++;
		}
	    }
	  
	}
      while(k1<=t1)
	{
	  c[k3][0]=a[k1][0];
	  c[k3][1]=a[k1][1];
	  c[k3][2]=a[k1][2];
	  k1++;
	  k3++;
	}
      while(k2<=t2)
	{
	  c[k3][0]=b[k2][0];
	  c[k3][1]=b[k2][1];
	  c[k3][2]=b[k2][2];
	  k2++;
	  k3++;
	}
      c[0][0]=a[0][0];
      c[0][1]=a[0][1];
      c[0][2]=k3-1;
      printf("The Sum is a s follows:\n");
      for(i=0;i<k3;i++)
	{
	  for(j=0;j<3;j++)
	    {
	      printf("%d\t",c[i][j]);
	    }
	  printf("\n");
	}
    }
  else
    {
      printf("Addition not possible!!\n");     
    }
}
