#include <stdio.h>
#include <string.h>

typedef struct processType
{
  int pid, at, bt, tt, wt, st, ct, left, status;
  char pname[15];
}process;

int read(process p[], int *n);
int roundRobin(process p[], int n);
int display(process p[], int *n);

process d[10];
int queue[100], front = -1, rear = -1;

int enqueue(int n);
int dequeue();

int main()
{
  int n, ls = 0, flag = 0, num = 0, time, avgWait = 0, avgTT = 0;
  process p[10];

  read(p, &n);
  roundRobin(p, n);
  display(p ,&n);

  return 0;
}


int read(process p[], int *n)
{
  int i, num;

  system("clear");
  printf("\n\n\t How many processes : ");
  scanf("%d",&num);

  for(i = 0;i < num; i++)
    {
      printf("\n\t pid of process %d : ",i+1);
      scanf("%d",&p[i]);
      printf("\n\t arrival time of process %d : ",i+1);
      scanf("%d",&p[i]);
      printf("\n\t burst time of process %d : ",i+1);
      scanf("%d",&p[i]);

      p[i].status = 0;
    }

  *n = num;
  return 0;
}

int roundRobin(process p[], int n)
{
  int i, j, num = 0, flag = 0, ls= 0, k, time = 1;

  for(i = 0; ls < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  if(p[j].status == 0 && p[j].at <= i)
	    enqueue(j);

	  if(flag == 0 && front == -1)
	    {
	      strcpy(d[num].pname, "idle");
	      d[num].st = i;
	      i++;num++;
	      flag = 1;
	    }
	  else if(front != -1)
	    {
	      k = dequeue();
	      strcpy(d[num].pname, p[k].pname);
	      d[num].st = i;
	      if(p[k].left < time)
		{
		  d[num].ct = i + p[k].left;
		  i + d[num].ct;
		  num++;
		  ls++;
		}
	      else
		{
		  d[num].ct = i + time;
		  i = d[num].ct;
		  p[k].left = p[k].left - time;
		  num++;
		  
		  if(p[i].status == 0 && p[j].at <= i)
		      enqueue(j);
		  enqueue(k);
		}
	    }
	  else
	      i++;
	}	

	      
    }

  return 0;
}


int enqueue(int n)
{
  if(rear == -1)
    {
      front = 0;
      rear = 0;
      queue[rear] = n;
    }
  else
    {
      rear++;
      queue[rear] = n;
    }

  return 0;
}

int dequeue()
{
  int item;
  if(front == -1)
    {
      printf("\n\t stack empty");
      return -1;
    }
  else if(front == 0 && rear == 0)
    {
      item = queue[front];
      front = -1;
      rear = -1;
    }
  else
    {
      item = queue[front];
      front++;
    }

  return item;
}


int display(process p[], int *n)
{
  
  

  return 0;
}