//Program to implement a dynamically implimented queue.
#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();
struct node
{
  int data;
  struct node *next;
};
struct node *front=NULL,*rear=NULL;
void main()
{
  int op;
  do
    {
      
      printf("\n\t\tMENU\n\t\t****\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT");
      printf("\nEnter your choice:");
      scanf("%d",&op);
      switch(op)
	{
	case 1:push();
	  break;
	case 2:pop();
	  break;
	case 3:display();
	  break;
	case 4:break;
	default:printf("Invalid choice!!\n");
	}
    }while(op!=4);
}

//Function to push elements.
void push()
{
 struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  printf("Enter data:");
  scanf("%d",&p->data);
  p->next=NULL;
  if(front==NULL)
    {
      front=p;
      rear=p;
    }
  else
    {
      rear->next=p;
      rear=p;
    }
}
//Function to pop elements.
void pop()
{
  int item;
  struct node *temp;
  if(front==NULL)
    printf("Empty Queue.\n");
  else
    {
      temp=front;
      if(front==rear)
	{
	  front=NULL;
	  rear=NULL;
	}
      else
	front=front->next;
      item=temp->data;
      printf("Deleted element is %d.\n",item);
      free(temp);
    }
}

//Function to display the stack.
void display()
{
  struct node *temp1;
  if(front==NULL)
    {
      printf("Empty Queue.\n");
    }
  else
    {
      temp1=front;
      while(temp1!=NULL)
	{
	  printf("%d\t",temp1->data);
	  temp1=temp1->next;
	}
    }
}
