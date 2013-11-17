#ifndef CARD_CPP
#define CARD_CPP
#include "Card.h"

Card::Card(void)
{
	value = 2; 
	suitType = SPADES;
}

Card::Card(suit suit_, int value_)
{
	value = value_;
	suitType = suit_;
}

// TO DO
Card::~Card(void)
{
}

int Card::getValue()
{
	return value;
}

const char* Card::getSuit()
{
	switch(suitType){
			case 0:
				return "Hearts"; break;
			case 1:
				return "Spades"; break;
			case 2: 
				return "Clubs"; break;
			case 3: 
				return "Diamonds"; break;
		}
}

void Card::Print()
{
	std::cout<< getValue() << " of" << getSuit() << std::endl;
}



#endif