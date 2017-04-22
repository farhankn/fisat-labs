
#include<stdio.h>
int main()
{
 unsigned long int n,sum;
 scanf("%ld",&n);
 sum=valid(n);
 printf("%ld\n",sum);
 return 0;
}
 
int valid(unsigned long int n) {

 unsigned long int sum = 0,i;
 int count=0;  
for (i = 0; i <n; i++) {
     
     
   if (isvalid(i)) {
     sum += i;
     if(sum<n&&sum>2)
      
 if(isvalid(sum))
   {
     count++;
   }

   }
 }
 return count;
   
}



int isvalid(unsigned long int num) {
 long int i;

 
 if (num < 2) {
   return 0;
 }
   
 for (i = 2; i < num; ++i) {
   if (num % i == 0) {
     return 0;
   }
 }
 return 1;
}