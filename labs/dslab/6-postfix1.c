//Evaluation of Postfix expression

#include<stdio.h>
#include<math.h>
void push(char b);
void push1(int n);
char pop();
int pop1();
int icp(char p);
int isp(char q);
char a[100],a1[100],out[20],e[20];
int top=-1,max=20;
main()
{
  char item,op,x,y;
  int t,value,num;
  int i=0,c=0,j,p,q;
  printf("\nEnter an infix expression\t");
  scanf("%s",e);
  for(j=0;e[j]!='\0';j++);
  e[j]=')';
  push('(');
  while(top>-1)
    {
      item=e[i++];
      if(item=='\0')
	{
	  break;
	}
      else if(isalnum(item))
	{
	  out[c]=item;
	  c++;
	}
      else if(item==')')
	{
	  x=pop();
	  while(x!='(')
	    {
	      out[c]=x;
	      c++;
	      x=pop();
	    }
	}
      else if(isp(a[top])>=icp(item))
	{
	  x=pop();
	  while(isp(x)>=icp(item))
	    {
	      out[c]=x;
	      c++;
	      x=pop();
	    }
	  push(x);
	  push(item);
	}
      else if(isp(a[top])<icp(item))
	{
	  push(item);
	}
      else
	printf("invalid expression");
    }
  top=-1;
  for(j=0;out[j]!='\0';j++);
  out[j]='#';
  out[j+1]='\0';
  i=0;
  while(item!='#')
    {
      item=out[i];
      if(isalnum(item))
	{
	  printf("Enter the value of %c\t",item);
	  scanf("%d",&num);
	  push1(num);
	}
      else
	{
	  op=item;
	  p=pop1();
	  q=pop1();
	  switch(op)
	    {
	    case '+':
	      t=q+p;
	      break;
	    case '-':
	      t=q-p;
	      break;
	    case '^':
	      t=pow(q,p);
	      break;
	    case '*':
	      t=q*p;
	      break;
	    case '/':
	      t=q/p;
	      break;
	    }
	  push1(t);
	}
      i++;
    }
  value=pop1();
  printf("\nThe value is\t");
  printf("%d\n",value);
}

void push(char b)
{
  if(top>=(max-1))
    {
      printf("stack overflow\n");
    }
  else
    {
      top=top+1;
      a[top]=b;
    }
}

void push1(int n)
{
  if(top>=(max-1))
    {
      printf("stack overflow\n");
    }
  else
    {
      top=top+1;
      a1[top]=n;
    }
}

char pop()
{
  int d;
  if(top<0)
    {
      printf("the stack is empty\n");
    }
  else
    {
      d=a[top];
      top=top-1;
    }
  return d;
}

int pop1()
{
  int d;
  if(top>=0)
    {
      d=a1[top];
      top=top-1;
    }
  return d;
}

int isp(char q)
{
  if(q=='^')
    return 3;
  else if(q=='*')
    return 2;
  else if(q=='/')
    return 2;
  else if(q=='+')
    return 1;
  else if(q=='-')
    return 1;
  else if(q=='(')
    return 0;
}

int icp(char p)
{
  if(p=='^')
    return 4;
  else if(p=='*')
    return 2;
  else if(p=='/')
    return 2;
  else if(p=='+')
    return 1;
  else if(p=='-')
    return 1;
  else if(p=='(')
    return 4;	  
}
