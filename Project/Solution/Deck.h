/*
*	 This class is really much like a vector of cards; it contains and array which is dynamically added to and removed from. 
	 Ideally it will have 52 cards, however some games may require a different deck size so this is relatively flexible. 
*/

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "MyVector.h"
#include "iostream"

const int DEFAULT_SIZE = 52;
class Deck
{
	public:
		//
		// TODO: Parameterized constructor?
		//

		// Default constructor: Make 52 cards.
		Deck(void);

		void init();

		~Deck(void);

		// Shuffles the deck randomly
		void shuffle();

		// Sorts the cards by suit. 
		// Eg: hearts 1-13, clubs 1-13, spades 1-13, diamonds 1-13.
		void sortBySuit();

		// Sorts the cards by integer value. Pass in a templated struct?
		// Eg: 1 of hearts, 1 of clubs, 1 of spades, 1 of diamonds, 2 of hearts...
		void sortByNum();

		// Adds a card to the top of the deck. 
		void push();

		// Takes the top card off of the deck. 
		void pop();

		// Returns how many cards are left in the deck. 
		int getSize();

		// Returns (but does not pop) the top card on the deck. Think "peek"
		Card getTop()
		{
			return cards.getTop();
		};

		// For testing purposes:
		void print();

		// Friend operator which allows you to cout a Deck object. 
		// Must stay in the .h file.
		friend ostream& operator<<(ostream &out, Deck &deck_)
		{
			for(int i=0; i<deck_.getSize(); i++)
			{
				out << "[ " << deck_.cards[i] << " ]" << std::endl;
				
			}
			return out;
		};

	private: 
	
		int size;
		MyVector<Card> cards;

};

#endif