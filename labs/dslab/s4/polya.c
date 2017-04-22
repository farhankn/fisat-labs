#include<stdio.h>
struct poly
{
  int exp;
  int coef;
}pol1[5],pol2[5],pol3[5];
int temp1=0,temp2=0,temp3=0;


  void add(int c1,int c2)
  {
    while(temp1<c1&&temp2<c2)
      {
      if (pol1[temp1].exp==pol2[temp2].exp)
	{	pol3[temp3].coef=pol1[temp1].coef+pol2[temp2].coef;
    pol3[temp3].exp=pol1[temp1].exp;
    temp3++;
    temp2++;
    temp1++;
      }
      else if(pol1[temp1].exp>pol2[temp2].exp)
	{
	pol3[temp3].exp=pol1[temp1].exp;
        pol3[temp3].coef=pol1[temp1].coef;
	temp3++;
	temp1++;
}
      else
	{
	  pol3[temp3].exp=pol2[temp2].exp;
	  pol3[temp3].coef=pol2[temp2].coef;
	  temp3++;
	  temp2++;
	}
      }
    while(temp1<c1)
      {
	pol3[temp3].exp=pol1[temp1].exp;
	pol3[temp3].coef=pol1[temp1].coef;
	temp3++;
	temp1++;
}
    while(temp2<c2)
      {
	pol3[temp3].exp=pol2[temp2].exp;
	pol3[temp3].coef=pol2[temp2].coef;
	temp3++;
	temp2++;
      }
}
void main()
{int o1,o2,i,e,c,k=0;
  printf("Enter the order of poly 1");
  scanf("%d",&o1);
 
for(i=0;i<o1;i++)
    {printf("Enter expo and cef");
      scanf("%d%d",&e,&c);
      
      pol1[i].exp=e;
      pol1[i].coef=c;
}
  printf("Enter the order of poly 2");
  scanf("%d",&o2);
for(i=0;i<o2;i++)
    {printf("Enter expo and cef");
      scanf("%d%d",&e,&c);
      
      pol2[i].exp=e;
      pol2[i].coef=c;
}
  add(o1,o2);
  printf("Sum of polynomials:\n");
  printf("Exponent and coefficent:\n");
  for(i=0;i<temp3;i++)
    {
      if(k<1){
printf("%dx^%d",pol3[i].coef,pol3[i].exp);
      k++;}
else
printf("+%dx^%d",pol3[i].coef,pol3[i].exp);
    }  printf("\n");
    

}
