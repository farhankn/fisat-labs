//PROGRAM TO IMPLEMENT SIMPLE CALCULATOR
#include<stdio.h>
void sum();
void subtract();
void product();
void divide();
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
	case 1 : sum();
	  break;
	case 2 : subtract();
	  break;
	case 3 : product();
	  break;
	case 4 : divide();
	  break;
	default : printf("\n\n\tWrong Choice");
	  break;
	}
    }
  while(choice!=5);

}

  void sum()
  {
    printf("\n\nSum is %d",a+b);
  }

  void subtract()
  {
    printf("\n\ndifference is %d",a-b);
  }

  void product()
  {
    printf("\n\nProduct is %d",a*b);
  }

  void divide()
  {
    printf("Quotient is %f and Remainder is %d",(float) a/b,a%b);
  }
