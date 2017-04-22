//Linked list as a Stack
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
  int data;
  struct node *next;
}*top=NULL;
main()
{
  int choice;
  do
    {
      printf("\nMenu:");
      printf("\n 1 Push");
      printf("\n 2 Pop");
      printf("\n 3 Display");
      printf("\n 4 Exit\n Enter your choice:");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1:push();
	  break;
	case 2:pop();
	  break;
	case 3:display();
	  break;
	case 4:exit(0);
	default:printf("\nInvalid choice\n");
	}
    }while(choice!=4);
}

void push()
{
  int item;
  struct node *p;
  p=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted: ");
  scanf("%d",&item);
  p->data=item;
  p->next=top;
  top=p;
}

void pop()
{
  struct node *temp;
  if(top==NULL)
    printf("\nThe linked list is empty\n");
  else
    {
      temp=top;
      top=top->next;
      printf("\nThe deleted element is %d\n",temp->data);
      free(temp);
    }
}

void display()
{
  struct node *temp;
  if(top==NULL)
    printf("\nLinked list is empty\n");
  else
    {
      temp=top;
      printf("\nThe elements in the stack are:\n");
      while(temp!=NULL)
	{
	  printf(" %d ",temp->data);
	  temp=temp->next;
	}
      printf("\n");
    }
}
