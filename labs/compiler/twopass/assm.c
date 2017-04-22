// Pass 1 of a two Pass Assembler
#include<stdio.h>
#include<string.h>
main()
{
int SYMTABi[20],LOCCTR=0,start=0,error=0,sym=0,len,j,i,loc;
char opcode[10],label[10],operand[10],SYMTABc[20][5],optabc1[20][5],optabc2[20][5];
FILE *f1,*f2,*f3;
f1=fopen("input","r");
f2=fopen("intermediate","w");
f3=fopen("symtab","w");
j=0;
fscanf(f1,"%s%s%s",label,opcode,operand);
if(!strcmp(opcode,"START"))
{
	LOCCTR=atoi(operand);
}
start=LOCCTR;
fprintf(f2,"0000\t%s\t%s\t%s\n",label,opcode,operand);
fscanf(f1,"%s%s%s",label,opcode,operand);
while((strcmp(opcode,"END")) && (error==0))
{
	if(!strcmp(label,"-"))
	{
		fprintf(f2,"%d\t%s\t%s\t%s\n",LOCCTR,label,opcode,operand);
		LOCCTR+=3;
	}
	else
	{
		for(i=0;i<sym;i++)
		{
			if(!strcmp(label,SYMTABc[i]))
			{
				error=1;
				printf("Duplicate symbol\n");
				break;
			}
		}
		if(i==sym)
		{
			strcpy(SYMTABc[sym],label);
			SYMTABi[sym]=LOCCTR;
			sym++;
		}
	loc=LOCCTR;
	if(!strcmp(opcode,"WORD"))
		{
			LOCCTR+=3;
		}
	else if(!strcmp(opcode,"RESW"))
		{
			LOCCTR+=3*atoi(operand);
		}
	else if(!strcmp(opcode,"RESB"))
		{
			LOCCTR+=atoi(operand);
		}
	else if(!strcmp(opcode,"BYTE"))
		{
			len=(strlen(operand)-3);
			LOCCTR+=len;
		}
	else
		LOCCTR+=3;
	fprintf(f2,"%d\t%s\t%s\t%s\n",loc,label,opcode,operand);
}
fscanf(f1,"%s%s%s",label,opcode,operand);
}
fprintf(f2,"%d\t%s\t%s\t%s\n",LOCCTR,label,opcode,operand);
len=LOCCTR-start;
for(i=0;i<sym;i++)
{
	fprintf(f3,"%s\t%d\n",SYMTABc[i],SYMTABi[i]);
}
fclose(f1);
fclose(f2);
fclose(f3);
printf("Pass 1 completed\n");
}