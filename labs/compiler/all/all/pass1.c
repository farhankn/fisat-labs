#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flag=0;
main()
{
	char label[50],opcode[50],operand[40];
	FILE *f1,*f2,*f3,*f4;
	char symbol[10][10];
	int i=0,sym=0;
	int locctr,start,temp,error=0,length;
	f1=fopen("input.txt","r");
	f2=fopen("inter.txt","w");
	f3=fopen("symbol.txt","w");
	fscanf(f1,"%s%s%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		start=atoi(operand);
		locctr=start;
		fprintf(f2,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
		strcpy(symbol[sym],label);
		fprintf(f3,"%d\t%s\n",locctr,label);
		fscanf(f1,"%s%s%s",label,opcode,operand);
	}
	else
		locctr=0;
	while(strcmp(opcode,"END")!=0)
	{
		flag=0;
		fprintf(f2,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
		if(strcmp(opcode,"WORD")==0)
			locctr=locctr+3;
		else if(strcmp(opcode,"RESW")==0)
		{
			temp=atoi(operand);
			locctr=locctr+(3*temp);
		}
		else if(strcmp(opcode,"RESB")==0)
		{
			temp=atoi(operand);
			locctr=locctr+temp;
		}
		else if(strcmp(opcode,"BYTE")==0)
		{
			temp=strlen(operand)-3;
			locctr=locctr+temp;
		}
		else
			locctr=locctr+3;
		
		if(strcmp(label,"-")!=0)
		{
			for(i=0;i<sym;i++)
			{
				if(strcmp(symbol[i],label)==0)
				{printf("Duplicate symbol\n");
				flag=1;}
			}
			if(flag==0)
			{
				fprintf(f3,"%d\t%s\n",locctr,label);
			}			
			strcpy(symbol[sym++],label);
		}
		fscanf(f1,"%s%s%s",label,opcode,operand);
	}
	fprintf(f2,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
	length=locctr-start;
	printf("lenght of the program is  %d\n",length);
	f4=fopen("pgmlength.txt","w");
	fprintf(f4,"%d",length);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	
}
		
