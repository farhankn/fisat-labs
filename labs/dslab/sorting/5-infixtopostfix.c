//Convert Infix to Postfix
#include<stdio.h>
#include<ctype.h>
#include<string.h>
void push(char);
char pop();
int isp(char);
int icp(char);
char s[20],stack[20],top;
main()
{
  int i,a;
  char x,item; 
  top=-1;
  printf("\nEnter the infix expression\n");
  gets(s);
  for(i=0;s[i]!='\0';i++)
  a=i;
  s[a+1]=')';
  // if(top<=-1)
    push('(');
  while(top>-1)
    {
      for(i=0;s[i]!='\0';i++)
	{ 
	  item=s[i];
	  if(isalnum(item)==1)
	    printf("%c",item);
	  else if(item==')')
	    {
	      x=pop();
	      while(x!='(')
		{
		  printf("%c",x);
		  x=pop();
		}
	    }
	  else if(isp(s[top])>=icp(item))
	    {
	      x=pop();
	      while(isp(x)>=icp(item))
		{
		  printf("%c",x);
		  x=pop();
		}
	      push(x);
	      push(item);
	    }
	  else if(isp(s[top])<icp(item))
	    {
	      push(item);
	    }
	  else
	    printf("\nEnter a valid expression\n");
       }
    }
  printf("\nEnd of Expression\n");
}
int isp(char item)
{
  switch(item)
    {
    case '^' :return 3;
              break;
    case '*' :
    case '/' :return 2;
              break;
    case '+' :
    case '-' :return 1;
              break;
    case '(' :return 0;
              break;
    }

}
int icp(char item)
{
  switch(item)
    {
    case '^' :return 4;
              break;
    case '*' :
    case '/' :return 2;
              break;
    case '+' :
    case '-' :return 1;
              break;
    case '(' :return 4;
              break;
    }
}
void push(char item)
{
  top=top+1;
  stack[top]=item;
}
char pop()
{
  int e;
  e=stack[top];
  top--;
  return e;
}
 
