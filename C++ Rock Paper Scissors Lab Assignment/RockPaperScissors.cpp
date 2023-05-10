/*	RockPaperScissors-V1.0 - Determines the game winner
C++ Programming version of the game
Name: Jose Caicedo
Date: 03/19/2023
Inputs: player1 and player2 - (R)ock, (P)aper, or (S)cissors
Output: Winner of the round
*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) 
{
	char player1;			// input for Player 1
	char player2;			// input for Player 2
	char playAgain = 'y';	// loop control
	do
		{
			cout << "Enter R P or S for rock, paper or scissors" << endl;	// Instructions for the game
			
			cout << "Player 1 (R P S): ";
			cin >> player1;
			player1 = toupper(player1); // convert for easy comparisons
			
			while (player1 != 'R' && player1 != 'P' && player1 != 'S') {	// this loop is to ensure that the user provide a valid input for player 1
				cout << "Illegal selection for player 1"<<endl;
				cout << "Player 1 (R P S): ";
				cin >> player1;
				player1 = toupper(player1);
			}
			
			cout << "Player 2 (R P S): ";
			cin >> player2;
			player2 = toupper(player2); // convert for easy comparisons
			
			while (player2 != 'R' && player2 != 'P' && player2 != 'S') {	// this loop is to ensure that the user provide a valid input for player 2
				cout << "Illegal selection for player 2"<<endl;
				cout << "Player 2 (R P S): ";
				cin >> player2;
				player2 = toupper(player2);
			}
			
			if (player1 == 'R')
				{
					if (player2 == 'R')
						cout << "Tie game, nobody wins"<< endl;
					else if(player2 == 'P')
						cout << "Paper covers rock - player 2 wins"<<endl;
					else 
						cout <<"Rock breaks scissors - player 1 wins"<<endl;
				}
			else if (player1 == 'P')
				{
					if (player2 == 'R')
						cout << "Paper covers rock - player 1 wins"<< endl;
					else if(player2 == 'P')
						cout << "Tie game, nobody wins"<<endl;
					else 
						cout <<"Scissors cuts paper - player 2 wins"<<endl;
				}
			else if (player1 == 'S')
				{
					if (player2 == 'R')
						cout << "Rock breaks scissors - player 2 wins"<< endl;
					else if(player2 == 'P')
						cout << "Scissors cut paper - player 1 wins"<<endl;
					else 
						cout <<"Tie game, nobody wins"<<endl;
				}
			
			do{
				cout << "Do you want to play again? Y/N: ";		// loop to ensure that user provides a valid option N or Y
				cin >> playAgain;
				playAgain = toupper(playAgain);					// convert in case lower case Y
				if(playAgain !='N' && playAgain !='Y')
					cout <<"Illegal selection. " <<endl;
			}
			while(playAgain != 'Y' && playAgain != 'N');
			
			if(playAgain == 'N')
				break;						// break out the loop and exit the program
			
			cout <<endl;	// blank line between games
		}
	while (playAgain == 'Y');
	
	return 0;
}