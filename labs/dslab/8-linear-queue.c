//Array Implementation of Linear Queue
#include<stdio.h>
void insert();
void delete();
void display();
int rear=0,front=0,size;
int queue[20];
main()
{
  int i,choice;
  printf("\nEnter the Size of Queue: ");
  scanf("%d",&size);
  do
    {
      printf("\n\n\nMenu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
      printf("Enter your choice ");
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
  if(rear==size)
    {
      printf("\nQueue is full\n");
    }
  else
    {
      for(i=0;i<1;i++)
	{
	  rear=rear+1;
	  printf("\nEnter the element to be inserted: ");
	  scanf("%d",&queue[rear]);
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
      printf("\nQueue is empty\n");
    }
  else
    {
      item=queue[front];
      printf("\nThe deleted element is %d",item);
      if(front==rear)
	{
	  front=0;
	  rear=0;
	}
      else
	{
	  front=front+1;
	}
    }
}
void display()
{
  int i;
  if(front==0)
    {
      printf("\nQueue is empty\n");
    }
  else
    {
      printf("\nThe queue is\n");
      for(i=front;i<=rear;i++)
        {
          printf(" %d ",queue[i]);
        }
    }
}
