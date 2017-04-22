#include<stdio.h>
int mul(int,int,int);
int mul(int num1, int num2, int k) {

 int t = 0;

if(num2 > 0) {
t = (num1 - (2*k)) * num2;
} 
else {
t = (num1 + (2*k)) * num2;
}
return t;
}



int main() {
int n,k,i,arraya[100],arrayb[100];
scanf("%d",&n);
scanf("%d",&k);

for(i=0;i<n;i++) {
    scanf("%d",&arraya[i]);
}
for(i=0;i<n;i++) {
    scanf("%d",&arrayb[i]);
}
    int sum = 0,j,diff,val = 0;

    for(j=0;j<n;j++) {
    sum = (arraya[j] * arrayb[j]) + sum;
    }

    val = sum;
    for(i = 0; i<n;i++) {

        diff = mul(arraya[i], arrayb[i], k) + sum - arraya[i] * arrayb[i];

        if(val > diff) {
        val = diff;
        }
    }
printf("%d", val);
return 0;
}



