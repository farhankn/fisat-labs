//Program to sort a list of strings.
#include<stdio.h>
#include<stdlib.h>
void copy(char *str,char *b);
void sort(char **a,int n);
int compare (char *str1,char *str2);
void swap(char *a,char *b);
int length(char str[20]);
main()
{
  char name[20],*ptr[10];
  int i,n,len;
  printf("Enter the number of strings:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("Enter name:");
      scanf("%s",name);
      len=length(name);
      *(ptr+i)=(char*)malloc(sizeof(char)*len);
      copy(name,*(ptr+i));
    }
  sort(ptr,n);
  printf("Sorted list of strings is as follows:\n");
  for(i=0;i<n;i++)
    {
      printf("%s\n",*(ptr+i));
    }
}
//Function to copy.
void copy(char *str,char *b)
{
  int i;
  for(i=0;*(str+i)!='\0';i++)
    *(b+i)=*(str+i);
  *(b+i)='\0';
}

//Function to sort the array.
void sort(char **str,int n)
{
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n-i-1;j++)
      {
	if(compare((*(str+j)),(*(str+j+1)))==1)
	   swap(*(str+j),*(str+j+1));
      }
}
//Function to compare to strings.
int compare (char *str1,char *str2)
{
  int i=0;
  while(*(str1+i)!='\0' && *(str2+i)!='\0')
    {
      if((*(str1+i))==(*(str2+i)))
	i++;
      else if((*(str1+i))>(*(str2+i)))
	return 1;
      else 
	return 0;
    }
}
//Function to swap to strings.
void swap(char *a,char *b)
{
  char temp[20];

  copy(a,temp);                    //swapping value of variables
  copy(b,a);
  copy(temp,b);
}
//Function to find length of a string.
int length(char str[20])
{
  int i=0;
  while(*(str+i)!='\0')
    i++;
  return i;
}
