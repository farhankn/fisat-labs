#include <stdio.h>
#include <string.h>

main()
{
  int i, j, k = 0, current, flag = 0, refer[20], numRefer, page[20], numPage, pageFaults = 0;
  char refString[100];
  printf("\n\n\t How many pages : ");
  scanf("%d", &numPage);

  for(i = 0; i < numPage; i++)
    page[i] = -1;
  printf("\n\t Enter the reference string : ");
  scanf("%s", &refString);
  numRefer = strlen(refString);
  for(i = 0; i < numRefer; i++)
    {
      refer[i] = refString[i] - '0';
    }

  for(i = 0; i < numRefer; i++)
    {
      current = refer[i];
      
      for(j = 0, flag = 1; j < numPage; j++)
	if(page[j] == current)
	  flag = 0;

      if(flag)
	{
	  pageFaults++;
	  
	  if(k > (numPage - 1))
	    k = 0;
	  
	  page[k] = current;
	  
	  k++;
	}
  int i;
  printf("\n\n\t Page table for %d", current);
  printf("\n\n\t");
  for(i = 0; i < numPage; i++)
    {
      printf("-----");
    }

  printf("-\n\t|");
  for(i = 0; i < numPage; i++)
    {
      if(page[i] >= 0)
	printf("  %d |", page[i]);
      else
	printf("    |");
    }

  printf("\n\t-");

  for(i = 0; i < numPage; i++)
    {
      printf("-----");
    }
 
  printf("\n\n\t Total page faults : %d\n\n", pageFaults);
}
	  

