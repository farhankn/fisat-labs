//Arrray Implementation of A Double Ended Queue
#include<stdio.h>
int rear=0,front=0,size,dequeue[20];
void push();
void pop();
void inject();
void eject();
void display();
main()
{
  int i,choice;
  printf("\n Enter the Size of the DeQueue : ");
  scanf("%d",&size);
  do
    {
      printf("\nMENU\n1.Push(Front)\n2.Pop(Front)\n3.Inject(Rear)\n4.Eject(Rear)\n5.Display\n6.Exit");
      printf("\nEnter your choice\t");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1:
	  push();
	  break;
	case 2:
	  pop();
	  break;
	case 3:
	  inject();
	  break;
	case 4:
	  eject();
	  break;
	case 5:
	  display();
	  break;
	case 6:
	  exit(0);
	default:
	  printf("\nInvalid entry");
	}
    }while(choice!=6);
}

void push()
{
  int temp;
  if(front==0)
    temp=1;
  else if(front==1)
    temp=size;
  else
    temp=temp-1;
  if(temp==rear)
    printf("\nThe dequeue is full\n");
  else
    {
      front=temp;
      if(rear==0)
	rear=1;
      printf("\nEnter the element to be inserted: ");
      scanf("%d",&dequeue[front]);
    }
}

void eject()
{
  int item;
  if(front==0)
    printf("\nThe dequeue is empty\n");
  else
    {
      item=dequeue[rear];
      printf("\nThe deleted element is %d\n",item);
      if(rear==front)
	{
	  front=0;
	  rear=0;
	}
      else if(rear==1)
	rear=size;
      else
	rear=rear-1;
    }
}

void inject()
{
  int i;
  if(((rear%size)+1)==front)
    {
      printf("\nQueue is full\n");
    }
  else
    {
      for(i=0;i<1;i++)
	{
	  rear=((rear%size)+1);
	  printf("\nEnter the element to be inserted ");
	  scanf("%d",&dequeue[rear]);
	}
    }
  if(front==0)
    {
      front=1;
    }
}
void pop()
{
  int item;
  if(front==0)
    {
      printf("\nDequeue is empty\n");
    }
  else
    {
      item=dequeue[front];
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
      printf("\nDequeue is empty\n");
    }
  else
    {
      printf("\nThe dequeue is\n");
      for(i=front;i!=rear;i=((i%size)+1))
        {
          printf(" %d ",dequeue[i]);
        }
      printf(" %d ",dequeue[rear]);
    }
}
