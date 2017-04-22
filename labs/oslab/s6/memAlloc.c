#include <stdio.h>
#include <malloc.h>

typedef struct nodeType
{
  int bid, freeMem, allocMem;
  struct nodeType *next;
}node;

int memPerBlock = 1000, n;

node *start = NULL;

int first();
int best();
int worst();
int display();

int main()
{
  node *temp;
  int opt = 1, i;

  system("clear");

  printf("\n\n\t How many blocks : ");
  scanf("%d", &n);

  for (i = 0; i < n; i++)
    {
      if(start == NULL)
	{
	  start = malloc(sizeof(node));
	  temp = start;
	}
      else
	{
	  temp->next = malloc(sizeof(node));
	  temp = temp->next;
	}
      
      temp->freeMem = memPerBlock;
      temp->allocMem = 0;
      temp->bid = i;
	  
      memPerBlock = memPerBlock - 100;
    }
  
  system("clear");




  while(opt)
    {
      printf("\n\n\t Choose an option : ");
      printf("\n\t\t 1. First fit");
      printf("\n\t\t 2. Best fit");
      printf("\n\t\t 3. Worst fit");
      printf("\n\t\t 4. Quit");

      printf("\n\n\t\t option : ");
      scanf("%d", &opt);

      system("clear");

      switch(opt)
	{
	case 1:first();break;
	case 2:best();break;
	case 3:worst();break;
	case 4:opt = 0;break;
	default:printf("\n\n\t\t Invalid Option");
	}

      display();

    }


  system("clear");
  return 0;
}


int first()
{
  node *temp;
  int pMem;

  system("clear");
  printf("\n\n\t Memory required : ");
  scanf("%d", &pMem);

  for(temp = start; temp->next != NULL; temp = temp->next)
    {
      if(temp->freeMem >= pMem)
	{
	  
	  temp->freeMem -= pMem;
	  temp->allocMem += pMem;
	  break;
	}
    }


  return 0;
}

int best()
{
  node *temp, *index;
  int pMem, min = 10000;

  system("clear");
  printf("\n\n\t Memory required : ");
  scanf("%d", &pMem);

  for(temp = start; temp != NULL; temp = temp->next)
    {
      if(temp->freeMem >= pMem && temp->freeMem <= min)
	{
	  index = temp;
	  min = temp->freeMem;
	}
    }

  index->freeMem -= pMem;
  index->allocMem += pMem;


  return 0;
}

int worst()
{
  node *temp, *index;
  int pMem, max = -10000;

  system("clear");
  printf("\n\n\t Memory required : ");
  scanf("%d", &pMem);



  for(temp = start; temp != NULL; temp = temp->next)
    {
      if(temp->freeMem >= pMem && temp->freeMem >= max)
	{
	  printf("\n\t freeMem = %d, max = %d", temp->freeMem, max);
	  index = temp;
	  max = temp->freeMem;
	}
    }

  index->freeMem -= pMem;
  index->allocMem += pMem;


  return 0;  
}


int display()
{
  node *temp;

  printf("\n\n\t--------------------------");
  printf("\n\tBlock\tFree\tAllocated");
  printf("\n\t--------------------------");

  for(temp = start;temp != NULL ; temp = temp->next)
    {
      printf("\n\t%d  \t%d  \t%d", temp->bid, temp->freeMem, temp->allocMem);
      // printf("\n\t Free Memory : %d", temp->freeMem);
      // printf("\n\t Allocated Memory : %d", temp->allocMem);
    }

  printf("\n\t--------------------------");

  return 0;
}

