#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int f1=0,i=0;
	char pre[20],name[20],val[20],a[20],b[20];
	FILE *fp1,*fp2,*fp3;
	fp1=fopen("inmacro.txt","r");
	fp2=fopen("intermacro.txt","w");
	fp3=fopen("opmacro.txt","w");
	fscanf(fp1,"%s",pre);
	while(strcmp(pre,"int")!=0)
	{
		if(strcmp(pre,"#define")==0)
		{	
			fscanf(fp1,"%s%s",name,val);
			fprintf(fp2,"%s\t%s\n",name,val);
		}
		fscanf(fp1,"%s",pre);
	}
	fscanf(fp1,"%s",name);
	fprintf(fp3," %s %s\n",pre,name);
	fclose(fp2);
	while(fscanf(fp1,"%s",val)!=EOF)
	{
		puts(val);
		f1=0;
		fp2=fopen("intermacro.txt","r");
		while(fscanf(fp2,"%s\t%s",a,b)!=EOF)
		{
			if(strcmp(val,a)==0)
			{
				f1=1;
				break;
			}
		}
		if(f1==1)
		{
			if(b[0]=='{')
			{	fprintf(fp3," ");
				for(i=1;i<strlen(b)-1;i++)
					fprintf(fp3,"%c",b[i]);
			}
			
			else
			{
				fprintf(fp3," %s",b);
			}
		}
		else
		{
			if(strcmp(val,";")==0 || strcmp(val,"{")==0 || strcmp(val,"}")==0)
			{
				fprintf(fp3," %s\n",val);
			}
			else
				
				fprintf(fp3," %s",val);
		}
		fclose(fp2);
	}
	fclose(fp1);
	fclose(fp3);
}	
