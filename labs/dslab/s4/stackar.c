#include<stdio.h>
int s[100],top=-1,n;
void push(int item)
{
  if(top>=n-1)
    printf("Stack is full");
  else
    {  top++;
      s[top]=item;
    }
}
void pop()
{int a;
  if(top==-1)
    { printf("Stack is empty");
      
	  
    }
  else
    {
      a=s[top];
      top--;
      printf("Deleted item:%d",a);   
}
}
void display()
{
  int i,t;
  t=top;
  if(t<0)
    {
      printf("Stack is empty");
}
  else 
    { for(i=top;i>-1;i--)
	printf("%d ",s[i]);
      
    }
}
main()
{int c,item;
  char y;
  printf("Enter size");
  scanf("%d",&n);
do
  {  printf("MENU\n1.Push\n2.POP\n3.DISPLAY");
  scanf("%d",&c);
  switch(c)
  {
  case 1:
    printf("Enter element");
    scanf("%d",&item);
    push(item);
    break;
  case 2:
    pop();
    

    break;

  case 3:
    printf("Elements of stack:");
    display();
    break;

}
  printf("\nDo you want to continue?");
  __fpurge(stdin);
  
  scanf("%c",&y);
  }while(y=='y');

}
