#include<stdio.h>
int n,front[10],rear[10],a[10][10];

void ins()
{
  int pr,item;
  printf("Enter item and priority");
  scanf("%d%d",&item,&pr);
  if (pr>=n)
    printf("insertion not possible");
  if(rear[pr]==n)
    printf("Queue is priority is full");
  
  else
    {
      rear[pr]=rear[pr]+1;
      a[pr][rear[pr]]=item;
      if(front[pr]==0)
	front[pr]=1;
    }
}
void del()
{int pr,item;
  pr=n-1;
  while(pr>=0)
    {
      if(front[pr]==0)
	pr--;
      else{
	item=a[pr][front[pr]];
	printf("deleted item:%d\n",item);
	if(front[pr]==rear[pr])
	  { front[pr]=0;
	rear[pr]=0;
          }
	else
	  front[pr]=front[pr]+1;
	break;
      }
    }

}
void display()
{
  int i,j;
  for(i=0;i<n;i++)
    {printf("\nElements with priority %d:",i);
      for(j=front[i];j<=rear[i];j++)
	
	  if(front[i]==0)
	    { printf("Empty");
	      break;
	    }
      else
	printf("%d ",a[i][j]);
}
  printf("\n");
}
void main()
{int c;
  char y;
  printf("Enter max size");
  scanf("%d",&n);
  do{
    printf("MENU\n1.INSERSTION\n2.DELETION\n3.DISPLALY");
    printf("\nEnter choice");
    scanf("%d",&c);
    switch(c)
      {
      case 1:
	ins();
	break;
      case 2:
	del();
	break;

      case 3:
	display();
	break;
}    
    printf("Do you wanna continue?");
    __fpurge(stdin);
    scanf("%c",&y);
      
      }while(y=='y');

}
