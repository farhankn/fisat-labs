#include<stdio.h>
main()
{
  int i,j,min,a[20],temp,loc,n,k;
  printf("Enter size");
  scanf("%d",&n);
  printf("Enter the elemnets");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n-1;i++)
    {
      min=a[i];
      loc=i;
      for(j=i+1;j<n;j++)
	if(a[j]<min)
	  {min=a[j];
	    loc=j;
	  }
      if(loc!=i)
	{
	  temp=a[i];
	  a[i]=a[loc];
	  a[loc]=temp;
	}
      printf("PASS %d:",i+1);
      for(k=0;k<n;k++)
	printf("%d ",a[k]);
      printf("\n");
    }
}
