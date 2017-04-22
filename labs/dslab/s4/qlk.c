#include<stdlib.h>
#include<stdio.h>
struct node{
  int data;
  struct node *link;
}*front=NULL,*temp=NULL,*rear=NULL;
void ins()
{
struct node  *p = (struct node *) malloc(sizeof(struct node));
  printf("Enter item to insert");
  scanf("%d",&p->data);
 p->link=NULL;
  if (front==NULL)
    {
      front=p;
      rear=p;
    }
 
  else {
    rear->link=p;
  rear=p;
  
  }}
   void del()
   {

     if(front==NULL)
       printf("Queue is empty");
else{
  temp=front;
  if(front==rear)
    {
      front=NULL;
      rear=NULL;
    }
  else
    {
       front=front->link;
    }
  printf("Deleted item:%d",temp->data);
  free(temp);
    }

}
void display()
{
 

  if(front==NULL)
    {
      printf("Queue is empty");
      return;
}
  else
    {
  temp=front;
  while(temp->link!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->link;
  }
    }  printf("%d",temp->data);
}
void main()
{char y;
  int c;
  do{  printf("MENU\n1.Insert\n2.Delete\n3.Display");
  printf("Enter choice");
  scanf("%d",&c);
  
  switch(c) 
    {
    case 1:ins();
      break;
    case 2:del();
      break;
    case 3:display();
      break;
    }
  printf("\nDo you want to continue?");
  __fpurge(stdin);
	   scanf("%c",&y);

	   }while(y=='y');

}
