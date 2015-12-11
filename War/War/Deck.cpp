#include "Deck.h"


Deck::Deck(bool empty = false)
{
	int i = 0, j = 0;
	if (!empty)
	{
		for (i = HEARTS; i <= SPADES; i++)
		{
			for (j = 2; j <= ACE; j++)
			{
				cards.push_back(Card(i,j));
			}
		}
	}
}


Deck::~Deck(void)
{
}

Card Deck::getNextCard()
{
	Card temp;
	if (cards.size() > 0)
	{
		temp = cards[cards.size() - 1];
		cards.pop_back();
	}
	return temp;
}

bool Deck::insertCard(Card card)
{
	cards.push_back(card);
	return true;
}

bool Deck::shuffleDeck()
{
	int number = -1, startSize = cards.size();
	std::vector<Card> shuffled;
	srand(time(NULL));
	for (int i = 0; i < startSize; i++)
	{
		number = rand() % cards.size();
		shuffled.push_back(cards[number]);
		cards.erase(cards.begin() + number);
		srand(time(NULL));
	}
	cards = shuffled;
	return true;
}

int Deck::getNumCardsInDeck()
{
	return cards.size();
}
