//Program to sort the elements of array using Pointers
#include<stdio.h>
#include<stdlib.h>
int bubble(int *,int n);
main()
{
  int n,*a,i;
  printf("Enter the size");
  scanf("%d",&n);
  a=(int*)malloc(sizeof(int)*n);
  printf("\nEnter %d Elements of the Array",n);
  for(i=0;i<n;i++)
    {
      scanf("%d",(a+i));
    }
  bubble(a,n);
}

//Bubble Sort Function
int bubble(int *a,int n)
{
  int i,j,temp;
  for(i=0;i<(n-1);i++)
    {
      for(j=0;j<(n-i-1);j++)
	{
	  if(*(a+j)>*(a+j+1))
	    {
	      temp=*(a+j+1);
	      *(a+j+1)=*(a+j);
	      *(a+j)=temp;
	    }
	}

    }
  printf("\nThe Sorted Array:\n");
 for(i=0;i<n;i++)
    {
      printf(" %d ",*(a+i));
    }
  printf("\n");


}
