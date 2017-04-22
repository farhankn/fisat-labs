#include<stdio.h>
#include<string.h>

int main()
{
  FILE *f1,*f2;
  char name[10][20],value[10][20],read1[20],r1[20],r2[30];
  int op=0,i,j,k;
  
  f1=fopen("2_input","r");
  f2=fopen("2_output","w");
  
  while(fscanf(f1,"%s",read1)!=EOF)
    {
      if(!strcmp(read1,"#define"))
	{
	  fscanf(f1,"%s%s",r1,r2);
	  if(r2[0]=='{')
	     r2[0]=' ';
	  if(r2[strlen(r2)-1]=='}')
	     r2[strlen(r2)-1]=' ';
	  strcpy(name[op],r1);
	  strcpy(value[op],r2);
	  op++;
	}
    }
//Printing the #define Table
printf("\nMacros Found \n");
 for(i=0;i<op;i++)
	printf("%s %s\n",name[i],value[i]);
printf("\n");
  
  rewind(f1);
  
  while(fscanf(f1,"%s",read1)!=EOF)
    {
      if(!strcmp(read1,"#define"))
	{
	  fscanf(f1,"%s%s",r1,r2);
	}
      else
	{
	  for(i=0;i<op;i++)
	    {
	      if(!strcmp(read1,name[i]))
		break;
	    }
	  if(i==op)
	    {
	      if(!strncmp(read1,"#include",8))
		continue;
	      else if(!strcmp(read1,";"))
		fprintf(f2,"%s\n",read1);
	      else if(!strcmp(read1,"{")||!strcmp(read1,"}"))
		fprintf(f2,"\n%s\n",read1);
	      else if(!strcmp(read1,"void")||!strcmp(read1,"int")||!strcmp(read1,"float")||!strcmp(read1,"double"))
		fprintf(f2,"\n%s ",read1);
	      else
		fprintf(f2,"%s ",read1);
	    }
	  else
	    {
	      fprintf(f2,"%s ",value[i]);
	    }

	}
    }
  
  fclose(f1);
  fclose(f2);
  printf("\nMacro expansion successfully completed.written to 2_output.\n");
  return(0);
}


