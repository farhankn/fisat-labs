#include<stdio.h>
int a[20],n,u=1;
void quick(int f,int l)
{int p,i,j,temp,k;
  if(f<l)
    {
      p=a[f];
      i=f;
      j=l;
      while(i<=j)
	{
	  while(a[i]<=p&&i<=l)
	    i++;
	  while(a[j]>=p&&j>f)
	    j--;
	  if(i<j)
	    {
	      temp=a[i];
	      a[i]=a[j];
	      a[j]=temp;
	    }
	}
      temp=a[f];
      a[f]=a[j];
      a[j]=temp;
          printf("Pass %d:",u++);
      for(k=0;k<n;k++)
	printf("%d ",a[k]);
      printf("\n");
      
      
      quick(f,j-1);
      quick(j+1,l);
     
    }
}
main()
{
  int i;
  printf("Enter size");
  scanf("%d",&n);
  printf("Enter the elemnets");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  quick(0,n-1);
  
}
