//Program to convert Infix to Postfix
#include<stdio.h>
#include<ctype.h>
#include<string.h>
void push(char);
char pop();
int isp(char);
int icp(char);

char stack[30],s[30],top=-1,op[30],temp;
main()
{
  int a,i,z=0,l,len;
  char x,item; 
  printf("\n Enter Infix Expression: ");
  gets(s);

  for(l=0;s[l]!='\0';l++);
  l=l-1;
  len=l;
  for(i=0;i<=(len/2);i++,l--)
    {
      temp=s[i];
      s[i]=s[l];
      s[l]=temp;
     }

  for(i=0;s[i]!='\0';i++)
    a=i;
  s[a+1]='(';
  push(')');
  
  while(top>-1)
    {
      for(i=0;s[i]!='\0';i++)
	{ 
	  item=s[i];
	  if(isalnum(item))
	    {
	      op[z]=item;
	      z++;
	    }
	  else if(item=='(')
	    {
	      x=pop();
	      while(x!=')')
		{
	      	  op[z]=x;
	          z++;
		  x=pop();
		}
	    }
	  else if(isp(s[top])>icp(item))
	    {
	      x=pop();
	      while(isp(x)>icp(item))
		{
		  op[z]=x;
	          z++;
		  x=pop();
		}
	      push(x);
	      push(item);
	    }
	  else if(isp(s[top])<=icp(item))
	    {
	      push(item);
	    }
	  else
	    printf("\nInvalid Expression !\n");
	}
    }
  
  for(l=0;op[l]!='\0';l++);
  l=l-1;
  len=l;
  for(i=0;i<=(len/2);i++,l--)
    {
      temp=op[i];
      op[i]=op[l];
      op[l]=temp;
     }
  printf("\nConverted Prefix Expression: ");
  puts(op);
  printf("\n");
}
	


void push(char item)
{
  top=top+1;
  stack[top]=item;
}

char pop()
{
  int k;
  k=stack[top];
  top=top-1;
  return k;
}

int isp(char d)
{
  switch(d)
    {
    case '^' :
      {
	return 3;
	break;
      }
    case '*' :
    case '/' :
      {
	return 2;
	break;
      }
    case '+' :
    case '-' :
      {
	return 1;
	break;
      }
    case ')' :
      {
	return 0;
	break;
      }
    }

}

int icp(char d)
{
  switch(d)
    {
    case '^' :
      {
	return 4;
	break;
      }
    case '*' :
    case '/' :
      {
	return 2;
	break;
      }
    case '+' :
    case '-' :
      {
	return 1;
	break;
      }
    case ')' :
      {
	return 4;
	break;
      }
    }
  
}
