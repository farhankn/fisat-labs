//Implementation of Circular Queue
#include<stdio.h>
void insert();
void delete();
void display();
int rear=0,front=0,size;
int cqueue[5];
main()
{
  printf("\nEnter the Size of the circular Queue : ");
  scanf("%d",&size);
  int i,choice;
  do
    {
      printf("\nMenu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
      printf("Enter your choice: ");
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
	  printf("\nInvalid entry");
	}
    }while(choice!=4);
}
  
void insert()
{
  int i;
  if(((rear%size)+1)==front)
    {
      printf("\nCircular Queue is full\n");
    }
  else
    {
      for(i=0;i<1;i++)
	{
	  rear=((rear%size)+1);
	  printf("\nEnter the element to be inserted: ");
	  scanf("%d",&cqueue[rear]);
	}
    }
  if(front==0)
    {
      front=1;
    }
}
void delete()
{
  int item;
  if(front==0)
    {
      printf("\nCircular Queue is empty\n");
    }
  else
    {
      item=cqueue[front];
      printf("\nThe deleted element is %d",item);
      if(front==rear)
	{
	  front=0;
	  rear=0;
	}
      else
	{
	  front=(front%size)+1;
	}
    }
}
void display()
{
  int i;
  if(front==0)
    {
      printf("\nCircular Queue is empty\n");
    }
  else
    {
      printf("\nThe circular queue is\n");
      for(i=front;i!=rear;i=((i%size)+1))
        {
          printf(" %d ",cqueue[i]);
        }
      printf(" %d ",cqueue[rear]);
    }
}
