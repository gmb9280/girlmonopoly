/*--------------------------------------------------------------------------------------------------
This project was made by Gabrielle Bennett and Amanda Rivet in 2013.
All rights reserved. 
--------------------------------------------------------------------------------------------------*/
#ifndef MAIN_CPP
#define MAIN_CPP
#include "Main.h"


// Game includes
#include "Deck.h"

// This is for OpenGL
void init(void){

}


int main()
{
	std::cout << "Cards in 3D! ... Soon\n";


	// Test the deck
	Deck myDeck;
	std::cout<< myDeck;

	std::cout<< endl << endl << "Peeking: " ;
	myDeck.getTop().Print();











	//Ending the program
	std::cout << "Press enter to finish";
	getchar();
	return 0;
}
#endif
