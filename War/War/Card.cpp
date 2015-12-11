#include "Card.h"


Card::Card()
{
}

Card::Card(int cardSuit, int cardRank)
{
	setSuit(cardSuit);
	setRank(cardRank);
}


Card::~Card(void)
{
}

bool Card::setSuit(int cardSuit)
{
	if (cardSuit >= 0 && cardSuit < 4)
	{
		suit = cardSuit;
		return true;
	}
	return false;
}

int Card::getSuit()
{
	return suit;
}

bool Card::setRank(int cardRank)
{
	if (cardRank >= 2 && cardRank <= ACE)
	{
		rank = cardRank;
		return true;
	}
	return false;
}

int Card::getRank()
{
	return rank;
}

bool Card::operator<(const Card& rhs)
{
	if (rank < rhs.rank)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Card::operator>(const Card& rhs)
{
	if (rank > rhs.rank)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Card::operator<=(const Card& rhs)
{
	if (rank <= rhs.rank)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Card::operator>=(const Card& rhs)
{
	if (rank >= rhs.rank)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Card::operator==(const Card& rhs)
{
	if (rank == rhs.rank)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Card::operator!=(const Card& rhs)
{
	if (rank != rhs.rank)
	{
		return true;
	}
	else
	{
		return false;
	}
}
