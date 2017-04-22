#include<stdio.h>
int q[100];
 int front=0,rear=0,n;
void inject()
{int item;
  if ((rear%n)+1==front)
    printf("deque if full");
  else
    {  rear=(rear%n)+1;
      printf("Enter item");
      scanf("%d",&item);
  q[rear]=item;
  if(front==0)
    front=1;
    }}
void pushdq()
{int temp,item;
  if (front==0)
    temp=1;
  else 
    if(front==1)
  temp=n;
  else
    temp=front-1;
    
  if (temp==rear)
    printf("Dequeue id full");
  else
    {
      printf("Enter item:");
      scanf("%d",&item);
      front=temp;
      q[front]=item;
      if (rear==0)
	rear=1;
    }
}
void eject()
{int item;
  if (front==0)
    printf("Deque is emptty");
  else{
    item=q[rear];
    if(rear==1)
      rear=n;
    else     if(rear==front)
      {	rear=0;
	front=0;}
    else rear--;
    

  printf("Deleted item:%d\n",item);
  }}
void popdq()
{int item;
  if(front==0)
    printf("Deque is empty");
  else
    {
      item=q[front];
      if(front==rear)
	{front=0;
      rear=0;
	}
      else
	front=(front%n)+1;
      
      printf("Deleted item:%d\n",item);
}
}  void display()
  {
    int t;
    if(rear==0)
       printf("Queue is empty\n");
       else {
    printf("Items:");
    for(t=front;t!=rear;t=(t%n)+1)
      printf("%d ",q[t]);
    printf("%d",q[rear]);
    printf("\n");

       }}
main()
{
  int c;
  char y; 
 printf("Enter size of queue");
  scanf("%d",&n);
  do{  printf("MENU\n1.PUSHDQ\n2.POPDQ\n3.INJECT\n4.EJECT\n5.Display");
    scanf("Enter choice");
    scanf("%d",&c);
    switch(c)
      {
      case 1:pushdq();
	break;
      case 2:popdq();
	  break;
      case 3:inject();
	break;
      case 4:eject();
	break;
      case 5:display();
	break;
      }
    printf("do you want to continue?");
    __fpurge(stdin);    
scanf("%c",&y);
  }while(y=='y');
}
