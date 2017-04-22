#include<stdio.h>
void main()
{
	FILE *fi,*fo,*fop,*fk;
	int flag = 0,i = 1,flag1 = 0;
	char c,d,t,a[15],ch[20],file[20];
	fi = fopen("lexinput.c","r");
	fo = fopen("lexout.txt","w");
	fop = fopen("oper.txt","r");
	fk = fopen("key.txt","r");
	c = getc(fi);
	while(!feof(fi))
	{
		if(isalpha(c)||isdigit(c)||(c=='['||c==']'|| c=='.' ==1))
			fputc(c,fo);
		else if(c=='>'||c=='<' == 1)
		{
			d = getc(fi);
			if(d == '=')
				fprintf(fo,"\t%c%c\t",c,d);
			else 
			{
				fseek(fi,-1,SEEK_CUR);
				fprintf(fo,"\t%c\t",c);
			}
		} 
		
		else
		{
			if(c=='\n')
				fprintf(fo,"\t$\t");
			else
				fprintf(fo,"\t%c\t",c);
		}
		c = getc(fi);
	}
	fclose(fi);
	fclose(fo);
	fi = fopen("lexout.txt","r");
	//printf("\t\tLEXICAL ANALYSIS \n");
	fscanf(fi,"%s",a);
	printf("\nline : %d\n",i++);
	while(!feof(fi))
	{
		if((strcmp(a,"$")==0))
		{
			printf("\nline : %d\n",i++);
			fscanf(fi,"%s",a);
		}
		fscanf(fop,"%s",ch);
		while(!feof(fop))
		{
			if(strcmp(ch,a)==0)
			{
				fscanf(fop,"%s",ch);
				printf("\t%s\t--->\t%s\n",a,ch);
				flag=1;
			}
			fscanf(fop,"%s",ch);
		}
		rewind(fop);
		fscanf(fk,"%s",ch);
		while(!feof(fk))
		{
			if(strcmp(ch,a)==0)
			{
				fscanf(fk,"%s",ch);
				printf("\t%s\t--->\tKeyword\n",a);
				flag=1;
			}
			fscanf(fk,"%s",ch);
		}
		rewind(fk);
		if(flag==0)
		{
			if(isdigit(a[0]))
			{
				for(i=0;a[i]!='\0';i++)
				{
					if(a[i]=='.')
						flag1 = 1;
				}
				if(flag1==1)
				{
					printf("\t%s\t--->\tFloating Point Number\n",a);
					flag1 = 0;
				}
				else
					printf("\t%s\t--->\tNumber\n",a);
			}
			else
				printf("\t%s\t--->\tIdentifier\n",a);
		
		}
		flag=0;
		fscanf(fi,"%s",a);
	}
	fclose(fi);
	fclose(fk);
	fclose(fop);
}
