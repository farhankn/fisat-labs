//PROGRAM TO IMPLEMENT SIMPLE CALCULATOR
#include<stdio.h>
int sum();
int subtract();
int product();
int divide();
int a,b;

main()
{
  int choice;
  do
    {
      printf("| Simple Calculator |");
      printf("\nMenu....");
      printf("\n 1. Add \n2.Subtract \n3.Multiply \n4.Divide \n5.Exit \nEnter a choice \n\n");
      scanf("%d",&choice);
      
      if(choice==5)
	continue;

      printf("Enter two numbers");
      scanf("%d %d",&a,&b);

      switch(choice)
	{
	case 1 : printf("%d\n",sum());
	  break;
	case 2 : printf("%d\n",subtract());
	  break;
	case 3 : printf("%d\n",product());
	  break;
	case 4 : printf("%d\n",divide());
	  break;
	default : printf("\n\n\tWrong Choice");
	  break;
	}
    }
  while(choice!=5);

}

  int sum()
  {
    return a+b;
  }

  int subtract()
  {
    return a-b;
  }

  int product()
  {
    return a*b;
  }

  int divide()
  {
    return a/b;
  }
