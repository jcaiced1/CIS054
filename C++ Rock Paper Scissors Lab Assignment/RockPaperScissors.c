/*	RockPaperScissors-V1.0 - Determines the game winner
C-language version of the game
Name: Jose Caicedo
Date: 03/19/2023
Inputs: player1 and player2 - (R)ock, (P)aper, or (S)cissors
Output: Winner of the round
*/

#include <stdio.h>	// needed for printf and scanf
#include <ctype.h>	// needed for the toupper function


int main(int argc, char *argv[]) 
{
	/* Declare the variables */
	char player1;			// input for Player 1
	char player2;			// input for Player 2
	char PlayAgain = 'Y';	// loop control
	
	/* Input user selections and determine the winner */
	printf( "Enter R P or S for rock, paper or scissors\n\n");
	do 
		{
			printf("Player 1's move (R P S): ");	// prompt for player 1
			scanf(" %c", &player1);	// skip  leading whitespace, read player 1
			player1 = toupper(player1); // convert for easy comparisons
			
			printf("Player 2's move (R P S): ");	// prompt for player 2
			scanf(" %c", &player2);	// skip  leading whitespace, read player 2
			player2 = toupper(player2); // convert for easy comparisons
			
			if (player1 == 'R')
				{
					if (player2 == 'R')
						printf ( "Tie game\n");
					else if(player2 == 'P')
						printf ( "Player 2 wins - Paper covers rock\n");
					else if (player2 == 'S')
						printf ("Player 1 wins - Rock breaks scissors\n");
					else
						printf ( "Illegal selection for player 2\n");
				}
			else if (player1 == 'P')
				{
					if (player2 == 'R')
						printf ( "Player 1 wins - Paper covers rock\n");
					else if(player2 == 'P')
						printf ("Tie game\n");
					else if (player2 == 'S')
						printf ("Player 2 wins - Scissors cuts paper\n");
					else
						printf ( "Illegal selection for player 2\n");
				}
			else if (player1 == 'S')
				{
					if (player2 == 'R')
						printf ( "Player 2 wins - Rock breaks scissors\n");
					else if(player2 == 'P')
						printf ( "Player 1 wins - Scissors cut paper\n");
					else if (player2 == 'S')
						printf ("Tie game\n");
					else
						printf ( "Illegal selection for player 2");
				}
			else
			{
				printf ( "Illegal selection for player 1");
			}
			
			printf ( "Play again? Y/N: ");
			scanf(" %c", &PlayAgain);	// added a space before %c to ignore any whitespace in the input burffer before reading the next character
			PlayAgain = toupper(PlayAgain);	// convert in case lower case Y
			printf ("\n");	// blank line between games
		}
			while (PlayAgain == 'Y');
			return 0;
}