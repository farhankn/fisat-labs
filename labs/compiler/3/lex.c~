#include<stdio.h>
#include<string.h>

main()
{
	FILE *f1,*f2;
	int state,i=0;
	char c[20];
	state = 0;
	f1=fopen("input","r");
	f2=fopen("output","w+");
	fscanf(f1,"%s ",c);
	while(!feof(f1))
	{
		switch(state)
		{
			case 0:	if(isnum(c[i])) state = 1;
				else if(c[i]=='/') state = 6;
		 		else if(c[i]=='+') state = 7;
				else if(c[i]=='-') state = 8;
				else if(c[i]=='*') state = 9;
				else if(c[i]=='<') state = 10;
				else if(c[i]=='>') state = 13;
				else if(c[i]=='!') state = 16;
				else if(isalpha(c[i])) state = 5;
				break;
			case 1:	if(c[i]== '.') state = 2;
				else state = 4;
				break;
			case 2: if(isnum(c[i])) state = 3;
				break;
			case 3: if(isnum(c[i])) fprintf(f2,"%sNumber\n",c);
				break;
			case 4: fprintf(f2,"%s Number\n",c)	
				break;
			case 5: fprintf(f2,"%s Number\n",c)	
				break;
			case 6: fprintf(f2,"%s Division Operator\n",c)	
				break;
			case 7: fprintf(f2,"%s Addition Operator\n",c)	
				break;
			case 8: fprintf(f2,"%s Subtraction Operator\n",c)	
				break;
			case 9: fprintf(f2,"%s Multiplication Operator\n",c)	
				break;




