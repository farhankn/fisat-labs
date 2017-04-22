
#include<iostream.h>
int main()
{
 unsigned long int n,sum;
 cin >> n;
 sum=prime(n);
 count<<sum
 return 0;
}
 
int prime(unsigned long int n) {

 unsigned long int sum = 0,i;
 int count=0;  
for (i = 0; i <n; i++) {
     
     
   if (isPrime(i)) {
     sum += i;
     if(sum<n&&sum>2)
{
 if(isPrime(sum))
   {
     count++;
   }
}
   }
 }
 return count;
   
}



int isPrime(unsigned long int num) {
 unsigned long int i;

 
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