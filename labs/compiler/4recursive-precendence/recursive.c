#include<stdio.h>
#include<string.h>
char str[30],c1;
void E1();
void T1();
void F();
void T();
void E();
char read();
int i,l,f=0;
main()
{
	printf("Enter the string\n");
	gets(str);
	c1=str[0];
	E();
	if(c1!='\0' || f==1)
		printf("String rejected\n");
	else
		printf("String accepted\n");
}

char read()
{
	char c;
	i++;
	c=str[i];
	return c;
}

void E()
{
	T();
	E1();
}

void T()
{
	F();
	T1();
}

void F()
{
	if(isalpha(c1))
		c1=read();
	else if(c1=='(')
	{
		c1=read();
		E();
		if(c1==')')
			c1=read();
		else
			f=1;
	}
	else
		f=1;
}

void T1()
{
	if(c1=='*')
	{
		c1=read();
		F();
		T1();
	}
}
	
void E1()
{
	if(c1=='+')
	{
		c1=read();
		T();
		E1();
	}
}




