#include<string.h>
#include<stdio.h>
int top=-1,j=0;
char a[100],s[100],c[100];
char push(char a)
{
  top++;
  s[top]=a;

}
char pop()
{
  char x;
  if(top==-1)
    printf("Stack is empty");
  else
    x=s[top];
  top--;
  return x;

}
void output(char a)
{
  c[j]=a;
  j++;
}
int isp(char a)
{
  switch (a)
    {
    case '^':
      return 3;
      break;
    case '/':
    case'*':
      return 2;
      break;
    case '+':
    case '-':
      return 1;
    case '(':
    return 0;
    
}

}

int icp(char a)
{
  switch(a)
    {
    case '^':
return 4;
break;
    case '/':
    case '*':
      return 2;
      break;
    case '+':
    case '-':
      return 1;
      break;
    case '(':
      return 4;
}
}
int cal(int a,int b,char c)
{
  int y;
  if(c=='+')
    y=a+b;
  else if(c=='-')
    y=a-b;
  else if(c=='/')
    y=a/b;
  else if(c=='*')
    y=a*b;

  return y;
}
main()
{
  int l,i,k=0,p,q,t;
  char x,r,m;
int value,v;
  printf("Enter infix expression");
 gets(a);
 l=strlen(a);
 a[l]=')';
 l++;
 a[l]='\0';

 push('(');
 for(i=0;a[i]!='\0';i++)
   {
     if(a[i]==')')
       {
       	 x=pop();
	 while(x!='(')
	   {   output(x);
	 x=pop();
	   }
       }
	 else if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
       output(a[i]);
     else if(isp(s[top])>=icp(a[i]))
       {  x=pop();
	 while(isp(x)>=icp(a[i]))
	   {

	     output(x);
	     x=pop();
}
	 push(x);
	 push(a[i]);
       }
     else if(isp(s[top])<icp(a[i]))
		 push(a[i]);
		 


}

 printf("postfix Expn:");
 puts(c);
 c[j]='#';
 while(c[k]!='#')
   {m=c[k];
     if((c[k]>='a'&&c[k]<='z')||(c[k]>='A'&&c[k]<='Z'))
      
       {
	 printf("Enter value for  %c",m);
	 scanf("%d",&v);
	 push(v);
       }     else if(m=='+'||m=='-'||m=='/'||m=='*')
       {
	 r=m;
	 p=pop();
	 q=pop();
	 t=cal(p,q,r);
	 push(t);
	 
}
     k++;
}
     value=pop();
     printf("The value of expression is:%d\n",value);

}
