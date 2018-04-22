/*---------------------------------------------------------
* Name: Atone Joryman
* Date: 2/17/2016
* Program: TenDollarBills.c
* Description: This program will receive a user requested
*  amount to get money in increments of ten dollars.
* --------------------------------------------------------*/
#include <stdio.h>//call library to do simple calls


int amount, fifty,twenty,ten; //declarations to set up money

void main() // function that will not return a number
{
    //display instruction
printf ("How many ten dollar bills will you deposit?\n ");
scanf("%d",&amount); //get tje amount

//if that received amount is divisible by 10 and is a number greater than ten
if(((amount%10)==0) && (amount>0)){
//statement for a fifty dollar bill
 if(amount>=50)
 {
printf ("You will get:\n"); //start showing the result to monitor
 fifty = amount/50;
 amount = amount%50;
 printf ("%d fifty dollar bill(s).\n",fifty); //display result
 }
//statement for twenty dollar bill
 if((amount>=20) && (amount<50))
 {

 twenty = amount/20;
amount = amount%20;
 printf ("%d twenty dollar bill(s).\n",twenty); //display result

 }
//statement for a ten dollar bill
 if(amount==10)
 {

 ten = 1; //automatically make a single ten dollar bill
 amount= amount%10;
 printf ("%d ten dollar bill(s).\n",ten); //display result
 }

}

else //for incorrect amount asked of atm
{
printf ("Bill must be in a multiple of ten(10).");

}
}

