#include<stdio.h>

int main(int argc, char const *argv[])
{
	int grid[100][100];
	int p,q,l,i,j;

	scanf("%d",&p);
	scanf("%d",&q);
	scanf("%d",&l);


	for (i = 0; i < p; i++)
		for (j = 0; j < q; j++)
		{
			grid[i][j]=0;		
		}


	for (i = 0; i < p; i++)
		for (j = 0; j < q; j++)
		{
			if((i>=l)||(j>=l))
				if ((i%l==0)||(j%l==0))
						{
							grid[i][j]=1;
						}		
		}
for (i = 0; i < p; i++)
{
			printf("\n");
		for (j = 0; j < q; j++)
			{
			printf(" %d ",grid[i][j]);
			}		
}
		




	return 0;
}