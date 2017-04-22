//Program to sort an array using insertion sort.
#include<stdio.h>
void insort(int *a,int n);
void main()
{
  int a[30], n,i;
  printf("Enter the size of the array:");
  scanf("%d",&n);
  printf("Enter the elements of the array:\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  insort(a,n);
  printf("The array after sorting is:\n");
  for(i=0;i<n;i++)
   printf("%d\t",a[i]);
  printf("\n");
}

//Function for insertion sort.
void insort(int *a,int n)
{
  int i,j,m;
  for(i=1;i<n;i++)
    {
      m=a[i];
      for(j=i-1;(j>=0)&&(m<a[j]);j--)
	a[j+1]=a[j];
      a[j+1]=m;
    }
}
