//Operations in a Singly Linked list
#include<stdio.h>
#include<stdlib.h>
void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void display();
struct node
{
  int data;
  struct node *next;
}*start=NULL;
main()
{
  int choice;
  do
    {
      printf("\nMenu:");
      printf("\n 1 Insert at Beginning");
      printf("\n 2 Insert at End");
      printf("\n 3 Insert at a Position");
      printf("\n 4 Delete from Beginning");
      printf("\n 5 Delete from End");
      printf("\n 6 Delete from a Position");
      printf("\n 7 Display");
      printf("\n 8 Exit\n Enter your choice:");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1:insertbeg();
	  break;
	case 2:insertend();
	  break;
	case 3:insertpos();
	  break;
	case 4:deletebeg();
	  break;
	case 5:deleteend();
	  break;
	case 6:deletepos();
	  break;
	case 7:display();
	  break;
	case 8:exit(0);
	default:printf("\nInvalid choice\n");
	}
    }while(choice!=8);
}

void insertbeg()
{
  int item;
  struct node *p;
  p=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted: ");
  scanf("%d",&item);
  p->data=item;
  p->next=start;
  start=p;
}

void insertend()
{
  int item;
  struct node *p,*temp;
  p=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted: ");
  scanf("%d",&item);
  temp=start;
  while(temp->next!=NULL)
    temp=temp->next;
  temp->next=p;
  p->data=item;
  p->next=NULL;
}

void insertpos()
{
  int item,pos,i;
  struct node *p,*temp;
  p=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the position: ");
  scanf("%d",&pos);
  if(pos==1)
    insertbeg();
  else
    {
      temp=start;
      for(i=1;i<(pos-1);i++)
	{
	  temp=temp->next;
	  if(temp==NULL)
	    {
	      printf("\nCannot insert\n");
	      break;
	    }
	}
      if(i==(pos-1))
	{
	  printf("\nEnter the element to be inserted: ");
	  scanf("%d",&item);
	  p->next=temp->next;
	  temp->next=p;
	  p->data=item;
	}    
    }
}

void deletebeg()
{
  struct node *temp;
  if(start==NULL)
    printf("\nThe linked list is empty\n");
  else
    {
      temp=start;
      start=start->next;
      printf("\nThe deleted element is %d\n",temp->data);
      free(temp);
    }
}

void deleteend()
{
  struct node *temp,*loc;
  if(start==NULL)
    printf("\nThe linked list is empty\n");
  else if(start->next==NULL)
    deletebeg();
  else
    {
      temp=start;
      loc=temp->next;
      while(loc->next!=NULL)
	{
	  temp=temp->next;
	  loc=loc->next;
	}
      temp->next=NULL;
      printf("\nThe deleted element is %d\n",loc->data);
      free(loc);
    }
}

void deletepos()
{
  struct node *temp,*loc;
  int pos,i;
  printf("\nEnter the position\t");
  scanf("%d",&pos);
  if(start==NULL)
    printf("\nLinked list is empty\n");
  else
    {
      if(pos==1)
	deletebeg();
      else
	{
	  temp=start;
	  loc=temp->next;
	  for(i=1;i<(pos-1);i++)
	    {
	      temp=temp->next;
	      loc=loc->next;
	      if(loc==NULL)
		{
		  printf("\nCannot delete\n");
		  break;
		}
	    }
	  if(i==(pos-1))
	    {
	      temp->next=loc->next;
	      printf("\nthe deleted element is %d\n",loc->data);
	      free(loc);
	    }
	}
    }
}
void display()
{
  struct node *temp;
  if(start==NULL)
    printf("\nLinked list is empty\n");
  else
    {
      temp=start;
      printf("\nThe elements in the linked list are:\n");
      while(temp!=NULL)
	{
	  printf(" %d ",temp->data);
	  temp=temp->next;
	}
      printf("\n");
    }
}
