#include<stdio.h>
#include<string.h>

struct process
{
	char pname[20];
	int at,bt,wt,tt,status;
}p[30];

struct done
{
	char name[20];
  int st,ct;
}d[20];

main()
{
  int num,found,flag,i,k,j,idle=0,ls,n,l;
  float atat=0,atwt=0;
  printf("Enter the number of processes:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("\nProcess %d \n",i+1);
      printf("Name: ");
      scanf("%s",p[i].pname);
      printf("Arrival time:");
      scanf("%d",&p[i].at);
      printf("Burst time:");
      scanf("%d",&p[i].bt);
      p[i].status=0;
    }
  
  printf("\n");
  for(i=0;ls<n;)
    {
      flag=0;
      found=0;
      for(j=0;j<n;j++)
	{
	  if(p[j].status==0&&p[j].at<=i&&found==0)
	    {
	      k=j;
	      found++;
	      flag++;
	    }
	  else if(found>0&&p[j].status==0&&p[j].at<=i)
	    {
	      if(p[j].bt<p[k].bt)
		{		
		  k=j;
		}
	      else if(p[j].bt==p[k].bt)
		{
		  if(p[j].at<p[k].at)
		    {
		      k=j;
		    }
		}
	    }
	}
      if(flag==0&&idle==0)
	{
	  idle=1;
	  strcpy(d[num].name,"IDLE");
	  d[num].st=i;
	  i++;
	}
      else if(flag>0)
	{
	  if(idle==1)
	    {
	      d[num].ct=i;
	      num++;
	    }
	  strcpy(d[num].name,p[k].pname);
	  d[num].st=i;
	  d[num].ct=i+p[k].bt;
	  p[k].wt=d[num].st-p[k].at;
	  p[k].tt=p[k].wt+p[k].bt;		
	  i=d[num].ct;
	  p[k].status=1;
	  num++;
	  idle=0;
	  ls++;
	}
      else
	{
	  i++;
	}
    }
  printf("\n Process Table \n");
  printf("\nPname\tAT\tBT\tStatus\tWT\tTT\n");
  for(i=0;i<n;i++)
    {
      printf("%s\t%d\t%d\t%d\t%d\t%d\n",p[i].pname,p[i].at,p[i].bt,p[i].status,p[i].wt,p[i].tt);
    }
  printf("\n");
  printf("\nName\tST\tCT\n");
  for(i=0;i<num;i++)
    {
      printf("%s\t%d\t%d\n",d[i].name,d[i].st,d[i].ct);
    }
  printf("\nGantt Chart\n");
  for(i=0;i<num;i++)
    {
      printf("---------");
    }
  printf("\n");
  for(i=0;i<num;i++)
    {
      printf("|  %s  ",d[i].name);
    }
  printf("|");
  printf("\n");
  for(i=0;i<num;i++)
    {
      printf("---------");
    }
  printf("\n");	
  for(i=0;i<num;i++)
    {
      printf("%d     ",d[i].st);
      l=i;
    }
  printf("%d",d[l].ct);
  printf("\n\n");
  
  for(i=0;i<num;i++)
    {
      atwt+=p[i].wt;
      atwt=atwt/num;
      atat+=p[i].tt;
      atat=atat/num;
    }
  printf("\n Average Waiting Time %2f",atwt);
  printf("\n Average Turnaround Time %2f\n",atat);
}
