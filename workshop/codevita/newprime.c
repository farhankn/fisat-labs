
#include<stdio.h>
int main()
{
 unsigned long int n;
 scanf("%ld",&n);




 unsigned long int sum = 0,i;
 int count=0;  
 for (i = 0; i <n; i++) {
  
  
  if (isvalid(i)) {
     sum += i;
     if(sum<n&&sum>2)
       {
  if(isvalid(sum))
   {
     count++;
   }
      }
   }
 }
 return count;





 printf("%ld\n",count);
 return 0;
}
 


int isvalid(unsigned long int primenum) {
  long int i;

 
 if (primenum < 2) {
   return 0;
 }
   
 for (i = 2; i < primenum; i++) 
 {
   if (primenum % i == 0) {
     return 0;
   }
 }
 return 1;
}
