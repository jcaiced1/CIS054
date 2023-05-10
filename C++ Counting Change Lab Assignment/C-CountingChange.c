/*	C-CountingChange.c
Jose Caicedo
Date: 03/11/2023
CIS054 C/C++ Programming
Inputs: quarters, dimes, nickles, pennies
Outputs: sumTotal
*/

/*	1 - Project Definition

Write a program that counts change. The program
should ask for the number of quarters, the number of
dimes, the number of nickels and the number of
pennies. Then the program should tell the user how
much money there is, expressed in dollars.
You must use constants for the value of each coin type,
and display a title at the top of the screen when the
program first runs. 
*/

#include <stdio.h>	//	used for cin and cout

/*	define the constants */
#define VALUE_QUARTERS 0.25;	//	1 Quarter = $0.25
#define VALUE_DIMES 0.10;		//	1 Dime = $0.10
#define VALUE_NICKELS 0.05;	//	1 Nickel = $0.05
#define VALUE_PENNIES 0.01;	//	1 Penny = $0.01

int main(int argc, char *argv[]) 
{
	//	Declare the variables
	int quarters, dimes, nickels, pennies;					// values input from the keyboard
	double sumQuarters, sumDimes, sumNickels, sumPennies;	// sum of values with their respective monetary value
	double sumTotal;
	
	//Welcome message
	printf("Jose's coin counting program\n\n");
	
	// INPUT: quarters, dimes, nicles, pennies
	printf("How many quarters do you have? ");		//	prompt
	scanf("%d", &quarters);							//	read quarters from keyboard
	printf("How many dimes do you have? ");			//	prompt
	scanf("%d", &dimes);							//	read dimes from keyboard
	printf("How many nickels do you have? ");		//	prompt
	scanf("%d", &nickels);							//	read nickels from keyboard
	printf("How many pennies do you have? ");		//	prompt
	scanf("%d", &pennies);							//	read pennies from keyboard
	
	// PROCESS: transforms the integers into their respective monetary value, and add the total
	
	sumQuarters = quarters * VALUE_QUARTERS;
	sumDimes = dimes * VALUE_DIMES;
	sumNickels = nickels * VALUE_NICKELS;
	sumPennies = pennies * VALUE_PENNIES;
	
	sumTotal = sumQuarters + sumDimes + sumNickels + sumPennies; 
	
	// OUTPUT: display the total
	printf("\n");			// blank line before the output
	printf("Your total is $%.2lf\n", sumTotal);

	return 0;
}
