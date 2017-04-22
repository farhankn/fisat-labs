#include <stdio.h>
#include <malloc.h>
void display();
struct pnode
{
  int bid, freeMem, allocMem;
  struct pnode *next;
}node;


void display()
{
  node *temp;
  printf("\n\tBlock\tFree\tAllocated");
  for(temp = start;temp != NULL ; temp = temp->next)
    {
      printf("\n\t%d\t%d\t%d",temp->bid,temp->freeMem,temp->allocMem);
    }
}


