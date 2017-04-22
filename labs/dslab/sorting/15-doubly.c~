//Doubly Linked List

#include<stdio.h>
#include<stdlib.h>
void ibeg();
void iend();
void ipos();
void dbeg();
void dend();
void dpos();
void fdisplay();
void rdisplay();
struct node
{
  int data;
  struct node *next,*prev;
}*start=NULL,*tail=NULL;
int posg=0;
main()
{
  int choice;
  do
    {
      printf("\nMenu");
      printf("\n 1 Insert at beginning");
      printf("\n 2 Insert at end");
      printf("\n 3 Insert at a position");
      printf("\n 4 Delete from beginning");
      printf("\n 5 Delete from end");
      printf("\n 6 Delete from a position");
      printf("\n 7 Forward Display");
      printf("\n 8 Reverse Display");
      printf("\n 9 Exit");
      printf("\n Enter your choice: ");


      scanf("%d",&choice);
      switch(choice)
	{
	case 1:
	  ibeg();
	  break;
	case 2:
	  iend();
	  break;
	case 3:
	  ipos();
	  break;
	case 4:
	  dbeg();
	  break;
	case 5:
	  dend();
	  break;
	case 6:
	  dpos();
	  break;
	case 7:
	  fdisplay();
	  break;
	case 8:
	  rdisplay();
	  break;
        case 9:
          exit(0);
	default:
	  printf("\nInvalid choice\n");
	}
    }while(choice!=9);
}

void ibeg()
{
  int item;
  struct node *p;
  p=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted  ");
  scanf("%d",&item);
  posg++;
  p->data=item;
  p->next=start;
  p->prev=NULL;
  if(start!=NULL)
    start->prev=p;
  else
    tail=p;
  start=p;
}

void iend()
{
  int item;
  struct node *p;
  p=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the element to be inserted  ");
  scanf("%d",&item);
  if(tail!=NULL)
    tail->next=p;
  else
    start=p;
  p->data=item;
  p->next=NULL;
  p->prev=tail;
  tail=p;
  posg++;

}

void ipos()
{
  int item,pos,i,temp;
  struct node *p,*a,*b;
  p=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the position  ");
  scanf("%d",&pos);
  if(pos==1)
    ibeg();
  else
    {
      a=start;
      b=start->next;
      for(i=1;i<(pos-1);i++)
	{
	      if(pos>posg)
		{
		  printf("\nUnused positions, Exiting ");
		  break;
		}

	  a=a->next;
	  b=b->next;
	  /* if(a->prev==NULL)
	    {
	      iend();
	      break;
	      }*/

	  if(a==NULL)
	    {
	      printf("\nCannot insert\n");
	      break;
	    }
	}
      if(i==(pos-1))
	{
	  printf("\nEnter the element to be inserted  ");
	  scanf("%d",&item);
	  p->next=b;
	  p->prev=a;
	  a->next=p;
	  b->prev=p;
	  p->data=item;
	  posg++;
	}
    }    
}

void dbeg()
{
  struct node *temp;
  if(start==NULL)
    printf("\nThe linked list is empty\n");
  else
    {
      
      posg--;
      temp=start;
      printf("\nThe deleted element is %d\n",temp->data);
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
}

void dend()
{
  struct node *temp;
  if(tail==NULL)
    printf("\nThe linked list is empty\n");
  else
    {
      posg--;
      temp=tail;
      printf("\nThe deleted element is %d\n",temp->data);
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

void dpos()
{
  struct node *temp,*a,*b;
  int pos,i;
  printf("\nEnter the position  ");
  scanf("%d",&pos);
  if(start==NULL)
    printf("\nLinked list is empty\n");
  else
    {
      posg--;
      if(pos==1)
	dbeg();
      else
	{
	  a=start;
	  b=a->next;
	  for(i=1;i<(pos-1);i++)
	    {
	      a=a->next;
	      b=b->next;
	      if(b==NULL)
		{
		  printf("\nCannot delete\n");
		  break;
		}
	      
	    }
	  if(i==(pos-1))
	    {
	      a->next=b->next;
	      temp=b;
	      b=b->next;
	      b->prev=a;
	      printf("\nthe deleted element is %d\n",temp->data);
	      free(temp);
	    }
	}
    }
}

void fdisplay()
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
      printf("\n\n");
    }
}

void rdisplay()
{
 struct node *temp;
 if(start==NULL)
   printf("\nLinked list is empty\n");
 else
   {
     temp=tail;
     printf("\nThe elements in the linked list are:\n");
     while(temp!=NULL)
       {
	 printf(" %d  ",temp->data);
	 temp=temp->prev;
       }
     printf("\n\n");
   }
}
