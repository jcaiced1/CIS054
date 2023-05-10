/*	C++SentenceFormating.cpp
Jose Caicedo
Date: 04/02/2023
Version 1
CIS054 C/C++ Programming
Inputs: sentence
Outputs: sentence (modified)
*/

/*
DESCRIPTION:
1) Input a sentence from the keyboard ending in a period
2) Change all whitespace characters to a space
3) Remove multiple spaces
4) Capitalize the first character of the sentence
5) Make all other characters lower-case
*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char sentence[200];
	int i=0, j=0;
	
	cout<<"Enter a sentence:" <<endl;
	cin.getline(sentence,200);
	
	// Change all whitespace characters to a space
	for (i=0;sentence[i];i++)
	{
		if(isspace(sentence[i]))
			sentence[i] = ' ';
	}
	
	// Remove multiple spaces
	i=0;
	while(sentence[i]!='\0')
	{
		// look for two consecutive spaces
		if(sentence[i]==' ' && sentence[i+1]==' ')
			for (int j=i;sentence[j]; j++)
		{
			sentence[j]=sentence[j+1];
		}
		else
			i++;
	}
	
	// Capitalize the first character of the sentence
	sentence[0] = toupper(sentence[0]);
	
	// make all the other characters lower-case
	// to start with the 2nd character, set i=1
	for (i=1; sentence[i]; i++)
	{
		sentence[i] = tolower(sentence[i]);
	}
	
	// display the output
	cout<< sentence<<endl;
}