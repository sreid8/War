#include <iostream>
#include <vector>
#include "Deck.h"

#define CRAZY_CARD 3

using namespace std;

//these functions pass by reference so that the deck maintains state throughout execution
int playWar(Deck &deck);
int resolveWar(Deck &deck);

int main(void)
{
	Deck mainDeck(false);
	mainDeck.shuffleDeck();
	int p1Wins = 0, p2Wins = 0, result;
	for (int i = 0; i < 3; i++)
	{
		cout << "Starting round " << i+1 << "!!" << endl;
		result = playWar(mainDeck);
		if (result == -1)
		{
			cout << "Round " << i+1 << " goes to Player 1!" << endl;
			p1Wins++;
		}
		else if (result == 1)
		{
			cout << "Round " << i+1 << " goes to Player 2!" << endl;
			p2Wins++;
		}
		else
		{
			cout << "A winner could not be determined in round " << i+1 << "!" << endl;
		}
	}
	cout << endl << endl << "Player 1 won " << p1Wins << " times and Player 2 won " << p2Wins << " times" << endl;
	if (p1Wins > p2Wins)
	{
		cout << "Player 1 wins!" << endl;
	}
	else if (p2Wins > p1Wins)
	{
		cout << "Player 2 wins!" << endl;
	}
	else
	{
		cout << "A winner could not be determined!" << endl;
	}
	cout << "Press any key to exit" << endl;
	getchar();
	return 0;
}


/*rules are weird
if either pulls a CRAZY_CARD, the three wins
need to pick a "crazy" that wins all the time randomly from the deck.
unless either of those are pulled, the card that has the higher value wins.
if the two drawn cards are equal, war is declared
	- three cards are drawn for each person
		- sum of the sides three values is ranked. highest person wins. if equal, rewar
	- if < 6 cards exists in the deck, fight with remaining cards

THE VALUE RETURNED FROM THIS FUNCTION IS THE WINNER. -1 if PLAYER ONE WINS, 1 if PLAYER 2 WINS, 0 for error
*/
int playWar(Deck &deck)
{
	Card crazy = deck.getNextCard();
	cout << "This round's CRAZY CARD is " << crazy.getRank() << " in addition to the normal one of " << CRAZY_CARD << endl;
	Card p1;
	Card p2;
	
	p1 = deck.getNextCard();
	p2 = deck.getNextCard();

	cout << "Player 1 drew " << p1.getRank() << " and Player 2 drew " << p2.getRank() << "!!" << endl;
	if ( (p1 == crazy || p1.getRank() == CRAZY_CARD) && p1 != p2)
	{
		return -1;
	}
	else if ( (p2 == crazy || p2.getRank() == CRAZY_CARD) && p1 != p2)
	{
		return 1;
	}
	else if (p1 > p2)
	{
		return -1;
	}
	else if (p1 < p2)
	{
		return 1;
	}
	else // they're equal, time for war
	{
		cout << "It's a WAR!" << endl;
		return resolveWar(deck);
	}

	return 0;
}

//returns -1 if p1 wins, 1 if p2 wins, 0 for error
int resolveWar(Deck &deck)
{
	int p1Sum = 0, p2Sum = 0, i = 0, deckSize = 0;
	Card temp;
	Deck p1Deck(true);
	Deck p2Deck(true);
	deckSize = deck.getNumCardsInDeck();
	if (deckSize <= 0)
	{
		return 0; //no winner
	}
	if (deckSize >= 3)
	{
		deckSize = 3;
	}
	for (i = 0; i < deckSize; i++)
	{
		p1Deck.insertCard(deck.getNextCard());
		p2Deck.insertCard(deck.getNextCard());
	}
	for (i = 0; i < deckSize; i++)
	{
		temp = p1Deck.getNextCard();
		p1Sum += temp.getRank();
		temp = p2Deck.getNextCard();
		p2Sum += temp.getRank();
	}
	cout << "Player 1's WAR SUM is " << p1Sum << " and Player 2's WAR SUM is " << p2Sum << "!!" << endl;
	if (p1Sum > p2Sum)
	{
		return -1;
	}
	if (p2Sum > p1Sum)
	{
		return 1;
	}
	else //the sums are the same, need to go to war again
	{
		return resolveWar(deck);
	}
}