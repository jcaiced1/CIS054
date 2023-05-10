/*	 Student_Class.cpp : Defines the entry point for the console application.
Jose Caicedo
Date: 04/30/2023
CIS054 C/C++ Programming
Version 1
Inputs: Student Id, Name, Major, GPA
Outputs: Student Id, Name, Major, GPA
*/

#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;

// define an array of students
Student CIS054[] = {
    Student ("Joe Williams", 44536, "Medicine", 3.4),
    Student ("Sally Washington", 1000001, "Criminology", 3.7),
    Student ("Fred MacIntosh", 66587, "4omputer Science", 2.9),
    Student ("Jose De La Cruz", 67892, "Math", 4.1),
    Student ("777 Dan McElroy", 77777, "English", 4.0),
    Student ("Thinh Nguyen", 73657, "Psychology", 3.6)
};


int main(int argc, char* argv[])
{
    int NumberOfStudents = sizeof(CIS054)/sizeof(Student);

    // Display the header line
     // List all the students in the course
    // output column headers
    cout << "ID #     NAME                  MAJOR                  GPA\n";
    cout << "=============================================================\n";
    
    // output student data
    for (int i = 0; i < NumberOfStudents; i++) {
        cout << left << setw(9) << CIS054[i].getIdNumber() 
        << setw(22) << CIS054[i].getName() 
        << setw(23) << CIS054[i].getMajor() 
        << CIS054[i].getGpa() << endl;
    }
    
    cout << endl; // blank line after displaying the student names

    // compute the average gpa of all the students
    double total=0;
    for (int i=0; i<NumberOfStudents; i++)
        total += CIS054[i].getGpa();
    double average = total / NumberOfStudents;
    cout << "  " << "The average GPA of all the students is " << average << endl << endl;
	return 0;
}
