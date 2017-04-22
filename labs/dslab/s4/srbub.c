
#include<stdio.h>
main()
{
  int i,j,min,a[20],temp,loc,n,k;
  printf("Enter size");
  scanf("%d",&n);
  printf("Enter the elemnets");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++)
    {
      
      for(j=0;j<n-i-1;j++)
	if(a[j]>a[j+1])
	  {temp=a[j];
	    a[j]=a[j+1];
	    a[j+1]=temp;
	    
	  }
    
      printf("PASS %d:",i+1);
      for(k=0;k<n;k++)
	printf("%d ",a[k]);
      printf("\n");
    }
}
