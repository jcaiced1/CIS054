//	C++SumAverageRange.cpp
//	CIS054 C/C++ Programming
//	Jose Caicedo
//	03/26/2023
//
//	Inputs: Enter 10 numbers
//	Outpus:	Sum of odd numbers, sum of even numbers, sum of all numbers
//			lowest and highest number

#include <iostream>
#include <iomanip>	//	used to set 2 digits past the decimal
#include <cmath>
using namespace std;

const int NUMBER_COUNT = 10;	// define a constant

int main(int argc, char *argv[]) 
{
	int sumOfOddNumbers = 0;	// integer hold only whole numbers
	int sumOfEvenNumbers = 0;
	int sumOfAllNumbers = 0;
	int minValue = 0;
	int maxValue = 0;
	int number;
	int inputCounter = 1;
	double total =0;
	double average = 0;
	
	// INPUT:	numbers
	while (inputCounter <= NUMBER_COUNT) //	count from 1 to NUMBER_COUNT
	{
		cout << "(" << inputCounter << ") Enter a number: ";
		
		/* cin.peek() != '\n' checks if the next character in the input stream is a newline character. If it is not, this means the user entered additional characters after the integer (such as a decimal point), which makes the input invalid. floor(number) != number checks if the extracted number is a whole number. If it is not, this means the user entered a decimal number, which is also invalid.*/
		while (!(cin >> number) || cin.peek() != '\n' || floor(number) != number || number < 0) { 
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input!! Enter a positive integer: ";
		}
		
		//determine if the number is odd or even
		if (number %2 ==1)	// odd number
		sumOfOddNumbers +=number;
		else
			sumOfEvenNumbers += number;
		
		// also add the total of all numbers
		sumOfAllNumbers += number;
		
		// determine the range (min, max) of the input values
		if (inputCounter ==1)	// reading the first value?
		{
			minValue = number;	// initialize minValue and maxValue
			maxValue = number;	// to the first value read from kbd
		}
		else			// not reading the first value 
		{
			if (number <minValue)	// see if minValue needs updating
			minValue =  number;	// -yes
			if(number > maxValue)	// see if maxValue needs updating
			maxValue = number;	// -yes
		}
		
		// keep count of how many numbers were entered
		inputCounter++;
		
	} // end of while loop
	total = sumOfAllNumbers;
	average = total / 10;
	;
	
	//OUTPUT: display the results
	cout << endl;	// blank line before the summary information
	cout << "Sum of Odd Numbers: " << sumOfOddNumbers << endl;
	cout << "Sum of Even Numbers: " << sumOfEvenNumbers << endl;
	cout << "Sum of All Numbers: " << sumOfAllNumbers << endl;
	cout<<setiosflags(ios::fixed | ios::showpoint);
	cout << "The Average is: " <<setprecision(2)<< average << endl;
	cout << "The lowest value is: " << minValue <<endl;
	cout << "The highest value is: " << maxValue <<endl;
	cout << endl;	//blank line at the end of program
	
	return 0;
}