//	CPlayersOnTeam.c // C language version of the program
//
//	MaxPlayers - determine if there are not enough, too many
//	or just right for the number of players on a team
//	Jose Caicedo
//	Date: 03/11/2023
//	CIS054 C/C++ Programming
//	Inputs: PlayersOnTeam, TeamSelection
//	Outputs: morePlayersNeeded, extraPlayers, teamSize

#include <stdio.h>		// used by printf and scanf

int selectTeamSize();	// function prototype

int main(int argc, char *argv[]) 
{
	int teamSize;
	int playersOnTeam;
	int morePlayersNeeded;
	int extraPlayers;
	int scanfCount;
	
	//	Input the data
	//	use SelectTeamSize() function to select a sport and return the 
	//	number of players needed on a team for that sport
	teamSize = selectTeamSize();	// use function shown below
	printf ("There should be %d players on the team\n", teamSize);
	
	//	Input the number of players on the team
	printf ("How many players are currently on the team? ");
	scanfCount=scanf("%d", &playersOnTeam);			// Microsoft uses scanf_s, Mac uses scanf
	if(scanfCount !=1){								//check for a non-numeric value being input
		printf ("Illegal entry for the team size\n");
		return 1;		// Indicate an error
	}
	
	//	Process and Output
	if(playersOnTeam < teamSize){
		printf("There are not enough players\n");
		morePlayersNeeded =  teamSize - playersOnTeam;
		printf("%d more players are needed", morePlayersNeeded);
	}
	else if (playersOnTeam > teamSize) {
		printf("There are too many players");
		extraPlayers = playersOnTeam - teamSize;
		printf("%d players need to be eliminated", extraPlayers);
	}
	else {
		printf("You have the correct number of players");
	}
	return 0;
}

//	The SelectTeamSize() function asks the user to select a soport and then
//	returns the number of players on a team for that sport.
int selectTeamSize()
{
	char teamSelection;	// team selection entered at the keyboard 1-4
	int teamSize;		// # players that should be on a team - returned to main
	
	do {
		printf( "Select a professional sport\n" 
			"1 - NFL Football\n"
			"2 - NBA Basketball\n"
			"3 - MLB Baseball\n"
			"4 - NHL Hockey\n"
			"Select(1-4): ");
		scanf("%c", &teamSelection);
		
		if (teamSelection == '1')
			teamSize = 53; // NFL
		else if (teamSelection == '2')
			teamSize = 13; // NBA
		else if (teamSelection == '3')
			teamSize = 25; // MLB
		else if (teamSelection == '4')
			teamSize = 23; // NHL
		else {
			printf ("Illegal selection - try again\n\n");
			teamSize = 0; // error flag
		}
		
		while(getchar() != '\n');	//	consume newline character left in input buffer
									//	Basically, this code is to prevent the while loop from displaying the selection two times when an invalid selection is made	
	} while (teamSize == 0);	// loop until a valid selection is made
	
	return teamSize;		// to be used by the main program
}