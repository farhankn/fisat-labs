vf// Binary <--> Decimal || Hex <-->  Decimal CONVERSION 
#include<stdio.h>
#include<math.h>

//Function Decleration
int bintodec(int b);
void dectobin(int d);
void bintohex(int n);
long int  hextobin(char hex[]);

//Main Function
main()
{
  int ch,e,n,b,d;
  char c,hex[20];
 do
   {
      printf("\n\t\tConversion Program\nMenu:\n\n\n1.Binary to decimal\n2.Decimal to binary\n3.Binary to Hexadecimal\n4.Hexadecimal to Binary\n5.Exit\nEnter your option:  ");
      scanf("%d",&ch);
      switch(ch)   
	{
	case 1:
          printf("\nEnter a binary number:");
          scanf("%d",&b);
	  e=bintodec(b);
	  printf("\nThe decimal number is : %d\n",e);
          break;
        case 2:
          printf("\nEnter the decimal value of the number: ");
          scanf("%d",&d);
          
          dectobin(d);
          break;
	case 3:
	  printf("\nEnter a binary number :");
	  scanf("%d",&n);
	  bintohex(n);
          break;
        case 4:
	  printf("\nEnter  a hexadecimal number :");
	  scanf("%s",hex);
	  printf("\nThe binary is : %ld\n",hextobin(hex)); 
	  break;
	case 5:
          printf("\nExiting!!!");
	  exit(0);
        default:
          printf("\nInvalid Choice!!!");
	}
      printf("\nDo you wish to continue...?(y/n)");
      scanf("%s",&c);
    }while(c=='y');
}


void bintohex(int n)
{
  int i,l,d,r,j;
  char temp[20],hex[20];
  d=bintodec(n);
  for(i=0;d>0;i++)
    {
      r=d%16;
      if(r>9)
	{
      switch(r)
	{
	case 10:
	  hex[i]='A';
	  break;
	case 11:
	  hex[i]='B';
	  break;
	case 12:
	  hex[i]='C';
	  break;
	case 13:
	  hex[i]='D';
	  break;
	case 14:
	  hex[i]='E';
	  break;
	case 15:
	  hex[i]='F';
	  break;
	}
	}
      else
	hex[i]=r+48;
      d=d/16;
    }
  hex[i]='\0';
  l=i-1;
  for(j=0;j<i;j++,l--)
    {
      temp[j]=hex[l];
    }
  temp[j]='\0';
  printf("\nThe hexadecimal number is : %s\n",temp);
}




long int hextobin(char hex[20])
{
  long int i,l,d=0,b=0;
  for(l=0;hex[l]!='\0';l++);
	l=l-1;
  for(i=0;l>=0;i++,l--)
    {
      if(hex[l]>='0' && hex[l]<='9')
	d=d+(hex[l]-'0')*(pow(16,i));
      if(hex[l]>='A' && hex[l]<='F')
	d=d+(hex[l]-55)*(pow(16,i));
      if(hex[l]>='a' && hex[l]<='f')
	d=d+(hex[l]-87)*(pow(16,i));
    }
	
  i=1;
  while(d>0)
    {
      b=b+(d%2)*i;
      d=d/2;
      i=i*10;
    }
  return b;

}



int bintodec(int b)
{
  int rem,sum=0,power=0;
  
  while(b>0)
    {
      rem=b%10;
      sum=sum+rem*pow(2,power);
      power++;
      b=b/10;
    }
  return sum;
}




void dectobin(int d)
{
  int count=0,i,rev=0,rem,quo,rev1=0;
  for(;d>0;)
    { 
      rem=d%2;
      rev=(rev*10)+rem;
      if(rev==0)
	count++;
      d=d/2;
    }

  for(;rev>0;)
    {
      rem=rev%10;
      rev1=(rev1*10)+rem;
      rev=rev/10;
    }
  printf("\nThe binary number is:"); 
  printf("%d",rev1);
 
 for(i=0;i<count;i++)
    printf("0");
  printf("\n");
}
