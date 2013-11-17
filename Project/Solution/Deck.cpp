
#ifndef DECK_CPP
#define DECK_CPP
#include "Deck.h"

Deck::Deck()
{
	size =   DEFAULT_SIZE;

	init();
}

Deck::~Deck()
{
	//  TO DO: 
	// Delete allocated memory, etc etc. 
}

void Deck::init()
{
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
}

void Deck::shuffle()
{
	// At the beginning, make a new vector to be the temp container
	MyVector<Card> temp;
			
	for(int i=size; i>0; i--)
	{
		temp.Push(cards.retrieveRandom(i));
	}
	std::cout<< "Size of your newly shuffled deck: " << temp.GetSize() << endl;
	this->cards = temp;
	
	// TODO: delete temp
}

// TO DO
void Deck::sortBySuit()
{

}

void Deck::sortByNum()
{
}

// TO DO
void Deck::push()
{
}

// TO DO
void Deck::pop()
{
}

int Deck::getSize()
{
	return size;
}

void Deck::print()
{
	std::cout <<"DECK, size: " << getSize() << std::endl;
	for(int i = 0; i<size; i++)
	{
		std::cout<< cards[i] << std::endl;
	}
}



#endif