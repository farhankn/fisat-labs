/*Multiqueue implimentation using matrix*/

#include<stdio.h>
void insert();
void delete();
void display();
int r[10],f[10],a[10][10],n,pr;

main()
{
  printf("\n Enter the Priority Range: ");
  scanf("%d",&n);
  int choice,i;
  //Init-Priority
  for(i=1;i<=n;i++)
    {
      r[i]=0;
      f[i]=0;
    }
  do
    {
      printf("\n[1]Insert\n[2]Delete\n[3]Display\n[4]Exit\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1:
	  insert();
	  break;
	case 2:
	  delete();
	  break;
	case 3:
	  display();
	  break;
	case 4:
	  exit(0);
	default:
	  printf("\nInvalid choice");
	}
    }while(choice!=4);
}



void insert()
{
  int e;
  printf("\nEnter an element: ");
 scanf("%d",&e);
  printf("\nEnter the priority of %d -->",e);
  scanf("%d",&pr);
  if(pr>n)
    printf("\nPriority is out of range ");
  else
    {
      if(r[pr]>=n)
	printf("\nThe queue is full");
      else
	{
      	  r[pr]=r[pr]+1;
	  a[pr][r[pr]]=e;
	  if(f[pr]==0)
	    f[pr]=1;
	}
    }
}




void delete()
{
  int item;
  pr=n;
  while(pr>=1)
    {
      if(f[pr]==0)
	{
	  printf("\nThe queue of priority %d is empty\n",pr);
	  pr=pr-1;
	}
      else
	{
	  item=a[pr][f[pr]];
	  a[pr][f[pr]]=0;
          printf("\nthe deleted element is %d with priority %d\n",item,pr);
	  if(f[pr]==r[pr])
	    {
	      f[pr]=0;
	      r[pr]=0;
	    }
	  else
	    f[pr]=f[pr]+1;
	  break;
	}
    }
}



void display()
{
  int i,j;
  for(i=1;i<=n;i++)
    {
      printf(" Priority %d : ",i);
      for(j=1;j<=3;j++)
	printf(" %d ",a[i][j]);
      printf("\n");
    }
}
