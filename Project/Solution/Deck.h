/*
*	 This class is really much like a vector of cards; it contains and array which is dynamically added to and removed from. 
	 Ideally it will have 52 cards, however some games may require a different deck size so this is relatively flexible. 
*/

#ifndef DECK_H
#define DECK_H

#include "Card.h"
const int DEFAULT_SIZE = 52;
class Deck
{
private: 
	
	int numCards;
public:
	Deck(void);
	~Deck(void);

	// Shuffles the deck randomly
	void shuffle();

	// Sorts the cards by suit. 
	void sortBySuit();

	// Sorts the cards by integer value. Pass in a templated struct?
	void sortByNum();

	// Adds a card to the top of the deck. 
	void push();

	// Takes the top card off of the deck. 
	void pop();

	// Returns how many cards are left in the deck. 
	void getSize();

	// Returns (but does not pop) the top card on the deck. Think "peek"
	Card getTop();

};

#endif