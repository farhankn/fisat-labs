#include<stdlib.h>
#include<stdio.h>
struct poly{
  int exp,coef;
  struct poly *link;
}*start=NULL,*temp=NULL,*tempr=NULL,*startr=NULL;

void result(int,int); 
struct poly * createpoly()
{int n,i;
  start=NULL;
 printf("Enter how many terms");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
struct poly  *p = (struct poly *) malloc(sizeof(struct poly));
 printf("Enter exponent and coef value for term %d:",i+1);
 scanf("%d%d",&p->exp,&p->coef);
  p->link=NULL;

  if (start==NULL)
    {
      start=p;
      temp=p;
    }
 
  else {
    temp->link=p;
  temp=p;
  }
    }


  return start;
  }

void polyadd(struct poly *a,struct poly *b)
{int r;
struct poly  *p = (struct poly *) malloc(sizeof(struct poly));
struct poly  *q = (struct poly *) malloc(sizeof(struct poly));
 p=a;
 q=b;
 while(p!=NULL&&q!=NULL)
   {
     if(p->exp==q->exp)
       {
	 r=p->coef+q->coef;
	 result(p->exp,r);
	 q=q->link;
	 p=p->link;
       }
     else if(p->exp>q->exp)
       {
	 result(p->exp,p->coef);
	 p=p->link;
       }
     else
       {
	 result(q->exp,q->coef);
	 q=q->link;
       }
     
   }
 while(p!=NULL)
   { result(p->exp,p->coef);
	 p=p->link;
}
 while(q!=NULL)
   { result(q->exp,q->coef);
	 q=q->link;
}

}
void result(int r,int s)
{
struct poly  *p1 = (struct poly *) malloc(sizeof(struct poly));
 p1->exp=r;
 p1->coef=s;
 p1->link=NULL;
 if(startr==NULL)
 {
   startr=p1;
   tempr=p1;

 }
 else
   {
     tempr->link=p1;
     tempr=p1;
}



}

void display()
{int i=0;
  tempr=startr;
  while(tempr->link!=NULL)
    {if(i<1)
	{
      printf("%dx^%d",tempr->coef,tempr->exp);
      tempr=tempr->link;
      i++;
	}
      else
	{
	  if(tempr->coef>=0)
	    { printf("+%dx^%d",tempr->coef,tempr->exp);
	      tempr=tempr->link;
	}else
	    {
	       printf("%dx^%d",tempr->coef,tempr->exp);
	       tempr=tempr->link;
	    }
	  
}
      printf("\n");


}
if(tempr->coef>=0)
printf("+%dx^%d",tempr->coef,tempr->exp);
 else
printf("%dx^%d",tempr->coef,tempr->exp);

}
void main()
{char y;
  int c;

struct poly  *a = (struct poly *) malloc(sizeof(struct poly));
struct poly  *b = (struct poly *) malloc(sizeof(struct poly));
 a=createpoly();
 b=createpoly();
 polyadd(a,b);
 display();

}
