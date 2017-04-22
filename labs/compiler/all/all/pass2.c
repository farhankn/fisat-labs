#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int stradd,temp,addr,pgmln,n,i;
char lab[10],oper[10],opc[10],lab1[10],lab2[10],num[20],byte[10],con[10];
FILE *f1,*f2,*f3,*f4,*f5;
main()
{
	f1=fopen("inter.txt","r");
	f2=fopen("symbol.txt","r");
	f3=fopen("optab.txt","r");
	f4=fopen("pgmlength.txt","r");
	f5=fopen("output.txt","w");
	fscanf(f4,"%d",&pgmln);
	fscanf(f1,"%d\t%s\t%s\t%s",&temp,lab,opc,oper);
	if(strcmp(opc,"START")==0)
		{
			stradd=temp;
			fprintf(f5,"\nH^00%d^00%d\n",stradd,pgmln);
			fprintf(f5,"T^00%d^00%d",stradd,pgmln);	
		}
	while(fscanf(f1,"%d\t%s\t%s\t%s",&temp,lab,opc,oper)!=EOF)
	{
				if(strcmp(opc,"RESW")==0||strcmp(opc,"RESB")==0)
					continue;
		 		else if(strcmp(opc,"END")==0)
				{fprintf(f5,"\nE^00%d\n",stradd);}
			
				if(strcmp(opc,"WORD")==0)
				{
				fprintf(f5,"^00000%s",oper);
				}
				else if(strcmp(opc,"BYTE")==0)
				{
				strcpy(con,oper);
				fprintf(f5,"^");
				for(i=2;i<strlen(c)-1;i++)
				
					fprintf(f5,"%d",con[i]);		
				}
				
				
				else{
				while(!feof(f3))
				{
				fscanf(f3,"%s\t%d",lab1,&n);
				if(strcmp(opc,lab1)==0)
				{
					while(!feof(f2))
					{
						fscanf(f2,"%d\t%s",&addr,lab2);
						if(strcmp(oper,lab2)==0)
						{
							fprintf(f5,"^%d%d",addr,n);
							break;
						}
					}
					fclose(f2);
					f2= fopen("symbol.txt","r");
					break;
				}
				}
			fclose(f3);
			f3=fopen("optab.txt","r");
			}
			
		
	}
	
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	fclose(f5);
}
			
		
