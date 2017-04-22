// polynomial addition
#include<stdio.h>

struct polynomial
{
  int exp,coeff;
}poly1[10],poly2[10],poly3[10];


main()
{
  int i,temp1=0,temp2=0,temp3=0,count1,count2,count3;


  //READ POLYNOMIALS
  printf("\nEnter the no of terms in Poly1: ");
  scanf("%d",&count1);
  
  printf("\nEnter the elements\n");
  for(i=count1;i>=0;i--)
    {
      printf("Enter the coefficient for degree%d: ",i);
      scanf("%d",&poly1[i].coeff);
      poly1[i].exp=i;
    }
  
  printf("\n\nEnter the no of terms in Poly2: ");
  scanf("%d",&count2);

  printf("\nEnter the elements\n");
  for(i=count2;i>=0;i--)
    {
      printf("Enter the coefficient for degree%d: ",i);
      scanf("%d",&poly2[i].coeff);
      poly2[i].exp=i;
    }
 

  //BEGIN ADDITION
  while(temp1<=count1 && temp2<=count2)
    {
      if(poly1[temp1].exp>poly2[temp2].exp)
	{
	  poly3[temp3].exp=poly1[temp1].exp;
	  poly3[temp3].coeff=poly1[temp1].coeff;
	  temp3++;
	  temp1++;
	}
      else if(poly1[temp1].exp<poly2[temp2].exp)
	{
	  poly3[temp3].exp=poly2[temp2].exp;
	  poly3[temp3].coeff=poly2[temp2].coeff;
	  temp3++;
	  temp2++;
	}
      else 
	{
	  poly3[temp3].exp=poly1[temp1].exp;
	  poly3[temp3].coeff=poly1[temp1].coeff+poly2[temp2].coeff;
	  temp3++;
	  temp2++;
	  temp1++;
	}
    }

  while(temp1<=count1)
    {
      poly3[temp3].exp=poly1[temp1].exp;
      poly3[temp3].coeff=poly1[temp1].coeff;
      temp3++;
      temp1++;
    }

  while(temp2<=count2)
    {
      poly3[temp3].exp=poly2[temp2].exp;
      poly3[temp3].coeff=poly2[temp2].coeff;
      temp3++;
      temp2++;
    }

  printf("\nThe Entered Polynomials:\n");
  printf("\nPolynomial1\n");
  for(i=count1;i>=0;i--)
    {
      printf("%dx^%d",poly1[i].coeff,poly1[i].exp);
      if((i+1)!=1)
	printf(" + ");
      else
	printf(" =0\n");
    }
  
  printf("\nPolynomial2\n");
  for(i=count2;i>=0;i--)
    {
      printf("%dx^%d",poly2[i].coeff,poly2[i].exp);
      if((i+1)!=1)
	printf(" + ");
      else
	printf(" =0\n");
    }

  printf("\nPolynomial After addition is\n");
  for(i=temp3-1;i>=0;i--)
    {
      printf("%dx^%d",poly3[i].coeff,poly3[i].exp);
      if((i+1)!=1)
	printf(" + ");
      else
	printf(" =0\n");
    }
}
