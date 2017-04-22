//program to implement a  dequeue using array.
#include<stdio.h>
void inject();
void pop();
void push();
void eject();
void display();

int queue[50],rear=0,front=0,max;
void main()
{
  int op;
  printf("Enter the maximum size of the queue:");
  scanf("%d",&max);
  do
    {
      
      printf("\n\t\tMENU\n\t\t****\n\t1.PUSH\n\t2.POP\n\t3.INJECT\n\t4.EJECT\n\t5.DISPLAY\n\t6.EXIT");
      printf("\nEnter your choice:");
      scanf("%d",&op);
      switch(op)
	{
	case 1:push();
	  break;
	case 2:pop();
	  break;
	case 3:inject();
	  break;
	case 4:eject();
	  break;
	case 5:display();
	  break;
	case 6:break;
	default:printf("Invalid choice!!\n");
	}
    }while(op!=6);
}

//Function to push elements.
void push()
{
  int temp;
  if(front==0)
    temp=1;
  else if(front==1)
    temp=max;
  else
    temp=front-1;
  if(temp==rear)
    printf("Dequeue is full.\n");
  else
    {
      printf("Enter the element:");
      front=temp; 
      if(rear==0)
	rear=1;
      scanf("%d",&queue[front]);
    }
}

//Function to inject elements.
void inject()
{
 
  if((rear%max)+1==front)
    printf("Dequeue is full!!\n");
  else
    {
      printf("Enter the element:");
      rear=(rear%max)+1;
      scanf("%d",&queue[rear]);
      if(front==0)
	front=1;
    }

}

//Function to pop elements.
void pop()
{
  int ele;
  if(front==0)
    printf("Dequeue is empty!!\n");
  else
    {
      ele=queue[front];
      if(front==rear)
	{
	  front=0;
	  rear=0;
	}
      else
	front=(front%max)+1;
      printf("The deleted element is %d.\n",ele);
    }
}

//Function to eject elements.
void eject()
{
  int item;
  if(front==0)
    printf("Queue is empty!!!\n");
  else
    {
    item=queue[rear];
    if(rear==front)
      {
	front=0;
	rear=0;
      }
    else if(rear==1)
      rear=max;
    else
      rear--;
    printf("\nDeleted element is %d.\n",item);
    }
}

//Function to display elements.
void display()
{
  int i;
  if(front==0)
    printf("Dequeue is empty!!\n");
  else
    {
      printf("The queue is as follows:\n");
      for(i=front;i!=rear;)
	{
	  printf("%d\t",queue[i]);
	  i=(i%max)+1;
	}
  printf("%d\n",queue[rear]);
    }
}
