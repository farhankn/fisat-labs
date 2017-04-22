#include<stdio.h>

int main(int argc, char const *argv[])
{
	
	int a[10],b[10],c[10],n,k,i,j;
	int solution[2],sum;

	solution[0]=solution[1]=0;
	scanf("%d",&n);
	scanf("%d",&k);
	for (i = 0; i < n; ++i)
	{
	scanf("%d",&a[i]);	
	}
	for (i = 0; i < n; ++i)
	{
	scanf("%d",&b[i]);
	}


	//Possible Combination Trying
	k = 2*k;

	for (i = 0; i < n; ++i)
	{
	a[i]+=k;
	for (j = 0; j < n; ++j)
	{
	sum+=(a[j]*b[j]);

	}
	printf("%d %d\n",i,sum);
	if (sum>solution[0])
	{
		solution[0]=sum;
		solution[i]=i;
	}
	a[i]-=k;
	sum=0;
	}



/*

	for (i = 0; i < n; ++i)
	{
	printf(" %d ",c[i]);
	}
*/

	return 0;
}