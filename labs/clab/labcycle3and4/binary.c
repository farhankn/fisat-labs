/*To do binary search in an array*/
#include<stdio.h>
int binary(int a[],int n);
 main()
 {
    int a[100],n,i,c;
    printf("Enter the no. of elements ");
    scanf("%d",&n);
    printf("Enter the elements ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    c = binary(a,n);
    
 }
  int binary(int a[],int n)
 {
    int i,l,m,u,s;
    l=0;
    u=n;
    printf("Enter the number to be searched ");
    scanf("%d",&s);
    while(l<=u)
  	{
  	  m=((l+u)/2);
  	  if(a[m]==s)
	    {
	      printf("Element found at postion %d", m);
	      break;
	    }
          else if(s<a[m])
          u=m-1;
          else
          l=m+1;
        }
   if(l>u)
     printf("Number not found\n");
  }
 
  

