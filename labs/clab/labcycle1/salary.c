//TO CALCULATE DA, HRA, PF, GROSS PAY AND BONUS PAYMENT OF AN EMPLOYEE
#include<stdio.h>
main()
{
  int empcode;
  float basepay,overtime,absent,bonus,da,hra,pf,j,gross;
    //----------- Menu ---------------------------------
    
  printf("\n\n\t\t*- Employee Salary Calculator -*\n");
  printf("\nEnter Employee Code ");
  scanf("%f",&empcode);
  printf("\nEnter basic pay: ");
  scanf("%f",&basepay);
  printf("\nEnter overtime hours of work: ");
  scanf("%f",&overtime);
  printf("\nEnter days of absent ");
  scanf("%f",&absent);

  //-------- Pre Calculations ---------------------------

  da= 0.5 * basepay;
  hra = 200;
  pf = 0.2 * basepay;

  //-------- Bonus Pay Calculation-----------------------

  j = overtime - ((2/3) * absent);
  
  if(j>40)
    bonus = 5000;
  else if(j>30)
    bonus = 4000;
  else if(j>20)
    bonus = 3000;
  else if (j>10)
    bonus = 2000;
  else if(j==10)
    bonus = 1000;
  else
    bonus = 0;

  //-------- Gross Salary Calculation -------------------

  gross = da-pf+hra+bonus+basepay;

  //------- Display ------------------------------------

  printf("\n\n\n\t\t Employee Salary Details");
  printf("\n\t\t =======================");
  printf("\nEmployee code: %.0d",empcode);
  printf(" has a Basic pay: %.0f \t Overtime %.0f hours and \t %.0f days absent",basepay,overtime,absent);
  printf("\n\nSalary Details:");
  printf("\nDA = %.0f \nHRA = %.0f \nPF = %.0f \nBonus = %.0f",da,hra,pf,bonus);
  printf("\nTotal Salary is %.0f\n",gross);

}

//==============    END OF PROGRAM  ================
