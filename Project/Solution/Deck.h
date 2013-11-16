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
		// Default constructor: Make 52 cards:
		Deck(void)
		{
			size =   DEFAULT_SIZE;

			init();
		};

		// TODO: Parameterized constructor?

		void init(){
			// After we have the number of cards and such passed in, 
			// create the cards for the deck.
			
			for(int i=0; i<4; i++)
			{
				for(int j = 0; j<(size/4); j++)
				{
					if(i==0)
					{
						cards.Push(Card(HEARTS,j+1));
					}
					if(i==1)
					{
						cards.Push(Card(CLUBS, j+1));
					}
					if(i==2)
					{ 
						cards.Push(Card(SPADES, j+1));
					}
					if(i==3)
					{
						cards.Push(Card(DIAMONDS, j+1));
					}
				}
			}
			std::cout<< "Deck created with " << size << " cards!" << std::endl;
		};


		~Deck(void)
		{
			// Delete allocated memory etc etc : ( 
		};

		// Shuffles the deck randomly
		void shuffle(){
			// At the beginning, make a new vector to be the temp container
			MyVector<Card> temp;
		
		};

		void getRandom(){
			std::cout << cards.retrieveRandom();
		};

		// Sorts the cards by suit. 
		void sortBySuit();

		// Sorts the cards by integer value. Pass in a templated struct?
		void sortByNum();

		// Adds a card to the top of the deck. 
		void push();

		// Takes the top card off of the deck. 
		void pop();

		// Returns how many cards are left in the deck. 
		int getSize()
		{
			return size;
		};

		// Returns (but does not pop) the top card on the deck. Think "peek"
		Card getTop()
		{
			return cards.getTop();
		};

		// For testing purposes:
		void print(){
			std::cout <<"DECK, size: " << getSize() << std::endl;
			for(int i = 0; i<size; i++)
			{
				std::cout<< cards[i] << std::endl;
			}
		};

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