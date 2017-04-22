#include<stdio.h>
#include<math.h>
#include<string.h>

char S[50],A1[50],A[50],B[50],o;
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
  scanf("%s",A1);

  for(i=0;A1[i]!='\0';i++)
    {
      if(A1[i]=='=')
	break;	
    }

  if(A1[i]!='=')
    strcpy(A,A1);
  else
    {
      flag=1;
      for(j=i+1;A1[j]!='\0';j++,k++)
	A[k]=A1[j];
      A[k]='\0';
    }
  
  for(i=0;A[i]!='\0';i++);
  A[i]=')';
  A[i+1]='\0';
  
  push('(');
  i=0,j=0;

  while(top>-1)
    {
      x=pop();
      item=A[i];   
      
      if(isalpha(item))
	{ 
	  push(x);
	  B[j]=item;
	  i++,j++;
	}
      else if(item==')')
	while(x!='(')
	  {
	    B[j]=x;
	    i++,j++;
	    x=pop();
	  } 
      else if((item=='+')||(item=='-')||(item=='*')||(item=='/')||(item=='^')||(item=='('))
	if(ISP(x)>=ICP(item))
	  {
	    while(ISP(x)>=ICP(item))
	      {
		B[j]=x;
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
  B[j]='\0';
  printf("\n The Postfix expression is :- ");
  if(flag==1)
    printf("%c%s=",A1[0],B);
  else
    printf("%s",B);

  top=-1;  
  n=0,i=0;
  
  for(i=0;B[i]!='\0';i++);
  
  if(flag==1)
    {
      push(A1[0]);
      B[i]='=';
      B[i+1]='#';
      B[i+2]='\0';
    }
  else
    {
      B[i]='#';
      B[i+1]='\0';
    }

  i=0;
  
  while(B[i]!='#')
    {
      if(isalpha(B[i]))
	{
	  push(B[i]);
	  i++;
	}
      if((B[i]=='+')||(B[i]=='-')||(B[i]=='*')||(B[i]=='/')||(B[i]=='^')||B[i]=='=')
	{
	  if(B[i]=='=')
	    {
	      x=pop();
	      y=pop();
	      INTER[num].operator=B[i];
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
	      INTER[num].operator=B[i];
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

int ISP(char a)
{ 
  if(a=='^')
    return(3);
  if((a=='*')||(a=='/'))
    return(2);
  if((a=='+')||(a=='-'))
    return(1);
  if(a=='(')
    return(0);
}

int ICP(char a)
{
  if(a=='^')
    return(4);
  if((a=='*')||(a=='/'))
    return(2);
  if((a=='+')||(a=='-'))
    return(1);
  if(a=='(')
    return(4);
}

void push(char a)
{
  top++;
  S[top]=a;      
}

char pop(void)
{
  char a;
  a=S[top];
  top--;
  return(a);    
}
