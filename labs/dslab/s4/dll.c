#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *llink;
  struct node *rlink;
}*head,*tail,*temp,*a,*b,*loc;
int cn=0;
void inbeg()
{
  struct node *p =(struct node *) malloc(sizeof(struct node));
  printf("Enter item");
  scanf("%d",&p->data);
  p->llink=NULL;
  p->rlink=head;
  if(head==NULL)
    tail=p;
  else
    head=head->llink;
  head=p;
  cn++;

}
void inend()
{

struct node *p = (struct node *) malloc(sizeof(struct node));
      printf("Enter item");
      scanf("%d",&p->data);
      p->rlink=NULL;
      p->llink=tail;
      if(head==NULL)
	head=p;
      else 
	tail->rlink=p;
      tail=p;
      cn++;
}
void inpos()
{int r,i;
  printf("Enter position");
  scanf("%d",&r);
  if(r>cn+1)
  { printf("not possible");
  return;}
  else if(r==1)
    inbeg();
  else if(r==cn+1)
	 inend();
  else 
    {
 struct node *p = (struct node *) malloc(sizeof(struct node));
      printf("Enter item");
      scanf("%d",&p->data);
      a=head;
      b=head->rlink;
      for(i=1;i<(r-1);i++)
	{	a=a->rlink;
		b=b->rlink;
	}
      p->llink=a;
      p->rlink=b;
      a->rlink=p;
      b->llink=p;
      cn++;
}
}
void debe()
{
  if(head==NULL)
    printf( "D Linked list is empty");
  else
    {
      temp=head;
      if(head!=tail)
	{
	  head=head->rlink;
	  head->llink=NULL;
	}
      else{
	head=NULL;
	tail=NULL;
      }
      printf("Deleted item:%d",temp->data);
      free(temp);
      cn--;
      
}
}
void deend()
{
  if(head==NULL)
    printf("Linked list is empty");
 else
   {temp=tail;
     if(head==tail)
       {
	 head=NULL;
	 tail=NULL;
       }

     else
       {
	 tail=tail->llink;
	 tail->rlink=NULL;
	 
       }
printf("Deleted item:%d",temp->data);
      free(temp);
      cn--;
}
}
void debet()
{int pos,i;
  if(head==NULL)
    
    printf("Linked list is empty");
  else
    {
      printf("Enter pos");
      scanf("%d",&pos);
      if(pos==cn)
	deend();
else  if(pos==1)
  debe();
      else{
      if(pos>cn)
	return;
	
      temp=head;
      loc=head->rlink;
      for(i=1;i<(pos-1);i++)
	{
	  temp=temp->rlink;
	  loc=loc->rlink;
	 
	}
      temp->rlink=loc->rlink;
      loc->rlink->llink=temp;
      printf("Deleted item:%d",loc->data);
      free(loc);
      cn--;
      }}
}

void disfr()
{
  if(head==NULL)
    {
      printf("empty");
      return;
}
  else
    {printf("Elements:");
  temp=head;
  while(temp->rlink!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->rlink;
  }
    }  printf("%d",temp->data);
}
void disrev()
{
  if(head==NULL)
    {
      printf("empty");
      return;
}
  else
    {printf("Elements:");
  temp=tail;
  while(temp->llink!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->llink;
  }
    }  printf("%d",temp->data);
}
void main()
{char y;
  int c;
  do{  printf("MENU\n1.Insert at beg\n2.Insert at end\n3.Insert at pos\n4.Delete from beg\n5.Deleted from end\n6.Deleted from pos\n7.Forward Traversal\n8.Reverse Traversal");
  printf("Enter choice");
  scanf("%d",&c);
  
  switch(c) 
    {
    case 1:inbeg();
      break;
    case 2:inend();
      break;
    case 3:inpos();
      break;
    case 4:debe();
      break;
    case 5:deend();
      break;
    case 6:debet();
      break;
    case 7:disfr();
      break;
    case 8:disrev();
      break;
    }
  printf("\nDo you want to continue?");
  __fpurge(stdin);
	   scanf("%c",&y);

	   }while(y=='y');

}
