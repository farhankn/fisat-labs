#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *rchild;
  struct node *lchild;
}*root=NULL,*ptr=NULL,*parent=NULL;
void inorder(struct node *a)
{  struct node *ptr=(struct node *) malloc(sizeof(struct node));
  ptr=a;
  if(ptr!=NULL)
    {  inorder(ptr->lchild);
      printf("%d ",ptr->data);
  inorder(ptr->rchild);


}}
void preorder(struct node *a)
{  struct node *ptr=(struct node *) malloc(sizeof(struct node));
  ptr=a;
  if(ptr!=NULL)
    {  printf("%d ",ptr->data);
  preorder(ptr->lchild);
  preorder(ptr->rchild);

}}
void postorder(struct node *a)
{  struct node *ptr=(struct node *) malloc(sizeof(struct node));
  ptr=a;
  if(ptr!=NULL)
    {   postorder(ptr->lchild);
  postorder(ptr->rchild);
  printf("%d ",ptr->data);
    }}
void insertion(int item)
{
  struct node *p=(struct node *) malloc(sizeof(struct node));
  p->data=item;
  p->rchild=NULL;
  p->lchild=NULL;
  if(root==NULL)
    root=p;
  else
    {
      ptr=root;
      while(ptr!=NULL)
	{
	  parent=ptr;
	  if(ptr->data>item)
	    ptr=ptr->lchild;
	  else
	    ptr=ptr->rchild;
	  
	}
      if(parent->data>item)
	parent->lchild=p;
      else
	parent->rchild=p;

    }  }
/*
struct node * succ(struct node *b)
{
struct node *ptr1=(struct node *) malloc(sizeof(struct node));
 ptr1=b->rchild;
 if(ptr1!=NULL)
   while(ptr1!=NULL)
     ptr1=ptr1->lchild;

 return(ptr1);
 }*/
void deletion(int item)
{int f=0,a;
 struct node *ptr=(struct node *) malloc(sizeof(struct node));
 struct node *parent=(struct node *) malloc(sizeof(struct node));
 ptr=root;
 while((ptr!=NULL)&&(f==0))
      {
	if(ptr->data>item)
	  { parent=ptr;
	    ptr=ptr->lchild;}
	else if(ptr->data==item)
	  f =1;
	else if(ptr->data<item)
	  {parent=ptr;
	  ptr=ptr->rchild;
	  }}
    if(f==0)
      printf("Item does not exist\n");
	     else 
	       {
		 if((ptr->lchild==NULL)&&(ptr->rchild==NULL))
                  {
                       if(parent->data<ptr->data)
	                parent->rchild=NULL;
                  	else
	                parent->lchild=NULL;
	
                       }
		 else if((ptr->lchild!=NULL)&&(ptr->rchild!=NULL))
		    {
		      struct node *ptr1=(struct node *) malloc(sizeof(struct node));
		      struct node *ptr2=(struct node *)  malloc(sizeof(struct node));
		      ptr1=ptr->rchild;
		      if(ptr1!=NULL)
			while(ptr1->lchild!=NULL)
			  ptr1=ptr1->lchild;
		      ptr2=ptr1;
		      a=ptr2->data;
		      deletion(a);
		      ptr->data=a;
		    }
		  else
		    {
		      if(parent->data<ptr->data)
			{if(ptr->lchild==NULL)
			  parent->rchild=ptr->rchild;
			else
			  parent->rchild=ptr->lchild;
			}
		      else if(parent->data>ptr->data)
			{
			 if(ptr->rchild==NULL)
			  parent->lchild=ptr->lchild;
			 else
			  parent->lchild=ptr->rchild;
			}}
	       }
}




  void search(int item)
  {    int f=0;
    ptr=root;
    while((ptr!=NULL)&&(f==0))
      {
	if(ptr->data>item)
	  ptr=ptr->lchild;
	else if(ptr->data==item)
	  f =1;
	else if(ptr->data<item)
	  ptr=ptr->rchild;
}
    if(f==1)
      printf("Item found\n");
	     else 
	       printf("item not found\n");

}
void main()
{char y;
  int ch,item;
  do{
    printf("MENU\n1.Insertion\n2.Search\n3.Deletion\n4.Inoder\n5.Preorder\n6.Postorder");
    printf("Enter choice");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:printf("Enter item");
      scanf("%d",&item);
      insertion(item);
      break;
    case 2:printf("Enter item to search");
      scanf("%d",&item);
      search(item);
      break;
    case 3:printf("Enter item to delete");
      scanf("%d",&item);
deletion(item);
      break;
    case 4:inorder(root);
      break;
    case 5:preorder(root);
      break;
      case 6:postorder(root);
      break;
    }
  printf("\nDo you want to continue?");
  __fpurge(stdin);
  scanf("%c",&y);
  } while(y=='y');
}
