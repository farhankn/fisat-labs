//Menu driven program to add,delete and modify the details of a book using files
#include<stdio.h>
#include<stdlib.h>
struct book
{
	int bookno;
	char name[30];
	char author[30];
	float cost;
}s;
void add();
void delete();
void modify();
main()
{    
        int n;
	char c;
	do
	{
	printf("Enter your choice\n");
	printf("\n\t\tMENU\n");
	printf("\t1.Add a book \n\t2.Delete a book \n\t3.Modify a book\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:add();break;
		case 2:delete();break;
		case 3:modify();break;
		default:printf("Invalid choice\n");
	}
	 printf("\nDo you want to continue(y/n): ");
        __fpurge(stdin);
        scanf("%c",&c);
	}while(c=='y'||c=='Y');
}
void add()
{
	int n;
	FILE *ptr;
	ptr=fopen("books.txt","a+");
	if(ptr==NULL)
	{
		printf("Cannot open source file\n");
		exit(0);
	}
	printf("Enter the book number : ");
	scanf("%d",&s.bookno);
	printf("Enter the book name : ");
	__fpurge(stdin);
	gets(s.name);
	printf("Enter the name of author : ");
	__fpurge(stdin);
	gets(s.author);
	printf("Enter the cost : ");
	scanf("%f",&s.cost);
	fprintf(ptr," %d %s %s %f",s.bookno,s.name,s.author,s.cost);
	fclose(ptr);
}
void delete()
{	
	int a;char c;
	FILE *ptr,*ptr1;
	ptr=fopen("books.txt","r");
	if(ptr==NULL)
	{
		printf("Cannot open source file\n");
		exit(0);
	}
	ptr1 = fopen("temp.txt","w+");
	if(ptr1==NULL)
	{
		printf("Cannot open destination file\n");
		exit(0);
	}
	printf("Enter the book number to be deleted : ");
	scanf("%d",&a);
	fscanf(ptr,"%d %s %s %f",&s.bookno,s.name,s.author,&s.cost);
	while(1)
	{
	if(s.bookno==a)
	{
	printf("Deleted Line: %d %s %s %f \n",s.bookno,s.name,s.author,s.cost);
	}
	else
	{
        fprintf(ptr1," %d %s %s %f",s.bookno,s.name,s.author,s.cost);
        }
	if(feof(ptr))
	break;
	fscanf(ptr,"%d %s %s %f",&s.bookno,s.name,s.author,&s.cost);
	}
	fclose(ptr);
	fclose(ptr1);
	remove("books.txt");
	rename("temp.txt","books.txt");
}	
void modify()
{
	int a;
	FILE *ptr,*ptr1;
	ptr=fopen("books.txt","r+");
	if(ptr==NULL)
	{
		printf("Cannot open source file\n");
		exit(0);
	}
	ptr1=fopen("temp.txt","w");
	if(ptr1==NULL)
	{
		printf("Cannot open destination file\n");
		exit(0);
	}
	printf("Enter the book number to be modified : ");
	scanf("%d",&a);
	while(1)
	{
		if(feof(ptr))
		break;
		fscanf(ptr,"%d %s %s %f",&s.bookno,s.name,s.author,&s.cost);
		if(s.bookno!=a)
		{
		fprintf(ptr1," %d %s %s %f",s.bookno,s.name,s.author,s.cost);
		}
 		else
		{
		printf("Enter the book name : ");
		__fpurge(stdin);
		gets(s.name);
		printf("Enter the name of author : ");
		gets(s.author);
		printf("Enter the cost : ");
		scanf("%f",&s.cost);
		fprintf(ptr1," %d %s %s %f",s.bookno,s.name,s.author,s.cost);
		}
		
	}
	fclose(ptr);
	fclose(ptr1);
	remove("books.txt");
	rename("temp.txt","books.txt");
	
}
