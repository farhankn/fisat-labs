#include<stdio.h>
#include<string.h>

void main()
{
	int locctr=0,f=0,start=0;
	char c,label[10],opcode[10],operand[10],symname[10];
	FILE *f1,*f2,*f3,*f4;
	f1=fopen("input.txt","r");
	f2=fopen("intermediate.txt","w");
	f3=fopen("symbol.txt","r+");
	f4=fopen("size.txt","w");
	while((c=fgetc(f1))!=EOF)
	{
		fscanf(f1," %s\t %s\t %s",label,opcode,operand);
		if(!strcmp(opcode,"START"))
		{
			start=atoi(operand);
			locctr=atoi(operand);
			fprintf(f2," %d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
		}
		else
			locctr=0;
		while(strcmp(opcode,"END"))
		{
			fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
			fprintf(f2," %d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
			if(label[0]!='#')
			{
				if(strcmp(label,"-"))
				{
					rewind(f3);
					while(!feof(f3))
					{
						fscanf(f3,"%s",symname);
						if(!strcmp(symname,label))
						{
							f=1;
							printf("\nDuplicate label\n");
							break;
						}
					}
					if(f==0)
						fprintf(f3,"%s\t%d\n",label,locctr);
				}
				if(!strcmp(opcode,"WORD"))
					locctr+=3;
				else if(!strcmp(opcode,"RESW"))
					locctr=locctr+(3*atoi(operand));
				else if(!strcmp(opcode,"RESB"))
					locctr=locctr+atoi(operand);
				else if(!strcmp(opcode,"BYTE"))
					locctr=locctr+strlen(operand)-3;
				else
					locctr+=3;
			}
		}
		printf("\nThe length of the program : %d\n",locctr-start-3);
		fprintf(f4,"%d",locctr-start-3);
		break;
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
}
