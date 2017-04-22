#include <stdio.h>
int main()
{
 
    int i, j, a, n,p,q,number1[30],number2[30],x,sum,k,c[30][30],d[30],temp;
    scanf("%d", &n);
    scanf("%d",&k);
    k = 2 * k;
    for (i = 0; i < n; ++i)
        scanf("%d", &number1[i]);
    for (p = 0; p < n; ++p)
        scanf("%d", &number2[p]);


    for (i = 0; i < n; ++i)
    {
    if (number1[i]<0)
    {
    		number1[i]=number1[i]+k;
    }
    else if (number1[i]>0)
	{	
    			number1[i]=number1[i]-k;
    }
	for(x=0;x<n;x++)
    	{
        c[i][x]=c[i][x]+(number1[x]*number2[x]);   
    	}
	if (number1[i]<0)
    {
    		number1[i]=number1[i]-k;
    }
    else if (number1[i]>0)
	{
			number1[i]=number1[i]+k;
    } 	
    }
// for(i=0;i<n;i++)
// {
// 	printf("\n");
//     for(x=0;x<n;x++)
//     {
//         printf("%d\t", c[i][x]);   
//     }
//  }   

for(i=0;i<n;i++)
 {
	d[i] = 0;	
 }

temp = 0;


for(i=0;i<n;i++)
 {
	for(x=0;x<n;x++)
	{
		temp = temp + c[i][x];
	}
	d[i] = temp;
	temp = 0;
 }

// for(i=0;i<n;i++)
//  {
// 	printf("%d\n",d[i]);
//  }


for(i=0;i<n;i++)
{
 for (j = 0; j < n-i-1 ;++j)
 {
 	if (d[j] > d[j+1])
            {
                a =  d[j];
                d[j] = d[j+1];
                d[j+1] = a;
        } 
 }

}
temp = d[0];
printf("%d\n", temp);
}




























/*

    for (i = 0; i < n; ++i)
    {
      for (j = 0; j < n-i-1 ;++j)
        {
            if (number1[j] > number1[j+1])
            {
                a =  number1[j];
                number1[j] = number1[j+1];
                number1[j+1] = a;
        }    }
    }
 
    
    for (i = 0; i < n; ++i)
    {
      for (j = 0; j < n-i-1 ;++j)
        {
            if (number2[j] < number2[j+1])
            {
                a =  number2[j];
                number2[j] = number2[j+1];
                number2[j+1] = a;
        }    }
    }
  */