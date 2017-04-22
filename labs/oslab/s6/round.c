#include <stdio.h>
#include <string.h>

typedef struct processType
{
  int at, bt, tt, wt, left, status, st, ct;
  char pname[40];
}process;

process d[20];
process p[100];
int num = 0, n;
float avgWait = 0, avgTT = 0;

int queue[100], front = -1, rear = -1;
int enq(int x);
int dq();


int roundRobin(process p[], int n);
int display();

int main()
{
  int i;
 
  system("clear");

  printf("\n\n\t How many processes : ");
  scanf("%d", &n);

  for(i = 0;i < n;i++)
    {
      printf("\n\t process %d pid : ", i+1);scanf("%s", p[i].pname);
      printf("\n\t process %d arrival time : ", i+1);scanf("%d", &p[i].at);
      printf("\n\t process %d burst time : ", i+1);scanf("%d", &p[i].bt);
      p[i].status = 0;
      p[i].left = p[i].bt;
    }

  roundRobin(p, n);
  display();

  printf("\n\n");
	 
  return 0;
}


int roundRobin(process p[], int n)
{
  int flag = 0, time = 1, avgWait = 0, avgTT = 0, ls = 0, i, j, k;

  for(i = 0; ls < n;)
    {
      printf("\ndebug\n");
      for(j = 0; j < n; j++)
	if(p[j].status == 0 && p[j].at <= i)
	  {
	     enq(j);
	  }
      
      if(flag == 0 && front == -1)
	{
	  strcpy(d[num].pname, "idle");
	  d[num].st = i;
	  i++;num++;
	  flag = 1;
	}
      else if(front != -1)
	{
	  k = dq();
	  strcpy(d[num].pname, p[k].pname);
	  d[num].st = i;
	  
	  if(p[k].left <= time)
	    {
	      d[num].ct = i + p[k].left;
	      i = d[num].ct;
	      num++;ls++;

	      p[k].tt = i - p[k].at;
	      p[k].wt = p[k].tt - p[k].bt;
	      p[k].ct = d[num-1].ct;
	    }
	  else
	    {
	      d[num].ct = i + time;
	      i = d[num].ct;
	      p[k].left -= time;
	      num++;
	      
	      for(j = 0; j < n; j++)
		{
		  if(p[j].status == 0 && p[j].at <= i)
		    {
		      enq(j);
		    }
		}
	      enq(k);
	    }
	}
      else
	{
	  i++;
	}
	  
    }

  return 0;
}

int display()
{
  int i;

  system("clear");

  printf("\n\n");

  for(i = 0; i < num; i++)
    {
      printf("-------");
    }
  printf("\n");

  for(i = 0; i < num; i++)
    {
      if(strcmp(d[i].pname, "idle"))
	{
	  printf("   %s  |", d[i].pname);
	}
      else
	{
	  printf("  %s |", d[i].pname);
	}	  
	    
    }
  printf("\n");


  for(i = 0; i < num; i++)
    {
      printf("-------");
    }
  printf("\n");

  for(i = 0; i < num; i++)
    {
      printf("%d      ", d[i].st);
    }
  printf("%d", d[i-1].ct);
  printf("\n\n\n");


  printf("------------------------------------------------\n");
  printf("  pid      at      bt      wt      tt      ct   \n");
  printf("------------------------------------------------\n");

  for(i = 0; i < n; i++)
    {
      printf("    %s       %d       %d       %d       %d       %d   \n", p[i].pname, p[i].at, p[i].bt, p[i].wt, p[i].tt, p[i].ct);
      avgWait += p[i].wt;
      avgTT += p[i].tt;      
    }

  avgWait /= (float)n;
  avgTT /= (float)n;

  printf("------------------------------------------------\n");


  printf("\n\n\t Average Waiting Time : %f", avgWait);
  printf("\n\n\t Average Turn Around Time : %f", avgTT);

  return 0;
}


int enq(int x)
{
  if(rear == -1)
    {
      front = 0;
      rear = 0;
    }
  else
      rear++;

  queue[rear] = x;
  p[x].status = 1;

  return 0;
}

int dq()
{
  int item = -1;

  item = queue[front];

  if(front == -1)
    printf("\n\t Queue Empty\n");
  else if(front == rear)
    {
      front = -1;
      rear = -1;
    }
  else
    front++;

  return item;
}
    
    