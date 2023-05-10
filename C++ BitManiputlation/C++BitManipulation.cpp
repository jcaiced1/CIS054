/*	C++BitManipulation.cpp
Jose Caicedo
Date: 04/30/2023
CIS054 C/C++ Programming
Version 1
Inputs: x
Outputs: 1 or 0
*/

#include <iostream>
using namespace std;

int NUMBER_OF_BITS = 8;

int OddParity(char ch)
{
	int counter = 0; // initialize count to 0
	int i;
	for (int i = 0; i < NUMBER_OF_BITS; i++) 
		{
			// LOOK AT THE MSB FOR 8 BITS
			if ((ch & 0x80) != 0) 
				counter++;
			ch = ch << 1;	// shift left one bit
		}
	if (counter % 2 == 1)
		{
			return 0;
		} else {
			return 1;
		};
}

int main(int argc, char *argv[]) {
	char x;
	cout << "Enter a character: " ;
	cin >> x;
	cout << "The parity bit is: " << OddParity(x) <<endl;
}