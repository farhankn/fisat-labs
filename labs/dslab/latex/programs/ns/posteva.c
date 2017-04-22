//Program to evaluate a postfix expression.
#include<stdio.h>
#include<math.h>
int top=-1,top2=-1,stack2[50];
char stack[50],post[50],infix[50];
int ops(int x,int y,char op);
void push(char ele);
void push2(int ele);
char pop();
int pop2();
int isp(char ch);
int icp(char c);
void postfix();
void main()
{
  int i=0,len,value,num,x,y,t;
  char op,item;
  printf("Enter a infix expression:");
  scanf("%s",infix);
  postfix();
  while(post[i]!='\0')
    i++;
  post[i]='#';
  post[++i]='\0';
  len=i;
  i=0;
  while(post[i]!='\0')
    {
      item=post[i++];
      while(item!='#')
	{
	  if(isalnum(item))
	    {
	      printf("Enter value of %c:",item);
	      scanf("%d",&num);
	      push2(num);
	    }
	  else
	    {
	      op=item;
	      y=pop2();
	      x=pop2();
	      t=ops(x,y,op);
	      push2(t);
	    }
	  item=post[i++];
	 
	}
    }
 value=pop2();
 printf("Value is %d.\n",value);
}

//Function to do operation.
int ops(int x,int y,char op)
{
  int c;
  switch(op)
    {
    case '^':c=pow(x,y);
      break;
    case '*':c=x*y;
      break;
    case '/':c=x/y;;
      break;
    case '+':c=x+y;
      break;
    case '-':c=x-y;
      break;
      
    }
  
  return c;
}


//Function to convert infix to post fix.
void postfix()
{
  int i=0,j=0,k=0;
  char item,x;
  push('(');
  while(infix[k]!='\0')  //length
    k++;
  infix[k]=')';
  infix[k+1]='\0';
  while(infix[i]!='\0')
    {
      while(top>-1)
	{
	  item=infix[i++];
	  if(isalnum(item))
	    {
	      post[j]=item;
	      j++;
	    }
	  else if(item==')')
	    {
	      x=pop();
	      while(x!='(')
		{
		  post[j]=x;
		  j++;
		  x=pop();
		}
	    }
	  else if(isp(stack[top])>=icp(item))
	    {
	      x=pop();
	      while(isp(x)>=icp(item))
		{
		  post[j]=x;
		  j++;
		  x=pop();
		}
	      push(x);
	      push(item);
	    }
	  else if(isp(stack[top])<icp(item))
	      {
		push(item);
	      }
	  else
	    printf("Invalid expression.\n");
	}
    }
  post[j]='\0';
printf("The postfix expression is as follows:\n");
  __fpurge(stdin);
  puts(post);
  
}



//Function to push character elements.
void push(char ele)
{
  if(top>50)
    printf("Stack overflow!!\n");
  else
    {
      
      top++;
      stack[top]=ele;
      
    }
}


//Function to push integer elements.
void push2(int ele)
{
  if(top2>50)
    printf("Stack overflow!!\n");
  else
    {
      
      top2++;
      stack2[top2]=ele;
      
    }
}
//Function to pop character elements
char pop()
{
  char ele;
  if(top<-1)
    printf("Stack underflow!!\n");
  else
    {
      ele=stack[top];
      top--;
      return ele;
    }
}

//Function to pop integer elements
int pop2()
{
  int ele;
  if(top2<-1)
    printf("Stack underflow!!\n");
  else
    {
      ele=stack2[top2];
      top2--;
      return ele;
    }
}



//ISP
int isp(char ch)
{
  switch(ch)
    {
    case '^':return 3;
      break;
    case '*':return 2;
      break;
    case '/':return 2;
      break;
    case '+':return 1;
      break;
    case '-':return 1;
      break;
    case ')':return 0;
      break;	
    }
}

//ICP
int icp(char c)
{
  switch(c)
    {
    case '^':return 4;
      break;
    case '*':return 2;
      break;
    case '/':return 2;
      break;
    case '+':return 1;
      break;
    case '-':return 1;
      break;
    case '(':return 4;
      break;	
    }
}
