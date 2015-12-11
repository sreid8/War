#pragma once
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
class Deck
{
public:
	Deck(bool empty);
	~Deck(void);

	Card getNextCard();
	bool insertCard(Card card);
	bool shuffleDeck();

	int getNumCardsInDeck();

private:
	std::vector<Card> cards;
};
