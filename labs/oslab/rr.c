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
float AWT = 0, ATT = 0;
int queue[100], front = -1, rear = -1;
int enq(int x);
int dq();
int round(process p[], int n, int time);
void display();

void main()
{
  int i,time,l; 
  printf("\n\n No. of Processes : ");
  scanf("%d", &n);  
  for(i = 0;i < n;i++)
    {
      printf("Enter the name of process: ");
      scanf("%s",&p[i].pname);
      printf("Enter the AT of process: ");
      scanf("%d",&p[i].at);
      printf("Enter the BT of process: ");
      scanf("%d",&p[i].bt);;
      p[i].status = 0;
      p[i].left = p[i].bt;
    }
  printf("Enter time slice :");
  scanf("%d",&time);  
  round(p, n, time);
  display();  
  printf("\n\n");   
}

int round(process p[], int n, int time)
{
  int flag = 0, AWT = 0, ATT = 0, ls = 0, i, j, k;  
  for(i = 0; ls < n;)
    {      
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

void display()
{
  int i,l;
  printf("\n\n");
  for(i = 0; i < num; i++)
    {
      printf("-----------------------");
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
       printf("-----------------------");
    }
  printf("\n");
  
  for(i = 0; i < num; i++)
    {
      printf("%d      ", d[i].st);
    }
  printf("%d", d[i-1].ct);
  printf("\n\n\n");
  printf("\n\t\t\tTable\n\t\t\t-----\n");
  printf("------------------------------------------------------------------------------------------");
  printf("\nProcess |       AT      |       BT      |      TAT      |       WT      |      CT          \n");
		i=0; 		
		while(i<n)
		  {
		    printf("------------------------------------------------------------------------------------------");
		    printf("\n");
		    printf("%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",p[i].pname,p[i].at,p[i].bt,p[i].tt,p[i].wt,p[i].ct);
		    printf("\n");
		    i++;
		}
		l=0;
		while(l<n)
		  {
			AWT +=p[l].wt;
			ATT +=p[l].tt;
			l++;
		  }
		AWT /= (float)n;
		ATT /= (float)n;		
  printf("------------------------------------------------\n");    
  printf("\n\n\t Average Waiting Time : %f", AWT);
  printf("\n\n\t Average Turn Around Time : %f", ATT);  
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


