//Program to Store Marklist of Students 
#include<stdio.h>
struct student
{
     int roll,m[5];
     char name[15];
     float total;
}s[30];
void add(int,int);
int del(int,int);
void rank(int,int);
main()
{
        int i=0,k,z=0,n,j,t; 
	char c='y';
        printf("Enter the value of n \n");
        scanf("%d",&n);
	printf("Enter the number of subjects\t");
		scanf("%d",&t);
        printf("Enter the student details \n");
        for(i=0;i<n;i++)
	  {
 		s[i].total=0;
	        printf("Enter roll no: ");
  	        scanf("%d",&s[i].roll);
  		printf("Enter name: ");
  		__fpurge(stdin);
  		gets(s[i].name);
 		printf("Enter marks of %d subjects: ",t);
  		for(j=0;j<t;++j)
    		{
      			scanf("%d",&s[i].m[j]);
      			s[i].total=s[i].total+s[i].m[j];
    		}
    	}
  do
  {
	int n,j;
        printf("\n\t\t\tMENU\n");
        printf("\n\t1.Add record\n\t2.Delete record\n\t3.Display ranklist\n");
        printf("\nEnter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
           case 1:add(i,t);i++;break;
           case 2:z=del(i,t);if(z==1)i--;break;
           case 3:k=i;rank(k,t);break;
	   default:printf("Invalid selection\n");
         }
  }while(c=='y');
}

void add(int i,int t)
{
     int j;
     s[i].total=0;
     printf("Enter roll no: ");
     scanf("%d",&s[i].roll);
     printf("Enter name: ");
     __fpurge(stdin);
     gets(s[i].name);
     printf("Enter marks of %d subjects: ",t);
     for(j=0;j<t;++j)
     {
          scanf("%d",&s[i].m[j]);
          s[i].total+=s[i].m[j];
     }
     printf("Roll no :%d  Name:%s  Total mark:%f",s[i].roll,s[i].name,s[i].total);
}


 void rank(int k,int t)
 {
     int i,j;
     struct student temp;
     for(i=0;i<=k-2;++i)
           for(j=0;j<k-i-1;++j)
                if(s[j].total<s[j+1].total)
	        {
	          temp=s[j+1];
	          s[j+1]=s[j];
	          s[j]=temp;
	        }
      printf("\nRank Roll no  Name                   Total\n");
      for(i=0;i<k;++i)
      printf("%d    %d        %-12s                 %f\n",i+1,s[i].roll,s[i].name,s[i].total);
 }



int del(int k,int t)
{
  if(k==0)
    printf("\nEmpty");
else
  {
    int i,j,rolln,f=0;
    printf("Enter the roll no of the record to be deleted :");
    scanf("%d",&rolln);
    for(i=0;i<k;++i)
    {
        if(s[i].roll==rolln)
        {
           for(j=i;j<k;++j)
           s[j]=s[j+1];
           f=1;
        }
    }

  if(f!=1)
    printf("\nRecord not found");
  else
    return 1;
  }
}