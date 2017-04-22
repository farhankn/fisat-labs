#include<stdio.h>
int q[100];
 int front=0,rear=0,n;
void enque()
{int item;
  if (rear==n)
    printf("Queue if full");
  else
    {  rear++;
      printf("Enter item");
      scanf("%d",&item);
  q[rear]=item;
  if(front==0)
    front=1;
    }}
void deque()
{int item;
  if(front==0)
    printf("Queue is empty");
  else
    {
      item=q[front];
      if(front==rear)
	{front=0;
      rear=0;
	}
      else
	front++;
      
      printf("Deleted item:%d\n",item);
}
}  void display()
  {
    int t;
    if(rear==0)
       printf("Queue is empty\n");
       else {
    printf("Items:");
    for(t=front;t<=rear;t++)
      printf("%d ",q[t]);
    printf("\n");

       }}
main()
{
  int c;
  char y; 
 printf("Enter size of queue");
  scanf("%d",&n);
  do{  printf("MENU\n1.Insertion\n2.Deletion\n3.Display");
    scanf("Enter choice");
    scanf("%d",&c);
    switch(c)
      {
      case 1:enque();
	break;
      case 2:deque();
	break;
      case 3:display();
	break;
      }
    printf("do you want to continue?");
    __fpurge(stdin);    
scanf("%c",&y);
  }while(y=='y');
}
