
public class Problem1 {

private int modifiedMultipliedNumber(int num1, int num2, int k) {

int temp = 0;

if(num2 > 0) {
temp = (num1 - (2*k)) * num2;
} else {
temp = (num1 + (2*k)) * num2;
}

return temp;
}

private void doCalculation(int n, int k, int[] arr1, int[] arr2) {

int sum = 0;
int minDiff = 0;

for(int j = 0 ; j<n; j++) {
sum = arr1[j] * arr2[j] + sum;
}

minDiff = sum;
for(int i = 0; i < n; i++) {

int diff = modifiedMultipliedNumber(arr1[i], arr2[i], k) + sum - arr1[i] * arr2[i];

if(minDiff > diff) {
minDiff = diff;
}
}

System.out.println("Mimimum product difference" + minDiff);

}


public static void main(String[] args) {
Problem1 prob = new Problem1();

// Sample 1
int n = 3, k = 5;
int[] arr1 = {1,2,-3};
int[] arr2 = {-2,3,-5};

prob.doCalculation(n, k, arr1, arr2);

// Sample 2
n=5; k = 3;
arr1 = new int[]{2,3,4,5,4};
arr2 = new int[]{3,4,2,3,2};

prob.doCalculation(n, k, arr1, arr2);
}

}﻿