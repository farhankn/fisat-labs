
#include<stdio.h>

main()
{
 float c,f;
 printf("\n Program to Convert Fahrenheit to Celsius");
 printf("\nEnter the temperature in Fahrenheit: ");
 scanf("%f",&f);
 c=(f-32)*5/9;
 printf("\nTemperature in Celsius is %f \n", c);
}
