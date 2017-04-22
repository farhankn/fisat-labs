#include<stdio.h>
#include<string.h>

void main()
{
	int locctr=0,fo=0,fs=0,fi=0,start=0,size,oploc,symval;
	char c,label[10],opcode[10],operand[10],symname[10],opname[10];
	FILE *f1,*f2,*f3,*f4,*f5;
	f1=fopen("code.txt","w+");
	f2=fopen("intermediate.txt","r");
	f3=fopen("symbol.txt","r+");
	f4=fopen("size.txt","r+");
	f5=fopen("optab.txt","r+");
	while(!feof(f2))
	{
		fscanf(f2," %d\t%s\t%s\t%s\n",&locctr,label,opcode,operand);
		fscanf(f4,"%d",&size);
		if(!strcmp(opcode,"START"))
		{
			start=atoi(operand);
			fscanf(f2," %d\t%s\t%s\t%s\n",&locctr,label,opcode,operand);
		}
		fprintf(f1,"H^%d^%d^\n",start,size);
		fprintf(f1,"T^%d^%d",start,size);
		while(strcmp(opcode,"END"))
		{
			
			if(label[0]!='#')
			{
				if(!strcmp(opcode,"RESB"))
					fi=1;
				if(!strcmp(opcode,"RESW"))
					fi=1;
				if(fi!=1)
				{
					fprintf(f1,"^");
				}
				else 
					fi=0;
				rewind(f5);
				while(!feof(f5))
				{
					fscanf(f5,"%s\t%d",opname,&oploc);
					
					if(!strcmp(opname,opcode))
					{
						fo=1;
						break;
					}
				}
				if(fo==1)
				{
					fprintf(f1,"%d",oploc);
					fo=0;
					rewind(f3);
					while(!feof(f3))
					{
						fscanf(f3,"%s\t%d",symname,&symval);
						if(!strcmp(symname,operand))
						{
							fs=1;
							break;
						}
					}
					if(fs==1)
					{
						fs=0;
						fprintf(f1,"%d",symval);
					}					
				}
				if(!strcmp(opcode,"BYTE") || !strcmp(opcode,"WORD"))
				{
					if(!strcmp(opcode,"BYTE"))
						fprintf(f1,"0000%d",operand[2]);
					else
						fprintf(f1,"00000%d",atoi(operand));
				}
			}
			fscanf(f2," %d\t%s\t%s\t%s\n",&locctr,label,opcode,operand);
		}
	}		
	fprintf(f1,"\nE^%d^\n",start);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	fclose(f5);
}
		
