#include<stdlib.h>
#include<stdio.h>
struct node{
  int data;
  struct node *link;
}*start=NULL,*temp=NULL,*loc=NULL;/*
temp=NULL;
loc=NULL;
start=NULL;*/
int cn=0;
void inbeg()
{
struct node  *p = (struct node *) malloc(sizeof(struct node));
  printf("Enter item to insert");
  scanf("%d",&p->data);

  if (start==NULL)
  p->link=NULL;
  else 
    p->link=start;
  start=p;
  cn++;
 
}
void inend()
{
  if (start==NULL)
    inbeg();
  else
    { struct node *p = (struct node *) malloc(sizeof(struct node));
      printf("Enter item");
      scanf("%d",&p->data);
      p->link=NULL;
      temp=start;
      while(temp->link!=NULL)
	temp=temp->link;
      temp->link=p;
      cn++;
    }
}
void inpos()
{int r,i;
  printf("Enter position");
  scanf("%d",&r);
  if(r==1)
    inbeg();
  else
    {
 struct node *p = (struct node *) malloc(sizeof(struct node));
      printf("Enter item");
      scanf("%d",&p->data);
      temp=start;
      for(i=1;i<(r-1);i++)
	temp=temp->link;
      p->link=temp->link;
      temp->link=p;
      cn++;
}
}
void debe()
{
  if(start==NULL)
    printf("Linked list is empty");
  else
    {
      temp=start;
      start=start->link;
      printf("Deleted item:%d",temp->data);
      free(temp);
      cn--;
}
}
void deend()
{
  if(start==NULL)
    printf("Linked list is empty");
 else
   {
     if(start->link==NULL)
       {
	 temp=start;
	 start=NULL;
	 printf("Deleted item:%d",temp->data);
	 free(temp);
	 cn--;
       }

     else
       {
	 temp=start;
	 loc=start->link;
	 while(loc->link!=NULL)
	   { temp=temp->link;
	     loc=loc->link;}
      
	 temp->link=NULL;
	 printf("Deleted item:%d",loc->data);
	 free(loc);
	 cn--;
       }
}
}
void debet()
{int pos,i;
  if(start==NULL)
    
    printf("Linked list is empty");
  else
    {
      printf("Enter pos");
      scanf("%d",&pos);
      if(pos>cn)
	return;
      if(pos==1)
	debe();
      else{
      temp=start;
      loc=start->link;
      for(i=1;i<(pos-1);i++)
	{
	  temp=temp->link;
	  loc=loc->link;
	 
	}
      temp->link=loc->link;
      printf("Deleted item:%d",loc->data);
      free(loc);
      cn--;}
    }
}
void display()
{
  printf("***********");

  if(start==NULL)
    {
      printf("empty");
      return;
}
  else
    {
  temp=start;
  while(temp->link!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->link;
  }
      printf("%d",temp->data);
    }}
void main()
{char y;
  int c;
  do{  printf("MENU\n1.Insert at beg\n2.Insert at end\n3.Insert at pos\n4.Delete from beg\n5.Deleted from end\n6.Deleted from pos\n7.Display");
  printf("\nEnter choice");
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
    case 7:display();
      break;
    }
  printf("\nDo you want to continue?");
  __fpurge(stdin);
	   scanf("%c",&y);

	   }while(y=='y');

}
