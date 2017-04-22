#include<stdio.h>
#include<stdlib.h>
struct node
{
 int bid,free,allot;
 struct node *link;
}*start=NULL,*trav=NULL;


void best();
void worst();
void first();
void display();

struct block
{
  int bid,diff;
}a[10];

int pro,space;

main()
{
  int i,j=1000,ch;
  for(i=10;i>0;i--)
  {
   struct node *p;
   p=malloc(sizeof(struct node ));
   p->bid=i;
   p->free=j;
   p->allot=0;
   p->link=start;
   start=p;
   j=j-100;
  }
 do
  {
  printf("\nMenu\n\n1.Bestfit\n\n2.Worstfit\n\n3.Firstfit\n\n4.Exit\n");
  printf("\nEnter your choice:\n");
  scanf("%d",&ch);
  switch(ch)
    {
    case 1:display();
           printf("\nEnter processid:");
           scanf("%d",&pro);
           printf("\nEnter the memory space needed:");
	   scanf("%d",&space);
           best();
           break;
    case 2:display();
           printf("\nEnter processid:");
           scanf("%d",&pro);
           printf("\nEnter the memory space needed:");
	   scanf("%d",&space);
           worst();
           break;
    case 3:display();
           printf("\nEnter processid:");
           scanf("%d",&pro);
           printf("\nEnter the memory space needed:");
	   scanf("%d",&space);
           first();
           break;
    case 4:exit(0);
    }
  }while(ch!=4);
}

void display()
{
 int i;
 struct node *temp;
 temp=start;
 printf("\nBlockid	Free	 Allot");
 for(i=0;i<10;i++)
 {
  printf("\n%d	 %d	 %d	",temp->bid,temp->free,temp->allot);
  temp=temp->link;
 }
}

void best()
{
 struct block t;
 int i,j,blid;
 trav=start;
 for(i=0;i<10;i++)
 {
  a[i].bid=trav->bid;
  if(space<=trav->free)
  {
   a[i].diff=trav->free-space;
  }
  else
  {
   a[i].diff=-1;
  }
 trav=trav->link;
 }
 for(i=0;i<10;i++)
 {
  for(j=0;j<9;j++)
  {
   if(a[j].diff>a[j+1].diff)
   {
    t=a[j];
    a[j]=a[j+1];
    a[j+1]=t;
   }
  }
 }
 i=9;
 if(a[i].diff==-1)
  printf("\nNot enough memory.\n");
 else
 {
  for(i=0;i<10;i++)
  {
   if(a[i].diff!=-1)
   {
    blid=a[i].bid;
     printf("\nProcess fits in block %d",blid);
    break;
   }
  }
 }

 trav=start;
 while(trav!=NULL)
 {
  if(trav->bid==blid)
  {
   trav->free=trav->free-space;
   trav->allot+=space;
   break;
  }
  else
  {
   trav=trav->link;
  }
 }
 display();
}

void worst()
{
 struct block t;
 int i,j,blid;
 trav=start;
 for(i=0;i<10;i++)
 {
  a[i].bid=trav->bid;
  if(space<trav->free)
  {
   a[i].diff=trav->free;
  }
  else
  {
   a[i].diff=-1;
  }
 trav=trav->link;
 }
 for(i=0;i<10;i++)
 {
  for(j=0;j<9;j++)
  {
   if(a[j].diff>a[j+1].diff)
   {
    t=a[j];
    a[j]=a[j+1];
    a[j+1]=t;
   }
  }
 }
 i=9;
 if(a[i].diff==-1)
  printf("\nNot enough memory.");
 else
 {
  blid=a[i].bid;
  printf("\nProcess fits in block %d",blid);
 }

 trav=start;
 while(trav!=NULL)
 {
  if(trav->bid==blid)
  {
   trav->free=trav->free-space;
   trav->allot+=space;
   break;
  }
  else
  {
   trav=trav->link;
  }
 }
 display();
}

void first()
{
 int blid;
 trav=start;
 while(trav!=NULL)
 {
  if(trav->free>=space)
  {
   trav->free=trav->free-space;
   trav->allot+=space;
   printf("\nProcess fits in block %d",blid);
   display();
`++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   break;
  }
  else
   trav=trav->link;
 }
 if(trav==NULL)
  printf("\nNo memory");
}


/*OUTPUT

MENU

1.Bestfit

2.Worstfit

3.Firstfit

4.Exit

Enter your choice:
1

Blockid	Free	 Allot
1	 100	 0	
2	 200	 0	
3	 300	 0	
4	 400	 0	
5	 500	 0	
6	 600	 0	
7	 700	 0	
8	 800	 0	
9	 900	 0	
10	 1000	 0	
Enter processid:101

Enter the memory space needed:150

Process fits in block 2
Blockid	Free	 Allot
1	 100	 0	
2	 50	 150	
3	 300	 0	
4	 400	 0	
5	 500	 0	
6	 600	 0	
7	 700	 0	
8	 800	 0	
9	 900	 0	
10	 1000	 0	
MENU

1.Bestfit

2.Worstfit

3.Firstfit

4.Exit

Enter your choice:
2

Blockid	Free	 Allot
1	 100	 0	
2	 50	 150	
3	 300	 0	
4	 400	 0	
5	 500	 0	
6	 600	 0	
7	 700	 0	
8	 800	 0	
9	 900	 0	
10	 1000	 0	
Enter processid:105

Enter the memory space needed:366

Process fits in block 10
Blockid	Free	 Allot
1	 100	 0	
2	 50	 150	
3	 300	 0	
4	 400	 0	
5	 500	 0	
6	 600	 0	
7	 700	 0	
8	 800	 0	
9	 900	 0	
10	 634	 366	
MENU

1.Bestfit

2.Worstfit

3.Firstfit

4.Exit

Enter your choice:
3

Blockid	Free	 Allot
1	 100	 0	
2	 50	 150	
3	 300	 0	
4	 400	 0	
5	 500	 0	
6	 600	 0	
7	 700	 0	
8	 800	 0	
9	 900	 0	
10	 634	 366	
Enter processid:121

Enter the memory space needed:440

Process fits in block 0
Blockid	Free	 Allot
1	 100	 0	
2	 50	 150	
3	 300	 0	
4	 400	 0	
5	 60	 440	
6	 600	 0	
7	 700	 0	
8	 800	 0	
9	 900	 0	
10	 634	 366	
MENU

1.Bestfit

2.Worstfit

3.Firstfit

4.Exit

Enter your choice:
4
*/
