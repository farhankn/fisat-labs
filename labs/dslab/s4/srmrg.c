#include<stdio.h>
int a[100],n,k,b[100],h,u=1;
void merge(int,int,int);
void mergesort(int low,int high)
{
  int mid;
  if(low<high)
    {
      mid=(high+low)/2;
      mergesort(low,mid);
      mergesort(mid+1,high);
      merge(low,mid,high);
    }
}
void merge(int low,int mid,int high)
{
  int i,j;
  i=low;
  j=mid+1;
  k=low;
  while(i<=mid&&j<=high)
    {
      if(a[i]<=a[j])
	{
	  b[k]=a[i];
	  k++;
	  i++;
	}
      else
	{
	  b[k]=a[j];
	  k++;
	  j++;
	}

    }
  while(i<=mid)
    {
      b[k]=a[i];
      k++;
      i++;
    }
  while(j<=high)
    {
      b[k]=a[j];
      k++;
      j++;
    }
  for(i=low;i<=high;i++)
    a[i]=b[i];
  printf("PASS %d:",u++);
 for(h=0;h<n;h++)
    printf("%d ",a[h]);
 printf("\n");
}
void main()
{int i;
  printf("Enter size");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  mergesort(0,n-1);
  
  

}
