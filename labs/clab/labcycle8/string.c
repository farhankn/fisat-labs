//Menu driven program for Palindrome checking,String concatenation and to Replace a Substring.

#include<stdio.h>
void palindrome(char str[25]);
void concat(char str[25]);
void replace(char str[25]);
int search(char src[25],char str[25]);
char str[25];
main()
{
  int op;
  char ch;
  printf("Enter a string:");
  
  gets(str);
  do
    {
      printf("MENU\n=====\n1.Palindrome checking\n2.String concatenation\n3.Replace a substring\n4.Exit");
      printf("\nEnter your choice:");
      scanf("%d",&op); 
      switch(op)
	{
	case 1:palindrome(str);
	  break;
	case 2:concat(str);
	  break;
	case 3:replace(str);
	  break;
	case 4:printf("Exiting program!!");
	  break;
	default:printf("Invalid choice!!!");
	}
      printf("Do you want to continue(y/n)??");
      scanf("%s",&ch);
    }while(ch=='y');
}

//Function to check whether a string is palindrome.
void palindrome(char str[25])
{
  char b[25];
  int i=0,j,len,flag=0;
  while(str[i]!='\0')
    i++;
  len=i;
  j=len-1;
  i=0;
  while(str[i]!='\0')
    {
      b[i]=str[j];
      i++;
      j--;
    }
  b[len]='\0';
  for(i=0;i<len;i++)
    {
      if(str[i]!=b[i])
	{
	  printf("Given string is not a palindrome.\n");
	  flag++;
	  break;
	}
    }
  if(flag==0)
    printf("Given string is a palindrome.\n");
}

//Function to Concatenate two strings.

void concat(char str[25])
{
  char b[25];
  int i=0,j,len;
  printf("Enter the second string:");
  scanf("%s",b);
  while(str[i]!='\0')
    i++;
  len=i;
  for(j=len,i=0;b[i]!='\0';j++,i++)
    str[j]=b[i];
  str[j]='\0';
  printf("Concatenated string:");
  puts(str);
}

//Function to Replace a substring.
void replace(char str[25])
{
  char sub[25],temp[25];
  int i=0,tlen,nlen,j,rep,len;
  printf("Enter a substring:");
  scanf("%s",sub);
  while(sub[i]!='\0')		
    i++;
  len=i;
  rep=search(str,sub);
  printf("Position is %d\n",rep+1);
  for(j=0;str[rep+j]!='\0';j++)
    temp[j]=str[rep+j+len];
  tlen=j;
  printf("Enter the string to replace:");
  scanf("%s",sub);
  i = 0;
  while(sub[i]!='\0')
    i++;
  nlen=i;
  for(j=0,i=rep;j<nlen;i++,j++)
    str[i]=sub[j];
  for(j=0,i=rep+nlen;j<(rep+tlen+nlen);i++,j++)
    str[i]=temp[j];
  puts(str);
}

int search(char src[25],char str[25])
{
  int i=0,j=0,found;
  while(src[i]!='\0')
    {
      while((src[i]!='\0') && (src[i]!=str[0]))
	{
	  i++;
	}
      found=i;
      if(src[i]==str[0])
	while((src[i]==str[j]) && (src[i]!='\0') && (str[j]!='\0'))
	  {
	    i++;
	    j++;
	  }
      if(str[j]=='\0')
	{
	  return found;
	}
      if(src[i]=='\0')
	return -1;
      found++;
      j=0;
    }
}

