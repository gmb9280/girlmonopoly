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
	Card(void)
	{
			value = 2;
			suitType = SPADES;
	};

	// Construct with a suit type and a value 1-13. Make sure to check if valid and throw an error if it isn't.
	Card(suit suit_, int value_){
		value = value_;
		suitType = suit_;
	};

	// Destructor.
	~Card(void);

	// Return the value
	int getValue(){
		return value;
	};

	const char* getSuit(){
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
	// Print
	void Print()
	{
		std::cout<< getValue() << " of " << getSuit() << std::endl;
	}

	friend ostream& operator<<(ostream &out, Card &card_){
		out << card_.getValue() << " of " << card_.getSuit() ;
		return out;
	};
};

#endif