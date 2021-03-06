/*queue using singly linked list*/
#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();

struct node
{
  int data;
  struct node *next;
}*front=NULL,*rear=NULL;

main()
{
  int choice;
  do
    {
      printf("\nMenu \n 1 Insert \n 2 Delete \n 3 Display \n 4 Exit\n Enter your choice ");
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
	  printf("\nInvalid choice\n");
	}
    }while(choice!=4);
}

void insert()
{
  int item;
  struct node *p;
  p=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted: ");
  scanf("%d",&item);
  p->data=item;
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

void delete()
{
  struct node *temp;
  if(front==NULL)
    printf("\nThe Queue is empty\n");
  else
    {
      temp=front;
      printf("\nThe deleted element is %d\n",temp->data);
      if(front==rear)
	{
	  front=NULL;
	  rear=NULL;
	}
      else
	front=front->next;
      free(temp);
    }
}

void display()
{
  struct node *temp;
  if(front==NULL)
    printf("\nQueue is empty\n");
  else
    {
      temp=front;
      printf("\nThe elements in the linked list are:\n");
      while(temp!=NULL)
	{
	  printf(" %d ",temp->data);
	  temp=temp->next;
	}
      printf("\n");
    }
}
