// Program to find Upper and Lower Triangle
#include<stdio.h>
void upper(int a[100][100],int,int);
void lower(int a[100][100],int,int);
main()
{
  int a[100][100],i,j,m,n,ch;
  printf("Enter the Rows and Colums of Matrix A ");
  scanf("%d %d",&m,&n);
  printf("\nEnter element in Matrix A\n ");
  for(i = 0; i<m; i++)
    for(j=0; j<n; j++)
      scanf("%d",&a[i][j]);
  printf("\n\nEntered Matrix is");
  for(i = 0; i<m; i++)
    {
      for(j=0; j<n; j++)
	printf(" %d ",a[i][j]);
      printf("\n");
    }  
do
  {
    printf("\n\n--MENU--\n\n1. Upper Traingle\n2. Lower Triangle\n3.Exit\nEnter your choice...");
    scanf("%d",&ch);
    switch(ch)
      {
      case 1: upper(a,m,n);
	  break;
      case 2: lower(a,m,n);
	break;
      case 3: break;
      default:printf("\n\nWrong Choice.. Enter a Correct option");
}
  }
    while(ch!=3);
}

void lower(int a[100][100],int m,int n)
{
  int i,j;
  printf("\n\nThe Lower Traingular Matrix is \n");
	for(i=0;i<m;i++)
	  {
	    for(j=0;j<n;j++)
	      if(i>j)
		printf("  %d  ",a[i][j]);
	      else
100100		printf(" - ");
	    printf("\n");
	  }
      
}

void upper(int a[100][100],int m,int n)
{
  int i,j;
  printf("\n\nThe upper triangular matrix is \n");
	for(i=0;i<m;i++)
	  {
	    for(j=0;j<n;j++)
	      if(i<j)
		printf(" %d ",a[i][j]);
	      else
		printf(" - ");
	    printf("\n");
	  }
      
}
