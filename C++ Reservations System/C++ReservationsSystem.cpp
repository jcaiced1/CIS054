/*	C++ReservationsSystem.cpp
Jose Caicedo
Date: 05/14/2023
CIS054 C/C++ Programming
Version 1
Inputs: NumberOfRows, NumberOfSeats
Outputs: seating arrangement, availability of seat, number of seats available
*/

#include <iostream>
#include <cctype>
using namespace std;

// Function declarations (prototypes)
char **CreateArrayOfSeats (int NumberOfRows, int seats);
void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats);
void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int seats);
void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int seats);

int main(int argc, char* argv[])
{
    char **ArrayOfSeats;
    int NumberOfRows;
    int NumberOfSeats;
    char rowSelection;  // 1 to max NumberOfRows, input from the user
    char seatSelection; // 'A' to max seats, input from the user, convert to a number
    int row;    // index into ArrayOfSeats, 0 to NumberOfRows-1
    int seat;   // index into ArrayOfSeats, 0 to seats-1
    int i = 0;
    
    // get the number of NumberOfRows and seats from the user
    cout << "Enter the number of rows: ";
    cin  >> NumberOfRows;
    cout << "Enter the number of seats on each row: ";
    cin  >> NumberOfSeats;
    
    ArrayOfSeats = CreateArrayOfSeats(NumberOfRows, NumberOfSeats);
    InitializeSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
    DisplayArrayOfSeats  (ArrayOfSeats, NumberOfRows, NumberOfSeats);
    
    // full amount of seats available 
    
    int y = NumberOfRows * NumberOfSeats;
    cout<< "Total number of seats: " << y <<endl;
    cout <<"Total seats occupied: 0" <<endl;
    
    do
        {
            
            cout << endl << "Enter a seat selection" << endl << "  (example 5F -or- 00 to quit): ";
            cin  >> rowSelection;       // get row from the user
            cin  >> seatSelection;      // get the seat from the user
            if (rowSelection=='0')
                continue;               // skip the rest of the loop
            
            seatSelection = toupper(seatSelection); // convert to upper case
            row = rowSelection - '1';     // count from zero to work with the array
            seat = seatSelection - 'A';   // convert 'A' to 0, 'B' to 1, 'C' to 2, etc.
            
            //------ you need to complete the rest of the program------
            // Verify that a valid row and seat were entered
            //
            // See if all the seats are taken
            //   hint, keep a count each time a seat is taken
            //   and compare to the maximum number of seats (NumberOfRows*seats)
            // See if the seat selection is already taken (see if it has an '-')
            //   if it has an '-', display a message that the seat is taken
            //   else, put an '-' in that location using   ArrayOfSeats[row][seat] = '-';   
            
            if (ArrayOfSeats[row][seat]=='-')
                cout << "The seat you selected has already been taken." <<endl;
            else
                {
                    ArrayOfSeats[row][seat] = '-';
                    i++;                    // keeps count of every seat that is taken
                };
            
            DisplayArrayOfSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
            
            
            int x = NumberOfRows * NumberOfSeats;
            cout<< "Total number of seats: " << x <<endl;
            cout<< "Total seats occupied: " <<i <<endl;
            
            if ((x-i) == 0)                 // ends if all seats are taken
                {
                    cout << "All seats are taken" <<endl;
                    return 0;
                }
            
        } while (rowSelection != '0');
    
    MemoryCleanup (ArrayOfSeats, NumberOfRows, NumberOfSeats);   // return the memory
    
    return 0;
}

char **CreateArrayOfSeats (int NumberOfRows, int seats)    // ** means pointer to pointers
{
    char **ArrayOfSeats;
    ArrayOfSeats = new char*[NumberOfRows];          // create array of pointers for NumberOfRows
    for(int r = 0; r < NumberOfRows; r++)
        ArrayOfSeats[r] = new char[seats];   // create an array of seats for each row
    return ArrayOfSeats;                     // return pointer to the array back to main program
}

void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats)
{
    for (int r=0; r<NumberOfRows; r++)          // initialize the data for each row
    {
        for (int s=0; s<seats; s++)
            ArrayOfSeats[r][s] = 'A' + s;    // put 'A' 'B' 'C' etc in each row
    }
}

void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
    for (int r=0; r<NumberOfRows; r++)              // for each row
    {
        cout.width(2);
        cout << r+1 << ' ';                 // Display row numbers starting from 1
        for (int s=0; s<NumberOfSeats; s++)
            cout << ArrayOfSeats[r][s] << ' ';   // Display info for each seat
        cout << endl;                       // new line after each row
    }
}

void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
    for (int r=0; r<NumberOfRows; r++)
        delete [] ArrayOfSeats[r];   // delete each row of seats individually
    delete [] ArrayOfSeats;          // delete the row array
}  