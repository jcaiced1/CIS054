/* C++StringManipulation.cpp
Jose Caicedo
Date: 04/02/2023
Version 1
CIS054 C/C++ Programming
Inputs: Outputs:
*/

#include <iostream> // Required for input and output operations
#include <cstdlib> // Required for the random number generator
#include <ctime> // Required to seed the random number generator
#include <cctype> // Required for the toupper() function
#include <string> // Required for C++ strings

using namespace std;

// Arrays containing words for different parts of the sentence
const char *noun[] = {"desk", "chair", "envelope", "car", "train", "bus", "boat", "elephant", "dog", "cat", "moose", "rabbit"};
const char *article[] = {"the", "a", "one", "some", "any"};
const char *adjective[] = {"brave", "orange", "fast", "slow", "smart"};
const char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
const char *preposition[] = {"to", "from", "over", "under", "on"};

// Count the number of words in each array
int nounCount = sizeof(noun) / sizeof(char*);
int articleCount = sizeof(article) / sizeof(char*);
int adjectiveCount = sizeof(adjective) / sizeof(char*);
int verbCount = sizeof(verb) / sizeof(char*);
int prepositionCount = sizeof(preposition) / sizeof(char*);

int main(int argc, char *argv[])
{
    // Declare the variables
    string sentence; // C++ string object
    int selection,selectionArticle;
    
    srand((unsigned int)time(0));    // Seed the random number generator
    
    for (int i=0; i<20; i++)        // Create and display 20 sentences
    {
        selection = rand() % adjectiveCount;
        
        // Determine whether to use "an" before the adjective
        if (adjective[selection][0] == 'a' || adjective[selection][0] == 'e' || adjective[selection][0] == 'i' || adjective[selection][0] == 'o' || adjective[selection][0] == 'u')
            {
                sentence = "an";
            }
        else
            {
                selectionArticle = rand() %articleCount;
                sentence = article[selectionArticle];
            }
        
        sentence += " ";
        sentence += adjective[selection];
        sentence += " ";
        
        selection = rand() % nounCount;    
        sentence += noun[selection];    
        sentence += " ";
        
        selection = rand() % verbCount;
        sentence += verb[selection];
        sentence += " ";
        
        selection = rand() % prepositionCount;
        sentence += preposition[selection];
        sentence += " ";
        
        selection = rand() % adjectiveCount;
        
        // Determine whether to use "an" before the adjective
        if (adjective[selection][0] == 'a' || adjective[selection][0] == 'e' || adjective[selection][0] == 'i' || adjective[selection][0] == 'o' || adjective[selection][0] == 'u')
            {
                sentence += "an";
            }
        else
            {
                selectionArticle = rand()%articleCount;
                sentence += article[selectionArticle];
            }
        
        sentence += " ";
        sentence += adjective[selection];
        sentence += " ";
        
        selection = rand() % nounCount;    
        sentence += noun[selection];  
        
        sentence[0] = toupper(sentence[0]);    // make 1st  capital letter
        cout <<"("<<i+1<<") "<< sentence << "." << endl;  // display the sentences and add a period at the end.
    }
    return 0;
}
