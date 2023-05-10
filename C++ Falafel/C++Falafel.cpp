// C++Falafel.cpp
// CIS-054 C/C++ Programming
// Jose Caicedo
// 04/16/2023
// Version 1

// Inputs: selection
// Outputs: counts, subtotal, tax_total, total

#include <iostream>
#include <iomanip>
#include <cctype>
void displayMenu();
using namespace std;

const double PRICE_FALAFEL = 5.15;
const double PRICE_SODA = 2.24;
const double PRICE_EXTRA = 1.57;
const double TAX_RATE = 0.087;

int main(int argc, char *argv[]) 
{
	double subtotal = 0.00;
	double tax_total = 0.00;
	double price;
	char selection;
	int counts[3] = {0}; // initialize all counters to zero
	
	displayMenu();
	do
		{
			price = 0;
			cout << "Make your selection (FSXT): ";
			cin >> selection;
			switch (toupper(selection))
			{
				case 'F':
					price = PRICE_FALAFEL;
					counts[0]++; // increment falafel counter
					break;
				case 'S':
					price = PRICE_SODA;
					counts[1]++; // increment soda counter
					break;
				case 'X':
					price = PRICE_EXTRA;
					counts[2]++; // increment extras counter
					break;
				case 'T':
					break;
				default:
					cout << "Illegal selection, try again." <<endl;
			}
			subtotal += price;
			tax_total += price * TAX_RATE; // calculate tax for the item
		} while (selection != 'T' && selection != 't');
	
	double total = subtotal + tax_total;
	
	cout << "+----------------------------------+"<<endl;
	cout << "| Item        | Count   | Subtotal |" << endl;
	cout << "+----------------------------------+"<<endl;
	cout << "| Falafel     | " << setw(7) << counts[0] << " | $" << setw(7) << counts[0]*PRICE_FALAFEL << " |" << endl;
	cout << "| Soda        | " << setw(7) << counts[1] << " | $" << setw(7) << counts[1]*PRICE_SODA << " |" << endl;
	cout << "| Extras      | " << setw(7) << counts[2] << " | $" << setw(7) << counts[2]*PRICE_EXTRA << " |" << endl;
	cout << "+----------------------------------+"<<endl;
	
	cout << setiosflags(ios::fixed | ios::showpoint);
	cout << setprecision(2);
	cout << " Subtotal: $" << subtotal <<endl;
	cout << " Tax total: $" << tax_total <<endl;
	cout << " Total: $" << total <<endl;
	return 0;
}

void displayMenu()
{
	cout << setiosflags(ios::fixed | ios::showpoint);
	cout << setprecision(2);
	cout << endl;
	cout << "F = falafel  $" << PRICE_FALAFEL << endl;
	cout << "S = soda     $" << PRICE_SODA << endl;
	cout << "X = extras   $" << PRICE_EXTRA << endl;
	cout << "T = total" << endl;
}
