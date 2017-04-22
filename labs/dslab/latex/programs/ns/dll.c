//Program to implement a doubly linked list dynamically.
#include<stdio.h>
#include<stdlib.h>
void inbeg();
void inend();
void inpos();
void debeg();
void deend();
void depos();
void displaybeg();
void displayend();
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
struct node *start=NULL,*tail=NULL;
void main()
{
  int choice;
  do
    {
      printf("\n\t\tMENU\n\t\t*****\n\t1.Insert at start.\n\t2.Insert at end.\n\t3.Insert at a position.\n\t4.Delete from start.\n\t5.Delete from end.\n\t6.Delete from position.\n\t7.Display from Beginning.\n\t8.Display from End.\n\t9.Exit.\nEnter your choice:");
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
	case 7:displaybeg();
	  break;
	case 8:displayend();
	  break;
	case 9:break;
	default:printf("Invalid choice!!\n");
	}
    }
 while(choice!=9);
}

//Function to insert node at the start.
void inbeg()
{
  struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  printf("Enter data:");
  scanf("%d",&p->data);
  p->prev=NULL;  
  p->next=start;
  if(start!=NULL)
    {
      start->prev=p;
    }
  else
    {
      tail=p;
    }
  start=p;
}

//Function to insert node at the end.
void inend()
{
  struct node *p,*temp;
  p=(struct node*)malloc(sizeof(struct node));
  printf("Enter data:");
  scanf("%d",&p->data);
  p->next=NULL;
  p->prev=tail;
  if(tail!=NULL)
    {
      tail->next=p;
    }
  else
    {
      start=p;
        
    }
  tail=p;
}

//Function to insert node at a position.
void inpos()
{
  struct node *a,*b;
  int pos,i;
  printf("\nEnter position:");
  scanf("%d",&pos);
  if(start==NULL)
    printf("The linked list is empty.\n");
  else
    {
      if(pos==1)
	inbeg();
      else
	{
	  struct node *p;
	  p=(struct node*)malloc(sizeof(struct node));
	  
	  a=start;
	  b=a->next;
	  for(i=1;i<pos-1;i++)
	    {
	      a=a->next;
	      b=b->next;
	      if(b==NULL)            //
		{
		  printf("Invalid position...Cannot insert..!\n");
		  break;
		}
	      if(a==NULL)
		{
		  printf("\nInvalid position!!Cannot insert..\n");
		  break;
		}
	    }
  if((i==pos-1) && (b!=NULL))
	    {
	      printf("Enter data:");
	      scanf("%d",&p->data);
	      p->prev=a;
	      p->next=b;
	      a->next=p;
	      b->prev=p;
	    }

	} 
    }
  
}
//Function to delete a node from the beginning.
void debeg()
{
  struct node *temp;
  if(start!=NULL)
    {
      temp=start; 
      printf("Deleted element is %d.\n",temp->data);
      
      if(start!=tail)
	{
	  start=start->next;
	  start->prev=NULL;
	}
      else
	{
	  start=NULL;
	  tail=NULL;
	}
      free(temp);
    }
  else
    printf("\nThe Linked List is empty.");
}

//Function to delete a node from the end.
void deend()
{
  struct node *temp;
  if(start==NULL)
    printf("\nThe Linked List is empty.");
  else
    {
      temp=tail; 
      printf("\nDeleted element is %d.\n",temp->data);
      if(start!=tail)
	{
	  tail=tail->prev;
          tail->next=NULL;
	}
      else
	{
	  start=NULL;
	  tail=NULL;
	}
     free(temp);
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
	      
	}
      if((i==pos-1)&& (loc->next!=NULL))
	    {
	      temp->next=loc->next;
	      (loc->next)->prev=temp;
	      printf("\nDeleted element is %d.",loc->data);
	      free(loc);
	    }
else if((i==pos-1) &&(loc->next==NULL))
deend();    
}
}

//Function for Forward traversal.
void displaybeg()
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

//Function for Reverse traversal.
void displayend()
{
  struct node *temp;
  if(start==NULL)
    printf("\nThe linked list is empty.");
  else
    {
      temp=tail;
      while(temp->prev!=NULL)
	{
	  printf("%d\t",temp->data);
	  temp=temp->prev;
	}
      printf("%d\t\n",temp->data);
    }
}
