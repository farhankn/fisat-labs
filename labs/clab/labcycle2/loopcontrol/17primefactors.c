
//To display the prime factors of an entered number
#include<stdio.h>
main()
{
  int number,i,count;
  printf("Enter Number ");
  scanf("%d",&number);
  for(i=2 ; i<=(number/2); i++)
   {
     if(number%i==0)
       {
	 for(i=1; i<(number/2); ++i)
	   {
	     if((number%i==0))
	       count++;
	   }
	 if(count>1)
	   printf("\n %d ",number);
       } 
   }
  printf(" are the factors");
}
