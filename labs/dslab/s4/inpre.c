#include<string.h>
#include<stdio.h>
int top=-1,j=0;
char a[100],s[100],c[100],r[100],p[100];
char push(char a)
{
  top++;
  s[top]=a;

}
void rev()
{char c;

  int i,l;
  l=strlen(a);
  for(i=0,j=l-1;i<=l;i++,j--)
    {
      r[i]= a[j];}
      r[i]='\0';
      printf("%s ",r);
}
  void rev1()
  {
    char c;
    int i,l;
    l=strlen(r);
    for(i=0,j=l-1;i<=l;i++,j--)
      p[i]=r[j];

  p[i]='\0';
  printf("%s ",p);
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
    case ')':
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
    case ')':
      return 4;
}
}
main()
{
  int l,i;
  char x;
  printf("Enter infix expression");
 gets(a);
 l=strlen(a);
 a[l]='(';
 l++;
 a[l]='\0';
 rev();
 push(')');
 for(i=0;r[i]!='\0';i++)
   {
     if(r[i]=='(')
       {
       	 x=pop();
	 while(x!=')')
	   {   output(x);
	 x=pop();
	   }
       }
	 else if((r[i]>='a'&&r[i]<='z')||(r[i]>='A'&&r[i]<='Z'))
       output(r[i]);
     else if(isp(s[top])>icp(r[i]))
       {  x=pop();
	 while(isp(x)>icp(r[i]))
	   {

	     output(x);
	     x=pop();
}
	 push(x);
	 push(r[i]);
       }
     else if(isp(s[top])<=icp(r[i]))
		 push(a[i]);
		 


}
 rev1();

 printf("postfix Expn:");
 puts(p);
}
