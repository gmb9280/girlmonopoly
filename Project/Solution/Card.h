#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

enum suit
	{
		HEARTS, SPADES, CLUBS, DIAMONDS
	};
class Card
{
private: 
	suit suitType;
	int value;

public:
	// Default card constructor -- I'm sure there can be something here, maybe a joker?
	Card(void);

	// Construct with a suit type and a value 1-13. Make sure to check if valid and throw an error if it isn't.
	Card(suit suit_, int value_);

	// Destructor.
	~Card(void);

	// Return the value
	int getValue();

	const char* getSuit();

	// Print
	void Print();

	// Friend operator override which allows you to print a card object.
	// It must remain in the .h
	friend ostream& operator<<(ostream &out, Card &card_){
		out << card_.getValue() << " of " << card_.getSuit() ;
		return out;
	};
};

#endif