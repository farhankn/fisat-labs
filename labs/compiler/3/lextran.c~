#include<stdio.h>
#include<string.h>
int i=0,kw=0,id=0,state=0,j=0,k;
main()
{
	char ch;
	FILE *fp;
	char str[20];
	char num[20];
	printf("\nLex Analyser tool \n");
	fp=fopen("transinput.txt","r");
	ch=fgetc(fp);
	while(!feof(fp))
	{
		switch(state)
		{
			case 0:
			{
				if(ch=='+')
					state=1;
				else if(ch=='-')
					state=2;
				else if(ch=='*')
					state=3;
				else if(ch=='/')
					state=4;
				else if(ch=='<')
					state=5;
				else if(ch=='=')
					state=9;
				else if(ch=='>')
					state=10;
				else if(isalpha(ch)||ch=='_')
					state=13;
				else if(ch==':'||ch=='#'||ch==';'||ch=='{'||ch=='}'||ch=='('||ch==')')
					state=15;
				else if(ch>='0' &&ch<='9')
					state=16;
				else 
					{
						ch=fgetc(fp);
						state=0;
					}
				break;
			}
			case 1:
			{
				printf("\n%c	operator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 2:
			{
				printf("\n%c	operator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 3:
			{
				printf("\n%c	operator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 4:
			{
				printf("\n%c	operator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 5:
			{
				ch=fgetc(fp);
				if(ch=='=')
					state=6;
				else if(ch=='>')
					state=7;
				else 
					state=8;
				break;
			}
			case 6:
			{
				printf("\n%c LE	Relational operator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 7:
			{
				printf("\n%c NE	Relational operator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 8:
			{
				printf("\n%c LT	Relational operator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 9:
			{
				ch=fgetc(fp);
				if(ch=='=')
					state=25;
				else 
				printf("\n%c As	Assignment operator",ch);
				state=0;
				break;
			}
			case 25:
			{
				printf("\n%c EQ	Relational operator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 10:
			{
				ch=fgetc(fp);
				if(ch=='=')
					state=11;
				else
					state=12;
				break;
			}
			case 11:
			{
				printf("\n%c GE	Relational operator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 12:
			{
				printf("\n%c GT	Relational operator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 13:
			{
				str[i]=ch;
				++i;
				ch=fgetc(fp);
				if(isalpha(ch)||ch=='_')
					state=13;
				else
					state=14;
				break;
			}
			case 14:
			{
				str[i]='\0';
				i=0;kw=0;
				if(strcmp(str,"int")==0)
					printf("\n%s    Keyword",str);
				else if(strcmp(str,"else")==0)
					printf("\n%s    Keyword",str);
				else if(strcmp(str,"if")==0)
					printf("\n%s    Keyword",str);
				else if(strcmp(str,"float")==0)
					printf("\n%s    Keyword",str);
				else if(strcmp(str,"char")==0)
					printf("\n%s    Keyword",str);
				else if(strcmp(str,"include")==0)
					printf("\n%s    Keyword",str);
				else if(strcmp(str,"main")==0)
					printf("\n%s    Keyword",str);
				else if(strcmp(str,"printf")==0)
					printf("\n%s    Keyword",str);
				else if(strcmp(str,"stdio.h")==0)
					printf("\n%s    Keyword",str);
				else if(strcmp(str,"scanf")==0)
					printf("\n%s    Keyword",str);
				else
					printf("\n%s    Identifier",str);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 15:
			{
				printf("\n%c -> Punctuator",ch);
				ch=fgetc(fp);
				state=0;
				break;
			}
			case 16:
			{
				num[j]=ch;
				j++;
				ch=fgetc(fp);
				if(ch>='0' && ch<='9')
					state=16;
				else if(ch=='.')
					state=17;
				else
					state=24;
				break;
			}
			case 17:
			{
				num[j]=ch;
				j++;
				ch=fgetc(fp);
				if(ch>='0' && ch<= '9')
					state=17;
				else
					state=24;
				break;
			}
			case 24:
			{
				num[j]='\0';
				printf("\n%s ->	Number",num);
				ch=fgetc(fp);
				state=0;
				break;
			}
			default:
				printf("error");
				break;
		}
				
	}
	fclose(fp);
	printf("\n");
}		
