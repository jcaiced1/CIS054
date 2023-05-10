/*	C-Paycheck.cpp
Jose Caicedo
Date: 03/05/2023
CIS054 C/C++ Programming
Inputs: name, hours, PayRate
Outputs: grossPay, taxes, netPay
*/

/*	1 - Project Definition

Create a program using C or C++ that does the following:
Read the employee name, number of hours worked and pay rate from the keyboard
Separate the nomber of hours entered into:
Regular hours, which are less than or equal to 40, and
Overtime hours, of anything over 40.
Compute the pay for the regular hours.
Compute the pay for the overtime hours at time-and-a-half.
Compute gross pay which is pay for regular hours + overtime pay.
Compute the taxes and net pay
Display employee name, gross pay, taxes and net pay.
*/

#include <iostream>	//	used for cin and cout
#include <iomanip>	//	used to set 2 digits past the decimal
using namespace std;

/*	define the constants */
const double OVERTIME_RATE = 1.5;	/* time and a half for overtime */
const double TAX_RATE = 0.14;		/* 0.14 is 14% */

int main(int argc, char *argv[]) 
{
	//	Declare the variables
	char name[100];
	double hours, payRate;				//	values input from the keyboard
	double regHours, overtimeHours;		//	the rest of the values are computed
	double regPay, overtimePay;
	double grossPay, taxes, netPay;
	
	// INPUT: your name, hours and payRate
	cout << "Enter your name: ";		//	prompt
	cin.getline(name, 100);				//	read up to 100 characters
	// INPUT hours and payRate
	cout << "Enter the hours worked: ";	//	prompot
	cin >> hours;						// read hours from keyboard
	cout << "Enter the pay rate: ";		//prompt
	cin >> payRate;
	
	// PROCESS: compute the paycheck
	// separate the regular and overtime hours
	if(hours<=40.0)				// less or equal to 40. No overtime
	{
		regHours = hours;		// separate regHours and overtimeHours
		overtimeHours = 0.0;
	}
	else	// hours are over 40. Compute how many are overtime?
	{
		regHours = 40.0;				//	regular pay of the first 40 hours
		overtimeHours = hours - 40.0;	// anything over 40 hours
	}

	regPay = regHours * payRate;
	overtimePay = overtimeHours * payRate * OVERTIME_RATE;
	grossPay = regPay + overtimePay;
	taxes = grossPay * TAX_RATE;
	netPay = grossPay - taxes;
	
	// OUTPUT: welcome message, and paycheck with two digits past the decimal
	cout<<endl<<"Paycheck for "<<name<<endl;
	cout<<setiosflags(ios::fixed | ios::showpoint);
	cout<<"Your gross pay is $"<<setprecision(2)<<grossPay<<endl;
	cout<<"Your taxes are $"<<setprecision(2)<<taxes<<endl;
	cout<<"Your net pay is $"<<setprecision(2)<<netPay<<endl;
	
	return 0;
}
