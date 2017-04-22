//Program to add two dynamically implemented polynomials.
#include<stdio.h>
#include<stdlib.h>

struct poly
{
  int c,e;
  struct poly *next;
}*startr=NULL,*tailr=NULL;
void display(struct poly *x);
void result(int coef,int exp);
void polyadd(struct poly *a,struct poly *b);
struct poly* createpoly();
void main()
{
  struct poly *a,*b;
  a=createpoly();
  printf("The first polynomial is as follows:\n");
  display(a);
  b=createpoly();
  printf("The second polynomial is as follows:\n");
  display(b);
  polyadd(a,b);
  printf("The sum is as follows:\n");
  display(startr);
}

//Function to create a polynomial.
struct poly* createpoly()
{
  int n,i=0;
  struct poly *start,*tail,*p;
  start=NULL;
  tail=NULL;
  printf("Enter the number of terms:");
  scanf("%d",&n);
  while(i<n)
    {
      p=(struct poly*)malloc(sizeof(struct poly));
      printf("Enter the power of term %d:",i+1);
      scanf("%d",&p->e);
      printf("Enter the coefficient of X^%d:",p->e);
      scanf("%d",&p->c);
      p->next=NULL;
      if(start==NULL)
	{
	  start=p;
	  tail=p;
	}
      else
	{
	  tail->next=p;
	  tail=p;
	}
      i++;
    }
  return start;
}

//Function to add polynomials.
void polyadd(struct poly *a,struct poly *b)
{
  int s;
  struct poly *p,*q;
  p=a;
  q=b;
  while((p!=NULL)&&(q!=NULL))
    {
      if(p->e==q->e)
	{
	  s=p->c+q->c;
	  result(s,p->e);
	  p=p->next;
	  q=q->next;
	}
      else if(p->e>q->e)
	{
	  result(p->c,p->e);
	  p=p->next;
	}
      else
	{
	  result(q->c,q->e);
	  q=q->next;
	}
    }
  while(p!=NULL)
    {
      result(p->c,p->e);
      p=p->next;
    }
  while(q!=NULL)
    {
      result(q->c,q->e);
	  q=q->next;
    }
}
//Function to create result.
void result(int coef,int exp)
{
  struct poly *r;
  r=(struct poly*)malloc(sizeof(struct poly));
  r->c=coef;
  r->e=exp;
  r->next=NULL;
  if(startr==NULL)
    {
      startr=r;
      tailr=r;
    }
  else
    {
      tailr->next=r;
      tailr=r;
    }
 
}

//Function to display.
void display(struct poly *x)
{
  struct poly *temp,*start;
  start=x;
  if(start==NULL)
    printf("\nThe polynomial is empty.");
  else
    {
      temp=start;
      while(temp!=NULL)
	{
	  printf("%dX^%d",temp->c,temp->e);
	  temp=temp->next;
	  if(temp!=NULL)
	    printf("+");
	  else
	    printf("=0\n");
	}
    }
}
