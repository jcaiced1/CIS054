//	C++TelephoneCall.cpp
//	CIS054 C/C++ Programming
//	Jose Caicedo
//	04/16/2023
//	Version 1
//
//	Inputs: day1, day2, hour, minute, LengthOfCall, again
//	Outpus:	CostOfCall

#include <iostream>	// used for cin and cout
#include <iomanip>	//	used to set 2 digits past the decimal
#include <cstring>	// used for toupper()
using namespace std;

int main(int argc, char *argv[]) 
{
	// list of variables and constants
	const double WEEKEND_RATE = 0.15;	//	$0.15 / minute
	const double EVENING_RATE = 0.25;	//	$0.25 / minute
	const double DAY_RATE = 0.40;		//	$0.40 / minute
	char day1;			//	first character of DayOfWeek
	char day2;			//	second character of DayOfWeek
	int hour;			//	Start time: hour input by the user
	char separator;		//	Start time: between hour and minutes
	int minute;			//	Start time: minutes input by the user
	int LengthOfCall;	//	Length of call in minutes
	
	//	used internally by the program
	char again;			//	loop control
	int TimeStarted;	//	time in 24-hour clock, 6:00pm=1800
	double billingRate;	//	determined by day and time of call
	double CostOfCall;	//	computed and displayed
	
	do
	{
		//	input the day of week
		cout << "Enter the day (Mo Tu We Th Fr Sa Su): ";
		cin >> day1 >> day2;	//	input two characters
		day1 = toupper(day1);	//	convert to uppercase
		day2 = toupper(day2);
		
		// input the time the call was started
		cout << "Enter the time started (ex: 14:35): ";
		cin >> hour >> separator >> minute; // input time
		TimeStarted = hour*100 + minute;
		
		//	input the length of the call
		cout << "Enter the length of the call in minutes: ";
		cin >> LengthOfCall;
		
		//	process - determine billingRate, then CostOfCall
		if (day1=='S' && day2=='A')		//	test for SA (Saturday)
			billingRate = WEEKEND_RATE;
		else if (day1=='s' && day2=='U')	//	test for SU (Sunday)
			billingRate = WEEKEND_RATE;
		else	// if not Saturday or Sunday, assume weekday
		{
			if (TimeStarted >= 800 && TimeStarted <= 1800)
				billingRate = DAY_RATE;
			else
				billingRate = EVENING_RATE;
		}
		CostOfCall = LengthOfCall * billingRate;
		
		// output -- You do the output
		cout<<setiosflags(ios::fixed | ios::showpoint);
		cout<< "The cost of the call is : $"<<setprecision(2)<<CostOfCall<<endl;
		
		// loop control
		cout << "Another call (Y/N)? ";
		cin >> again;
		again = toupper(again);
	} while (again == 'Y');
	return 0;
}	// end of main