/*	RationalTest.cpp
Jose Caicedo
Date: 05/07/2023
CIS054 C/C++ Programming
Version 1
Inputs: predefined values
Outputs: results with overloaded operators
*/
//
#include "Rational.h"   // double quotes = find file in project folder
#include <iostream>     // angle brackets = find file in compiler folder
#include <iomanip>
using namespace std;

// function prototypes
void initializeNumbers (Rational &, Rational &, Rational &);
void displayNumbers (Rational, Rational, Rational, const char *);

int main(int argc, char* argv[])
{
//  class    object
//    |        |
//    V        V
    Rational n1;
    Rational n2;  
    Rational n3;      

    // Title at the top of the display
    cout << "    n1     n2   n3\n  ==================\n" << endl;

    ///////// for each overloaded operator, 
    /////////    initialize the values for n1, n2 and n3
    /////////    test the operator
    /////////    display the results for n1, n2 and n3

    // Display values of n1, n2, n3 before each test
    initializeNumbers (n1, n2, n3);
    displayNumbers(n1, n2, n3, "Values of n1, n2 and n3 before the start of each test");

    // Test operator+
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2+n3           ;          // n2 + n3 = 3/4 + 2/3 = 9/12 + 8/12 = 17/12
    displayNumbers(n1, n2, n3, "n1 = n2 + n3 (n1 should be 17/12)");

    // Test operator+=
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1= n2 += n3;
    displayNumbers(n1, n2, n3, "n1 = n2 += n3 (n2 should be 17/12)");

    ///////// The test for + and += have been completed. You need to write the tests 
    ///////// for -   -=   *   *=   /   /=   =   and ==

    // Test operator-
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2-n3;
    displayNumbers(n1, n2, n3, "n1 = n2 - n3 (n1 should be 1/12)");

    // Test operator-=
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1= n2 -= n3;
    displayNumbers(n1, n2, n3, "n1 = n2 -= n3 (n2 should be 1/12)");
    
    // Test operator*
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2 * n3;
    displayNumbers(n1, n2, n3, "n1 = n2 * n3 (n1 should be 1/2)");
    
    // Test operator*=
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1= n2 *= n3;
    displayNumbers(n1, n2, n3, "n1 = n2 *= n3 (n2 should be 1/2)");
    
    // Test operator/
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2 / n3;
    displayNumbers(n1, n2, n3, "n1 = n2 / n3 (n1 should be 9/8)");
    
    // Test operator/=
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1= n2 /= n3;
    displayNumbers(n1, n2, n3, "n1 = n2 /= n3 (n2 should be 9/8)");

    // Test operator==  this should return a TRUE if both numbers are the same, otherwise FALSE
    initializeNumbers (n1, n2, n3); // reset the values before each test
    if (n2 == n3)
    {
        cout << setw(4) << n2 << " == " << n3 <<" therefore it is True"<<endl;
    }
    else {
        
        cout << setw(4) << n2 << " != " << n3 <<" therefore it is False"<<endl;
    }

    // Test operator double
    cout << endl << endl << "**** Rational number to double. 1/12 displays as 0.0833333" << endl;
    cout << "double(n2) = " << double(n2) << endl;
	cout << endl;
    return 0;
}

// Initialize each of the variables before testing each rational operator
void initializeNumbers (Rational &n1, Rational &n2, Rational &n3)
{
    n1 = Rational ();     //    0  no arguments
    n2 = Rational (3,4);  //   3/4
    n3 = Rational (2,3);  //   2/3
}

// Display each of the rational numbers using the friend function <<
void displayNumbers (Rational n1, Rational n2, Rational n3, const char *msg)
{
    cout << setw(4) << n1 << setw(4) <<  n2 << setw(4)  << n3 << "\t" << msg << endl;
}