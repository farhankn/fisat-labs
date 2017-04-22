//Program to implement a priority queue.
#include<stdio.h>
void insert();
void delete();
void display();

int a[50][50],r[50],f[50],ro,c;
void main()
{
  int op,i;
  printf("Enter the maximum size of the priority queue:");
  scanf("%d%d",&ro,&c);
  for(i=0;i<c;i++)
    {
      f[i]=0;
      r[i]=0;
    }
  do
    {
      
      printf("\n\tMENU\n\t****\n\t1.INSERT\n\t2.DELETE\n\t3.DISPLAY\n\t4.EXIT");
      printf("\nEnter your choice:");
      scanf("%d",&op);
      switch(op)
	{
	case 1:insert();
	  break;
	case 2:delete();
	  break;
	case 3:display();
	  break;
	case 4:break;
	default:printf("Invalid choice!!\n");
	}
    }while(op!=4);
}

//Function to insert element.
void insert()
{
  int pr,item;
  printf("Enter the priority:");
  scanf("%d",&pr);
  if(pr>ro)
    printf("Priority out of range.\n");
  else
    {
      if(r[pr]>=c)
	printf("Priority queue is full.\n");
      else
	{
	  printf("Enter the element:");
	  scanf("%d",&item);
	  r[pr]++;
	  a[pr][r[pr]]=item;
	  if(f[pr]==0)
	    f[pr]=1;
	}
    }
}

//Function to delete element.
void delete()
{
  int pr,item;
  pr=ro;
  while(pr>=1)
    {
      if(f[pr]==0)
	{
	  printf("No elements of Priority %d.\n",pr);
	  pr--; 
	}
      else
	{
	  item=a[pr][f[pr]];
	  a[pr][f[pr]]=0;
	  printf("Deleted element is %d of priority %d.\n",item,pr);
	  if(f[pr]==r[pr])
	    {
	      f[pr]=0;
	      r[pr]=0;
	    }
    	    f[pr]++;
	  break;
	}
    }
}

//Function to display priority queue.
void display()
{
  int i,j ;
  printf("The priority queue is a s follows:\n");
  for(i=1;i<=ro;i++)
    {
      printf("\nElements of priority %d.\n",i);
      for(j=1;j<=c;j++)
	{
	  printf("%d\t",a[i][j]);
	}
    }
}
