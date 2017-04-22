#include<stdio.h>
main()
{
  int i,j,m,a[20],n,k;
  printf("Enter size");
  scanf("%d",&n);
  printf("Enter the elemnets");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=1;i<n;i++)
    {
      m=a[i];
      
      for(j=i-1;j>=0;j--)
	if(a[j]>m)
	  a[j+1]=a[j];
	else
	  break;  
	
      a[j+1]=m;
      printf("PASS %d:",i);
      for(k=0;k<n;k++)
	printf("%d ",a[k]);
      printf("\n");
    }
}
