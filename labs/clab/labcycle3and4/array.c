/*Menu driven program to insert,delete and find the occurance of an element in an array*/
#include<stdio.h>
int insert(int a[],int);
int delete(int a[],int);
int occur(int a[],int);
main()
{
  int a[100],n,i,num,c;
  printf("Enter the number of elements ");
  scanf("%d",&n);
  printf("Enter the array elements ");
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  c=n;
   do
    { 
     printf("Enter the number to do the following:(4 to stop) \n1:Delete an element\n2:Insert an element\n3:Find the occurance of an element\n");
     scanf("%d",&num);
     n=c;
        switch(num)
            { case 1:c=delete(a,n);
                      break;
              case 2:c=insert(a,n);
                      break;
    	      case 3:c=occur(a,n);
                      break;
              default:printf("Invalid number\n");
             }
    }while(num!=4);
     printf("Exiting\n");
}

  int delete(int a[],int n)
  {
     int i,s,j;
     printf("Enter number to be deleted ");
     scanf("%d",&s);
     for(i=0;i<n;i++)
       {
          if(a[i]==s)
	    {
          for(j=i;j<=n;j++)
             a[j]=a[j+1];
	  n--;
	    }
       }
     printf("The new array is :\n");
     for(i=0;i<n-1;i++)
          printf("%d\t",a[i]);
     printf("\n");
     return n;
  }
  int insert(int a[],int n)
 { 
    int i,s,p;
     printf("Enter the number and position ");
     scanf("%d%d",&s,&p);
     for(i=n;i>=p;i--)
           a[i]=a[i-1];
     a[p-1]=s; 
     printf("The new array is :\n");
     for(i=0;i<=n;i++)
           printf("%d\t",a[i]);
     printf("\n");
     return n+1;
  }
  int occur(int a[],int n)
 {
    int i,count=0,s;
    printf("Enter the number ");
    scanf("%d",&s);
    for(i=0;i<n;i++)
      {
        if(a[i]==s)
        count=count+1;
      }
    printf("No. of occurance of %d is %d\n",s,count);
    return n;
 }
  

