#include<stdio.h>
int n=0,A[20],size,B[20];
void insertion(int item)
{int i,p,temp;
  if(n>size)
    printf("Not possible");
  else
    {
      n++;
      A[n]=item;
      i=n;
      p=i/2;
      while(p>0&&A[p]<A[i])
	{
	  temp=A[i];
	  A[i]=A[p];
	  A[p]=temp;
	  i=p;
	  p=p/2;
	}
    }

}
void display()
{
  int i;
  for(i=1;i<=n;i++)
    printf("%d ",A[i]);
}
void swap(int a,int b)
{int temp;
  temp=B[a];
  B[a]=B[b];
  B[b]=temp;
}
void heapsort()
{
  int i=1,k=1,n1,f=0,rchild,lchild,x,y;
  for(i=1;i<=n;i++)
    B[i]=A[i];
  n1=n;
  while(n1>1)
    {  swap(1,n1);
  n1--;
  f=0;
  i=1;
  while(f==0&&i<n1)
    { lchild=2*i;
  rchild=2*i+1;
  if(lchild<=n1)
    x=B[lchild];
  else
  x=-100;
  if(rchild<=n1)
    y=B[rchild];
  else
    y=-100;
  if(B[i]>=x&&B[i]>=y)
    f=1;
else if(x>=y&&x>=B[i])
    {    swap(lchild,i);
      i=lchild;
    }  
  else if(y>x && y>=B[i])
    {
      swap(rchild,i);
      i=rchild;
}
    }
  printf("PASS %d:",k);
  for(i=1;i<=n;i++)
    printf("%d ",B[i]);
  printf("\n"); 
 k++;
    }}
main()

{int c,i,item;
  char y;
  printf("Enter size");
  scanf("%d",&size);  
  do{
    printf("MENU\n1.Insertion\n2.Disply Heap tree\n3.HEAP Sort");
    scanf("Enter chopice");
    scanf("%d",&c);
    switch(c)
      {
      case 1:
	printf("Enter items");

	for(i=0;i<size;i++)
	  {

	scanf("%d",&item);
	insertion(item);}
	break;
      case 2:display();
	break;
      case 3:heapsort();
	break;

      }
    printf("Do you want to continue?");
    __fpurge(stdin);
    scanf("%c",&y);
    

  }while(y=='y');
}
