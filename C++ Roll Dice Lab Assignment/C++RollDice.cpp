// Program Name: C++RollDice.cpp
// Programmer:   Jose Caicedo
// Class:        CIS054 C/C++ Programming
// Date:         04/23/2023
// Version:      1.0

#include <iostream> // needed for cin and cout
#include <cstdlib>  // needed by srand() and srand()
#include <ctime>    // needed for the time() function
int roll();
int rollDice();
using namespace std;

int main(int argc, char *argv[]) {
	srand(time(0)); // Seed the random number generator - one time only
	
	// declare counters for counts two through twelve before the for loop
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	int seven = 0;
	int eight = 0;
	int nine = 0;
	int ten = 0;
	int eleven = 0;
	int twelve = 0;
	
	for (int i=0; i<1000; i++){
		int rollResult = rollDice();
		
		switch (rollResult) {
			case 2:
				two++; // if the count is 2, increment the countern named 2;
				break;
			case 3:
				three++; // same logic as before;
				break;
			case 4:
				four++;
				break;
			case 5:
				five++;
				break;
			case 6:
				six++;
				break;
			case 7:
				seven++;
				break;
			case 8:
				eight++;
				break;
			case 9:
				nine++;
				break;
			case 10:
				ten++;
				break;
			case 11:
				eleven++;
				break;
			case 12:
				twelve++;
				break;
		} //end of switch/case block
	} // end of for loop
	
	//display counters
	cout << "2 = " << two << endl;
	cout << "3 = " << three << endl;
	cout << "4 = " << four << endl;
	cout << "5 = " << five << endl;
	cout << "6 = " << six << endl;
	cout << "7 = " << seven << endl;
	cout << "8 = " << eight << endl;
	cout << "9 = " << nine << endl;
	cout << "10 = " << ten << endl;
	cout << "11 = " << eleven << endl;
	cout << "12 = " << twelve << endl;
} 

int rollDice(){ // roll dice
	int roll1 = roll(); 
	int roll2 = roll();
	int Result = roll1 + roll2;
	return Result;
}

int roll() // roll one die ( die is the singular of dice)
{
	// A static variable keeps its same memory location from the time the program starts until it exits
	static bool randomInitialized = false;
	// A local variable gets a new memory location and needs to be initialized each time the program enters a block of code {...}
	int points;
	
	// Only 1st time the function is called initialize the random number geerator
	if(!randomInitialized){
		srand((unsigned int)time(NULL));
		randomInitialized = true;	//don't do it again
	}
	// rand returns a value from 0 to the largest possible integer
	points = (rand()%6)+1;		// add 1 because rand starts a zero
	return points;
}