//Program to implement singly linked list dynamically.
#include<stdio.h>
#include<stdlib.h>
void inbeg();
void inend();
void inpos();
void debeg();
void deend();
void depos();
void display();
struct node
{
  int data;
  struct node *next;
};
struct node *start=NULL;
void main()
{
  int choice;
  do
    {
      printf("\n\t\tMENU\n\t\t*****\n\t1.Insert at start.\n\t2.Insert at end.\n\t3.Insert at a position.\n\t4.Delete from start.\n\t5.Delete from end.\n\t6.Delete from position.\n\t7.Display.\n\t8.Exit.\nEnter your choice:");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1:inbeg();
	  break;
	case 2:inend();
	  break;
	case 3:inpos();
	  break;
	case 4:debeg();
	  break;
	case 5:deend();
	  break;
	case 6:depos();
	  break;
	case 7:display();
	break;
	case 8:break;
	default:printf("Invalid choice!!\n");
	}
    }
 while(choice!=8);
}

//Function to insert node at the start.
void inbeg()
{
  struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  printf("Enter data:");
  scanf("%d",&p->data);
  if(start==NULL)
    {
      p->next=NULL;
      start=p;
    }
  else
    {
      p->next=start;
      start=p;
    }
}

//Function to insert node at the end.
void inend()
{
  struct node *p,*temp;
  p=(struct node*)malloc(sizeof(struct node));
  printf("Enter data:");
  scanf("%d",&p->data);
  p->next=NULL;
  if(start==NULL)
    {
      start=p;
    }
  else
    {
      temp=start;
      while(temp->next!=NULL)
	temp=temp->next;
      temp->next=p;
      
    }
}

//Function to insert node at a position.
void inpos()
{
  int pos,i;
  printf("\nEnter position:");
  scanf("%d",&pos);
  if(pos==1)
    inbeg();
  else
    {
      struct node *p,*temp;
      p=(struct node*)malloc(sizeof(struct node));
            if(start==NULL)
	{
	  start=p;
	}
      else
	{
	  temp=start;
	  for(i=1;i<pos-1;i++)
	    {
	      temp=temp->next;
	      if(temp==NULL)
		{
		  printf("\nInvalid position!!Cannot insert..\n");
		  break;
		}
	    }
	  if(i==pos-1)
	    {
	      printf("Enter data:");
	      scanf("%d",&p->data);
	      p->next=temp->next;
	      temp->next=p;
	    }
	} 
    }
}

//Function to delete a node from the beginning.
void debeg()
{
  struct node *temp;
  if(start==NULL)
    printf("\nThe Linked List is empty.");
  else
    {
      temp=start; 
      start =start->next;
      printf("Deleted element is %d.\n",temp->data);
      free(temp);
    }
}

//Function to delete a node from the end.
void deend()
{
  struct node *temp,*loc;
  if(start==NULL)
    printf("\nThe Linked List is empty.");
  else
    {
      temp=start; 
      loc=start->next;
      while(loc->next!=NULL)
	{
	  temp=temp->next;
	  loc=loc->next;
	}
      temp->next=NULL;
      printf("Deleted element is %d.\n",loc->data);
      free(loc);
    }
}
//Function to delete node from a position.
void depos()
{
  struct node *temp,*loc;
  int pos,i;
  printf("\nEnter the Position:");
  scanf("%d",&pos);
  if(start==NULL)
    printf("\nTHE Linked List is empty.");
  else
    {
      
      if(pos==1)
	debeg();
      else
	{
	  temp=start;
	  loc=temp->next;
	  for(i=1;i<pos-1;i++)
	    {
	      temp=temp->next;
	      loc=loc->next;
	      if(loc==NULL)
		{
		  printf("\nInvalid position!!Cannot delete..\n");
		  break;
		}
	    }
	  if(i==pos-1)
	    {
	      temp->next=loc->next;
	      printf("\nDeleted element is %d.",loc->data);
	      free(loc);
	    }
	}
    }
}
//Function to display the linked list.
void display()
{
  struct node *temp;
  if(start==NULL)
    printf("\nThe linked list is empty.");
  else
    {
      temp=start;
      while(temp!=NULL)
	{
	  printf("%d\t",temp->data);
	  temp=temp->next;
	}
    }
}
