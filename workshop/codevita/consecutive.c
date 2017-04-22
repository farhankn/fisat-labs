#include<stdio.h>
int multiply(int,int,int);

int multiply(int n1, int n2, int k) {

    int t = 0;

    if(n2 > 0) {
    t = (n1 - (2*k)) * n2;
    } 
    else {
    t = (n1 + (2*k)) * n2;
    }

    return t;
    }


main() {
int n,k,i,a[100],b[100];
scanf("%d",&n);
scanf("%d",&k);

for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
}
for(i=0;i<n;i++) {
    scanf("%d",&b[i]);
}
    int sum = 0,j,diff;
    int min = 0;

    for(j=0;j<n;j++) {
    sum = (a[j] * b[j]) + sum;
    }

    min = sum;
    for(i = 0; i < n; i++) {

        diff = multiply(a[i], b[i], k) + sum - a[i] * b[i];

        if(min > diff) {
        min = diff;
        }
    }

printf("%d", min);
}


