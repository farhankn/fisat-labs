#include<stdlib.h>
#include<stdio.h>
struct node{
  int data;
  struct node *link;
}*top=NULL,*temp=NULL;
void push()
{
struct node  *p = (struct node *) malloc(sizeof(struct node));
  printf("Enter item to insert");
  scanf("%d",&p->data);

  if (top==NULL)
  p->link=NULL;
  else 
    p->link=top;
  top=p;
  
}
   void pop()
   {

     if(top==NULL)
       printf("Stack is empty");
else{
  temp=top;
  top=top->link;
  printf("Deleted item:%d",temp->data);
  free(temp);
}

}
void display()
{
 

  if(top==NULL)
    {
      printf("Stack is empty");
      return;
}
  else
    {
  temp=top;
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
  do{  printf("MENU\n1.PUSH\n2.POP\n3.DISPLAY");
  printf("Enter choice");
  scanf("%d",&c);
  
  switch(c) 
    {
    case 1:push();
      break;
    case 2:pop();
      break;
    case 3:display();
      break;
    }
  printf("\nDo you want to continue?");
  __fpurge(stdin);
	   scanf("%c",&y);

	   }while(y=='y');

}
