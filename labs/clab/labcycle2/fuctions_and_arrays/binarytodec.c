#include<stdio.h>
#include<math.h>
int decimal(int a);
int binary(int a);
main()
{
  int choice,number;
  do
    {
      printf("\n::Menu::\n1.Binary to Decimal\n2.Decimal to Binary\n3.Exit");
      scanf("%d",&choice);
      if(choice==3)
	continue;

      if(choice==2)
	{
	  printf("Enter the Decimal number");
	  scanf("%d",&number);
	  binary(number);
	}
      else
	{
	  printf("Enter the Binary number");
	  scanf("%d",&number);
	  decimal(number);
	}
    }
  while(choice!=3);
}
  int binary(int a)
  {
    while(a!=0)
      {
	printf("%d",a%2);
	a/2;
return 0;
      }
  }

  int decimal(int a)
  {
    int rem,power=0,sum=0;
    while(a!=0)
      {
	rem = a%10;
	a = a/10;
	sum = sum + rem * pow(2,power);
	power++;
      }
    printf("%d",sum);
    return 0;
  }
