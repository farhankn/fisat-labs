#include<stdio.h>
#include<stdlib.h>
struct node
{int vertex;
  struct node *link;
};
struct node *gptr[20];
int top=-1,s[20],n,f=0,r=0,q[20],m=0,l=0,b[10],c[10];
void push(int x);
int pop();
void enqueue(int y);
int dequeue();

void dfs(int v)
{int u;
 struct node *p;
  if(gptr==NULL)
    {printf("graph is empty\n");
      exit(0);
    }
  else
    {u=v;
      push(u);
      while(top>-1)
	{u=pop();
	  if(search(b,u,m)==0)
	    {b[m++]=u;
		p=gptr[u];
		while(p!=NULL)
		  {push(p->vertex);
		    p=p->link;
		  }
	    }
	}
    }
}

void push(int x)
{
  top++;
  s[top]=x;
}

int pop()
{int y;
  y=s[top];
  top--;
  return y;
}

void bfs(int v)
{int u;
  struct node *p;
  if(gptr==NULL)
    {printf("graph is empty\n");
      exit(0);
    }
  else
    {u=v;
      enqueue(u);
      while(f!=0)
	{u=dequeue();
	  if(search(c,u,l)==0)
	    {c[l++]=u;
		p=gptr[u];
		while(p!=NULL)
		  {enqueue(p->vertex);
		    p=p->link;
		  }
	    }
	}
    }
}

void enqueue(int v)
{
  r++;
  q[r]=v;
  if(f==0)
    f=1;
}

int dequeue()
{int x;
  x=q[f];
  if(f==r)
    {f=0;
      r=0;
    }
  else 
    f++;
  return x;
}

int search(int b[50],int u,int k)
{int i;
  for(i=0;i<k;++i)
    {if(b[i]==u)
	return 1;	
    }
  return 0;
}

void main()
{int i,n,k,j,v,ch,x,y;
  struct node *p,*t;
  printf("enter the no. of vertices : ");
  scanf("%d",&n);
  for(i=1;i<=n;++i)
    gptr[i]=NULL;
  for(i=1;i<=n;++i)
    {
      printf("enter how many vertices connected to vertix %d : ",i);
      scanf("%d",&k);
      for(j=1;j<=k;++j)
	{printf("enter its vertex no. : ");
	  scanf("%d",&v);
	  struct node *p=(struct node *)malloc(sizeof(struct node));
	  p->vertex=v;
	  p->link=NULL;
	  if(j==1)
	    {gptr[i]=p;
	      t=p;
	    }
	  else
	    {t->link=p;
	      t=p;
	    }
	}
    }
  do
    {printf("\t\tgraph menu\n1. depth first search\n2. breadth first search\n3. exit\nenter your choice : ");
      scanf("%d",&ch);
      switch(ch)
	{case 1:printf("enter the vertex from which traversal has to begin with : ");
	    scanf("%d",&x);
	    dfs(x);
	    for(i=0;i<m;++i)
	      printf("%d  ",b[i]);
	    printf("\n");
	    break;
	 case 2:printf("enter the vertex from which traversal has to begin with : ");
	    scanf("%d",&y);
	    bfs(y);
	    for(i=0;i<l;++i)
	      printf("%d  ",c[i]);
	    printf("\n");
	    break;
	 case 3:exit(0);
	 default:printf("enter correcr option\n");
	}
    }while(ch!=3);
}
