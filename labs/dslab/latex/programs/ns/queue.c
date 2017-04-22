//program to implement a linear queue using array.
#include<stdio.h>
void insert();
void delete();
void display();

int queue[50],rear=0,front=0,max;
void main()
{
  int op;
  printf("Enter the maximum size of the queue:");
  scanf("%d",&max);
  do
    {
      
      printf("\t\tMENU\n\t\t****\n\t1.INSERT\n\t2.DELETE\n\t3.DISPLAY\n\t4.EXIT");
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
//Function to insert elements.
void insert()
{
 
  if(rear==max)
    printf("Queue is full!!\n");
  else
    {
      printf("Enter the element:");
      rear=rear+1;
      scanf("%d",&queue[rear]);
      if(front==0)
	front=1;
    }

}

//Function to delete elements.
void delete()
{
  int ele;
  if(front==0)
    printf("Queue is empty!!\n");
  else
    {
      ele=queue[front];
      if(front==rear)
	{
	  front=0;
	  rear=0;
	}
      else
	front++;
      printf("The deleted element is %d.\n",ele);
    }
}

//Function to display elements.
void display()
{
  int i;
  if(front==0)
    printf("Queue is empty!!\n");
  else
    {
      printf("The queue is as follows:\n");
      for(i=front;i<=rear;i++)
	printf("%d\t",queue[i]);
      printf("\n");
    }
}
