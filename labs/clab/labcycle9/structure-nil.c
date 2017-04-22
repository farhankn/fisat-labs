//Menu driven Program to Add a student record,Delete a student record and prepare a ranklist.
#include<stdio.h>

struct student_details
{
  char name[50];
  int rollNo;
  int mrk1;
  int mrk2;
  int mrk3;
  int tot;

}details[100],sorted[100],temp;
void markList();
void Remove();
void add();
void rankList();
void copy();
int next=0;

main()
{
  int choice,i,n;
  char c;
  do
    {
      
      printf("\nMENU\n*****\n1.Add student record\n2.Remove student record\n3.Prepare ranklist\n5.Exit\n\nChoice : ");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1 : printf("Enter the number of student records to add:");
	  scanf("%d",&n);
	  for(i=0;i<n;i++)
	    add();	  
	  markList();
	  break;
	case 2 :Remove();
	  markList();
	  break;
	case 3 : rankList();
	break;
	case 4 :printf("Exiting!!!");
	  break;
	default : printf("Invalid option");
	}
      printf("\nDo you want to continue(y/n)??");
      scanf("%s",&c);
    }while(c=='y');
  
} 


//Function to add student record.
void add()
{
  printf("\nEnter the details\n");
  printf("Enter name : ");
  scanf("%s",&details[next].name);
  printf("Enter roll number : ");
  scanf("%d",&details[next].rollNo);
  printf("Enter marks 1 : ");
  scanf("%d",&details[next].mrk1);
  printf("Enter marks 2 : ");
  scanf("%d",&details[next].mrk2);
  printf("Enter marks 3 : ");
  scanf("%d",&details[next].mrk3);
  
  details[next].tot=details[next].mrk1+details[next].mrk2+details[next].mrk3;
  
  next+=1;
  
  printf("\n\nStudent details added to the record.\n");
  
}

//Function to Remove student record.

void Remove() {
  int rollNo;
  int i;
  int j;
  printf("\nEnter the roll number of student to be deleted : ");
  scanf("%d",&rollNo);

  for(i=0;i<next;++i) {
    if(details[i].rollNo==rollNo) {
      for(j=i;j<next-1;++j)
	details[j]=details[j+1];
    }
  }

  next-=1;

  printf("\n\nStudent details Removed from the record");

}
//Function to display marklist.
void markList()
{
  int rollNo;
  int i,j;
  int found=0;
  printf("\nSTUDENT MARKLIST\n");
  for(i=0;i<next;++i)
    {     
      
      printf("\n\nStudent Name:%d ",details[i].name); 
      printf("\tRoll No.:%d",details[i].rollNo); 
      printf("\tChemistry:%d",details[i].mrk1); 
      printf("\tPhysics:%d",details[i].mrk2); 
      printf("\tMaths:%d",details[i].mrk3); 
      printf("\tTotal:%d",details[i].tot);
      
      found=1;
      
    }
  
  if(found==0)
    printf("\n\nThe student record was not found !");
  
}

//Function to display ranklist.
void rankList() 
{
  
  copy();
  
  int i;
  int j;
  
  for(i=0;i<next;++i)
    {
      for(j=0;j<next-i-1;++j)
	{
	  if(sorted[j].tot<sorted[j+1].tot) {
	    temp=sorted[j];
	    sorted[j]=sorted[j+1];
	    sorted[j+1]=temp;
	  }
	}
    }
  
  
  printf("\n\nStudent RankList\n\n");
  printf("Rank\t\t Name\t\t\tMarks\t\tRoll No\n\n");
    for(i=0;i<next;++i) {
      printf("%d    \t\t %s\t \t%d\t\t%d\n",i+1,sorted[i].name,sorted[i].tot,sorted[i].rollNo);
    }
}

//Function to copy data.
void copy()
{
  int i;
  for(i=0;i<next;++i)
    sorted[i]=details[i];
  
}

