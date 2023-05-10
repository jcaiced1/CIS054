/*	C++CountingChange.cpp
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

#include <iostream>	//	used for cin and cout
#include <iomanip>	//	used to set 2 digits past the decimal
using namespace std;

/*	define the constants */
const double VALUE_QUARTERS = 0.25;	//	1 Quarter = $0.25
const double VALUE_DIMES = 0.10;		//	1 Dime = $0.10
const double VALUE_NICKELS = 0.05;	//	1 Nickel = $0.05
const double VALUE_PENNIES = 0.01;	//	1 Penny = $0.01

int main(int argc, char *argv[]) 
{
	//	Declare the variables
	int quarters, dimes, nickels, pennies;					// values input from the keyboard
	double sumQuarters, sumDimes, sumNickels, sumPennies;	// sum of values with their respective monetary value
	double sumTotal;
	
	//Welcome message
	cout<< "Jose's coin counting program\n"<<endl;
	
	// INPUT: quarters, dimes, nicles, pennies
	cout << "How many quarters do you have? ";		//	prompt
	while (!(cin >> quarters)) {
		cin.clear(); // clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
		cout << "Invalid input. How many quarters do you have? ";
	}
	//cin >> quarters;
	cout << "How many dimes do you have? ";			//	prompt
	cin >> dimes;									//	read dimes from keyboard
	cout << "How many nickels do you have? ";		//	prompt
	cin >> nickels;									//	read nickels from keyboard
	cout << "How many pennies do you have? ";		//	prompt
	cin >> pennies;									//	read pennies from keyboard

	// PROCESS: transforms the integers into their respective monetary value, and add the total
	
	sumQuarters = quarters * VALUE_QUARTERS;
	sumDimes = dimes * VALUE_DIMES;
	sumNickels = nickels * VALUE_NICKELS;
	sumPennies = pennies * VALUE_PENNIES;
	
	sumTotal = sumQuarters + sumDimes + sumNickels + sumPennies; 
	
	// OUTPUT: display the total
	cout << endl;			// blank line before the output
	cout<<setiosflags(ios::fixed | ios::showpoint);
	cout<<"Your total is $"<<setprecision(2)<<sumTotal<<endl;

	return 0;
}
