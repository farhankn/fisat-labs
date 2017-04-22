#include<stdio.h>




struct team
{
	char name[10];
}teams[20];
int main(int argc, char const *argv[])
{
	int n,i;
	scanf("%d",&n);
	for (i = 0; i < n; ++i)
	{
		scanf("%s",&teams[i].name);
	}
	



	for (i = 0; i < n; ++i)
	{
		printf("%s\n",teams[i].name);
	}

}