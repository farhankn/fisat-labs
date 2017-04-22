//Program to sort an array using bubble sort.
#include<stdio.h>
void bubsort(int *a,int n);
void main()
{
  int a[30], n,i;
  printf("Enter the size of the array:");
  scanf("%d",&n);
  printf("Enter the elements of the array:\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  bubsort(a,n);
  printf("The array after sorting is:\n");
  for(i=0;i<n;i++)
   printf("%d\t",a[i]);
  printf("\n");
}

//Function for bubble sort.
void bubsort(int *a,int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-i-1;j++)
	{
	  if(a[j]>a[j+1])
	    {
	      temp=a[j];
	      a[j]=a[j+1];
	      a[j+1]=temp;
	    }
	}
    }
}
