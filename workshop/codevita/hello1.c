#include<stdio.h>
int main()
{
int n,k,i,a[100],b[100],temp;
int num1,num2;
scanf("%d",&n);
scanf("%d",&k);

for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
}
for(i=0;i<n;i++) {
    scanf("%d",&b[i]);
}
    int sum = 0,j,diff;
    int value = 0;

    for(j=0;j<n;j++) {
    sum = (a[j] * b[j]) + sum;
    }

    value = sum;
    for(i = 0; i < n; i++) {


    temp=0;

    if(num2 > 0) 
    {
    temp = (num1-(2*k))*num2;
    } 
    else 
    {
    temp = (num1+(2*k))*num2;
    }

        diff = temp + sum - a[i] * b[i];

        if(value > diff) {
        value = diff;
        }
    }

printf("%d", value);

return 0;
}





