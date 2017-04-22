#include<stdio.h>
#include<math.h>
#include<string.h>

char S[50],expr[50],expr1[50],post[50],o;
int top,max,n,num=0;
char item,x,y,j,res='0';

void push(char);
char pop(void);
int ISP(char);
int ICP(char);
int OP(char,int,int);

struct inter
{
  char operator, arg1,arg2,result;
}INTER[10];

void main()
{ 
  int i,j,k=0,flag=0;
  top=-1,max=50;
  
  printf("\n Enter the Infix expression : ");
  scanf("%s",expr);

  for(i=0;expr[i]!='\0';i++)
    {
      if(expr[i]=='=')
	break;	
    }

  if(expr[i]!='=')
    strcpy(expr1,expr);
  else
    {
      flag=1;
      for(j=i+1;expr[j]!='\0';j++,k++)
	expr1[k]=expr[j];
      expr1[k]='\0';
    }
  
  for(i=0;expr1[i]!='\0';i++);
  expr1[i]=')';
  expr1[i+1]='\0';
  
  push('(');
  i=0,j=0;

  while(top>-1)
    {
      x=pop();
      item=expr1[i];   
      
      if(isalpha(item))
	{ 
	  push(x);
	  post[j]=item;
	  i++,j++;
	}
      else if(item==')')
	while(x!='(')
	  {
	    post[j]=x;
	    i++,j++;
	    x=pop();
	  } 
      else if((item=='+')||(item=='-')||(item=='*')||(item=='/')||(item=='^')||(item=='('))
	if(ISP(x)>=ICP(item))
	  {
	    while(ISP(x)>=ICP(item))
	      {
		post[j]=x;
		j++;
		x=pop();
	      }
	    push(x);
	    push(item);
	    i++;
	  }
	else
	  {
	    push(x);
	    push(item);
	    i++;
	  }	 
    }
  post[j]='\0';
  printf("\n The Postfix expression is :- ");
  if(flag==1)
    printf("%c%s=",expr[0],post);
  else
    printf("%s",post);

  top=-1;  
  n=0,i=0;
  
  for(i=0;post[i]!='\0';i++);
  
  if(flag==1)
    {
      push(expr[0]);
      post[i]='=';
      post[i+1]='#';
      post[i+2]='\0';
    }
  else
    {
      post[i]='#';
      post[i+1]='\0';
    }

  i=0;
  
  while(post[i]!='#')
    {
      if(isalpha(post[i]))
	{
	  push(post[i]);
	  i++;
	}
      if((post[i]=='+')||(post[i]=='-')||(post[i]=='*')||(post[i]=='/')||(post[i]=='^')||post[i]=='=')
	{
	  if(post[i]=='=')
	    {
	      x=pop();
	      y=pop();
	      INTER[num].operator=post[i];
	      INTER[num].arg1=x;
	      INTER[num].arg2=' ';
	      INTER[num].result=y;
	      num++;
	      i++;
	    }
	  else
	    {
	      x=pop();			 
	      y=pop();
	      INTER[num].operator=post[i];
	      INTER[num].arg1=y;
	      INTER[num].arg2=x;
	      INTER[num].result=res;
	      res++;
	      push(INTER[num].result);
	      num++;
	      i++;
	    }
	}
    }
  

  printf("\n Output :\n Op\tArg1\tArg2\tResult\n --\t----\t----\t------\n");
  for(i=0;i<num;i++)
    {
      printf(" %c",INTER[i].operator);
      if(isdigit(INTER[i].arg1))
	printf("\tt%c",INTER[i].arg1);
      else
	printf("\t%c",INTER[i].arg1);
      if(isdigit(INTER[i].arg2))
	printf("\tt%c",INTER[i].arg2);
      else
	printf("\t%c",INTER[i].arg2);
      if(isdigit(INTER[i].result))
	printf("\tt%c\n",INTER[i].result);
      else
	printf("\t%c\n",INTER[i].result);
    } 
  printf("\n"); 
}

int ISP(char expr1)
{ 
  if(expr1=='^')
    return(3);
  if((expr1=='*')||(expr1=='/'))
    return(2);
  if((expr1=='+')||(expr1=='-'))
    return(1);
  if(expr1=='(')
    return(0);
}

int ICP(char expr1)
{
  if(expr1=='^')
    return(4);
  if((expr1=='*')||(expr1=='/'))
    return(2);
  if((expr1=='+')||(expr1=='-'))
    return(1);
  if(expr1=='(')
    return(4);
}

void push(char expr1)
{
  top++;
  S[top]=expr1;      
}

char pop(void)
{
  char expr1;
  expr1=S[top];
  top--;
  return(expr1);    
}
