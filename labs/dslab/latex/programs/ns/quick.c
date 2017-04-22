//Program to sort an array using quicksort.
#include<stdio.h>
void quicksort(int first,int last);
int a[30];
void main()
{
  int n,i,first=0,last;
  printf("Enter the size of the array:");
  scanf("%d",&n);
  printf("Enter the elements of the array:\n");
  for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
  last=n;
  quicksort(first,last);
  printf("The array after sorting is:\n");
  for(i=1;i<=n;i++)
   printf("%d\t",a[i]);
  printf("\n");
}

//Function for quick sort.
void quicksort(int first,int last)
{
  int i,j,pivot,temp;
  if(first<last)
    {
      pivot=a[first];
      i=first;
      j=last;
      while(i<j)
	{
	  while((a[i]<=pivot)&&(i<last))
	    i++;
	  while((a[j]>=pivot)&&(j>first))
	    j--;
	  if(i<j)
	    {
	      temp=a[i];
	      a[i]=a[j];
	      a[j]=temp;
	    }
	}
      temp=a[j];
      a[j]=a[first];
      a[first]=temp;
      quicksort(first,j-1);
      quicksort(j+1,last);
    }
}
