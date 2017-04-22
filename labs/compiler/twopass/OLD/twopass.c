#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct program
{
	char label[30];
	char opcode[30];
	char operand[30];

}s;
main()
{
  FILE *ptr,*ptr1;
  int loctr;
  char g,temp[10];
  
  ptr=fopen("code","r");
  if(ptr==NULL)
    {
      printf("Cannot open source file\n");
      exit(0);
    }
  ptr1 = fopen("intermediate","w+");
  if(ptr1==NULL)
	{
	  printf("Cannot open destination file\n");
	  exit(0);
	}

 while(1)
	  {
    	  if(feof(ptr))
	  	break;		
		fscanf(ptr,"%s %s %s",s.label,s.opcode,s.operand);
		strcpy(s.opcode,temp);
		if(strcmp(temp,'START')==0)
			loctr = 0;//loctr = atoi(s.operand);
		//else if(s.opcode=='-')
		//	loctr = 0;
		fprintf(ptr1,"%d %s %s %s\n",loctr,s.label,s.opcode,s.operand);
	
			
		//printf("%s %s %s\n",s.label,s.opcode,s.operand);
          }
fclose(ptr);
fclose(ptr1);
} 

