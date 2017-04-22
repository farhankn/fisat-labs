#include<string.h>
#include<stdio.h>
int top=-1,j=0;
char a[100],s[100],c[100],r[100];
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
  int l,i,k;
  char x,b[100];
  printf("Enter infix expression");
 gets(a);
 l=strlen(a);

 for(i=l-1,k=0;i>=0;i--,k++)
   b[k]=a[i];
 for(i=0;i<l;i++)
   a[i]=b[i];
 a[i]='(';
 i++;
 a[i]='\0';
 
 push(')');
 for(i=0;a[i]!='\0';i++)
   {
     if(a[i]=='(')
       {
       	 x=pop();
	 while(x!=')')
	   {   output(x);
	 x=pop();
	   }
       }
	 else if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
       output(a[i]);
     else if(isp(s[top])>icp(a[i]))
       {  x=pop();
	 while(isp(x)>icp(a[i]))
	   {

	     output(x);
	     x=pop();
}
	 push(x);
	 push(a[i]);
       }
     else if(isp(s[top])<=icp(a[i]))
		 push(a[i]);
		 


}
  
 for(i=j-1,k=0;i>=0;i--,k++)
   r[k]=c[i];
    r[k]='\0';
 printf("Prefix Expn:");
 puts(r);
}
