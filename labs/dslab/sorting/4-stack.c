//Menudriven program for stack operations
#include<stdio.h>
main()
{
  int s[5],j,i,e,k,top=-1;
do
  {
    printf("\nStack Operations\n.......\n");
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n\nEnter your choice\n");
    scanf("%d",&i);
    switch(i)
      {
      case 1 :if(top>4)
		printf("\nStack overflow!!\n");
	      else
		{
		  top=top+1;
		  printf("Enter the element\n");
		  scanf("%d",&j);
		  s[top]=j;
		}
	      break;
      case 2:if(top<0)
		printf("\nStack underflow\n");
	      else
		{
	          e=s[top];
		  top--;
		  printf("The Element deleted is %d",e);
		}
              break;
      case 3 :if(top<0)
		printf("No elements to be displayed\n");
	      else
		{
		  printf("\nElements in the stack are ");
		  k=0;
		  while(k<=top)
		    {
		      printf(" %d ",s[k]);
		      k++;
		    }
		}
      case 4 :break;
      case 5 :printf("\nPlease enter a valid choice\n");
	break;
      }
  }while(i!=4);
}




  
