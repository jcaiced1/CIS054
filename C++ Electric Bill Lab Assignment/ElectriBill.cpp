/*	ElectricBill.cpp
Jose Caicedo
Date: 03/19/2023
CIS054 C/C++ Programming
Inputs: kwh
Outputs: totalTier1, totalTier2, totalTier3, tax, total
*/

/*	1 - Project Definition
Write a program that inputs
the kWh used and computes and displays the electric bill for
each tier, the tax and total bill.
The bill is computed using pricing levels, known as “tiers,”
based on the amount of energy used. The first tier is known
as the Baseline Allowance of 350 kWh and is billed at $0.23
per kWh. Energy used between 351 and 1450 kWh is in Tier
2 and is billed at $0.29 per kWh. The third tier is for usage
over 1450 kWh and is billed at $0.45 per kWh. An Energy
Commission Tax of $0.20 is added to the final bill.
*/

#include <iostream>	//	used for cin and cout
#include <iomanip>	//	used to set 2 digits past the decimal
using namespace std;

/*	define the constants */
const double TIER_1_ALLOWANCE = 350 ;	/* tier 1 allowance */
const double TIER_2_ALLOWANCE = 1450;	/* tier 2 allowance */
const double TIER_1_RATE = 0.23;	/* Tier 1 rate */
const double TIER_2_RATE = 0.29;	/* Tier 2 rate */
const double TIER_3_RATE = 0.45;	/* Tier 3 rate */
const double TAX_RATE = 0.20;		/* 0.20 is $0.20 */

int main(int argc, char *argv[]) 
{
	//	Declare the variables
	int kwh, kwh1, kwh2, kwh3;
	double totalTier1, totalTier2, totalTier3;				//	values input from the keyboard
	double tax, total;
	
	// INPUT: kWh
	cout << "Enter kWh used: ";		//prompt
	cin >> kwh;
	
	if (cin.fail())
	{
		cout<< "Illegal-non-numeric input\n";		// in case an invalid input is provided
		return 1;
	}
	
	// PROCESS: compute the kWh with the respective tier rates

	if(kwh<=TIER_1_ALLOWANCE)				// less or equal to 350 kWh Tier 1
	{
		totalTier1 = kwh * TIER_1_RATE;		// separate regHours and overtimeHours
		kwh1 = kwh;
		kwh2 = 0;
		kwh3 = 0;
		cout<<setiosflags(ios::fixed | ios::showpoint);
		cout<<"Tier 1 Usage "<<kwh1<<" kWh $"<<setprecision(2)<< totalTier1<<endl;
		cout<<"Tier 2 Usage "<<kwh2<<endl;
		cout<<"Tier 3 Usage "<<kwh3<<endl;
	}
	else if(TIER_1_ALLOWANCE < kwh && kwh <= TIER_2_ALLOWANCE){		// more than 350 kWh but less or equal to 1450 kWh
		totalTier1 = TIER_1_ALLOWANCE * TIER_1_RATE;
		totalTier2 = (kwh - TIER_1_ALLOWANCE) * TIER_2_RATE;
		kwh1 = TIER_1_ALLOWANCE;
		kwh2 = kwh - TIER_1_ALLOWANCE;
		kwh3 = 0;
		cout<<setiosflags(ios::fixed | ios::showpoint);
		cout<<"Tier 1 Usage "<<kwh1<<" kWh $"<<setprecision(2)<< totalTier1<<endl;
		cout<<"Tier 2 Usage "<<kwh2<<" kWh $"<<setprecision(2)<< totalTier2<<endl;
		cout<<"Tier 3 Usage "<<kwh3<<endl;
	}
	else {															// more than 1450 kWh
		totalTier1 = TIER_1_ALLOWANCE * TIER_1_RATE;	
		totalTier2 = (TIER_2_ALLOWANCE - TIER_1_ALLOWANCE) * TIER_2_RATE;
		totalTier3 = (kwh - TIER_2_ALLOWANCE) * TIER_3_RATE;
		kwh1 = TIER_1_ALLOWANCE;
		kwh2 = TIER_2_ALLOWANCE-TIER_1_ALLOWANCE;
		kwh3 = kwh-TIER_2_ALLOWANCE;
		cout<<setiosflags(ios::fixed | ios::showpoint);
		cout<<"Tier 1 Usage "<<kwh1<<" kWh $"<<setprecision(2)<< totalTier1<<endl;
		cout<<"Tier 2 Usage "<<kwh2<<" kWh $"<<setprecision(2)<< totalTier2<<endl;
		cout<<"Tier 3 Usage "<<kwh3<<" kWh $"<<setprecision(2)<< totalTier3<<endl;
	}
	tax = TAX_RATE;
	total = totalTier1 + totalTier2 + totalTier3 + tax;
	
	// OUTPUT: tax and total
	cout<<setiosflags(ios::fixed | ios::showpoint);
	cout<<"Energy Commission Tax $"<<setprecision(2)<<tax<<endl;
	cout<<"Total Electric Charges $"<<setprecision(2)<<total<<endl;
	
	return 0;
}
