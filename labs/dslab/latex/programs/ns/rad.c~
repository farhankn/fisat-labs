//Program to sort an array using radix sort.
#include<stdio.h>
void radsort(int *a,int n);
void insertq(int item,int j);
void initq();
struct radix
{
  int data[100];
}q[10];
int f[10],r[10],a[50];
void main()
{
  int n,i;
  printf("Enter the size of the array:");
  scanf("%d",&n);
  printf("Enter the elements of the array:\n");
  for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
  radsort(a,n);
  printf("The array after sorting is:\n");
  for(i=1;i<=n;i++)
    printf("%d\t",a[i]);
  printf("\n");
}
//Fuction to radix sort
void radsort(int *a,int n)
{
  int d=1,b,large=a[0],i,j,k,p=0,pass;
  for(i=1;i<n;i++)
    {
      if(a[i]>large)
	large=a[i];
    }
  while(large>0)
    {
      p++;
      large=large/10;
    }
  initq();
  for(pass=0;pass<p;pass++)
    {
      k=0;
      for(i=0;i<n;i++)
	{
	  b=(a[i]/d)%10;
	  insertq(a[i],b);
	}
      for(i=0;i<10;i++)
	{
	  for(j=f[i];j<=r[j];j++)
	    {
	      a[k]=q[i].data[j];
	      k++;
	    }
	}
      d=d*10;
      initq();
    }
}

//Function to initialise.
void initq()
{
  int i;
  for(i=0;i<10;i++)
    {
      f[i]=1;
      r[i]=0;
    }
}

//Function to insert data.
void insertq(int item,int j)
{
  r[j]=r[j]+1;
  q[j].data[r[j]]=item;
}
