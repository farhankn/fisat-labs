#include<stdio.h>

struct process
{
  int pid;
  int st,ct,wt,bt,tt,at;
};

int sort(struct process p[],int totalProcesses);
int calculate(struct process p[],int totalProcesses);
int printGantt(struct process p[],int totalProcesses);

int main()
{

  struct process p[100];
  int totalProcesses,i;;

  system("clear");

  printf("\n\t How many processes : ");
  scanf("%d",&totalProcesses);

  for(i=0;i<totalProcesses;i++)
    {
      fflush(stdin);
      
      printf("\n\t Enter the pid of process %d : ",i+1);
      scanf("%d",&p[i].pid);
      fflush(stdin);
      printf("\n\t Enter the arrival time of process %d : ",i+1);
      scanf("%d",&(p[i].at));
      printf("\n\t Enter the burst time of process %d : ",i+1);
      scanf("%d",&(p[i].bt));
    }

  /*
  for(i=0;i<totalProcesses;i++)
    {
      printf("\n\t pid of process %d : %d",i+1,p[i].pid);
     
      printf("\n\t arrival time of process %d :%d ",i+1,p[i].at);
     
      printf("\n\t burst time of process %d :%d ",i+1,p[i].bt);
     
    }
  */

  sort(p,totalProcesses);
  calculate(p,totalProcesses);
  printf("\n\n");
  printGantt(p,totalProcesses);

  
  printf("\n\n");
  return 0;
}

int sort(struct process p[],int totalProcesses)
{
  struct process temp;
  int i,bubble = 1;

  while(bubble)
    {
      bubble = 0;
      for(i=0;i<(totalProcesses-1);i++)
	{
	  if(p[i].at > p[i+1].at)
	    {
	      temp = p[i];
	      p[i] = p[i+1];
	      p[i+1] = temp;
	      bubble = 1;
	    }
	    
	}
    }

  return 0;

}
	    
int calculate(struct process p[],int totalProcesses)
{
  float avgWait = 0,avgTA = 0;
  int i;

  p[0].st = p[0].at;
  p[0].ct = p[0].st + p[0].bt;
  p[0].wt = 0;
  p[0].tt = p[0].wt + p[0].bt;

  avgTA += p[0].tt;

  for(i=1;i<totalProcesses;i++)
    {
      if(p[i].at >= p[i-1].ct)
	{
	  p[i].st = p[i].at;
	  p[i].ct = p[i].st + p[i].bt;
	  p[i].wt = 0;
	  p[i].tt = p[i].wt + p[i].bt;
	}
      else
	{
	  p[i].st = p[i-1].ct;
	  p[i].ct = p[i].st + p[i].bt;
	  p[i].wt = p[i].st - p[i].at;
	  p[i].tt = p[i].wt + p[i].bt;
	}

      avgWait += p[i].wt;
      avgTA += p[i].tt;
    }

  avgWait /= totalProcesses;
  avgTA /= totalProcesses;

  printf("\n\n\t Average Waiting Time : %f ",avgWait);
  printf("\n\n\t Average Turn Around Time : %f ",avgTA);

  return 0;
}

int printGantt(struct process p[],int totalProcesses)
{
  int i,temp;

  if(p[0].st > 0)
    printf("-------",p[0].st);

  printf("-------");
  for(i=1;i<totalProcesses;i++)
    {
      if(p[i].st > p[i-1].ct)
	printf("-------");
      printf("-------");
    }
  printf("-");

  printf("\n");

  if(p[0].st > 0)
    printf("| idle ",p[0].st);
  

  printf("|   %d  ",p[0].pid);

  for(i=1;i<totalProcesses;i++)
    {
      if(p[i].st > p[i-1].ct)
	printf("| idle ");

      printf("|   %d  ",p[i].pid);
    }
  printf("|");
  printf("\n");

  printf("-------");
  for(i=1;i<totalProcesses;i++)
    {
      if(p[i].st > p[i-1].ct)
	printf("-------");
      printf("-------");
    }
  printf("-");


  if(p[0].st > 0)
    printf("-------",p[0].st);

  temp = totalProcesses;

  printf("\n0");
  if(p[0].st > 0)
    printf("      %d",p[0].st);
  for(i=1;i<temp;i++)
    {
      printf("      ");
      if(p[i].st > p[i-1].ct)
	{
	  printf("%d",p[i-1].ct);
	  printf("      %d",p[i].st);
	}
      else
	printf("%d",p[i].st);
    }
  printf("      %d",p[i-1].ct);

  return 0;
}
