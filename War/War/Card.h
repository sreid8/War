#pragma once
#define HEARTS 0
#define DIAMONDS 1
#define CLUBS 2
#define SPADES 3
#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14

class Card
{
public:
	Card();
	Card(int cardSuit, int cardRank);
	~Card(void);
	
	bool setSuit(int cardSuit);
	int getSuit();
	bool setRank(int cardRank);
	int getRank();
	
	bool operator<(const Card& rhs);
	bool operator>(const Card& rhs);
	bool operator<=(const Card& rhs);
	bool operator>=(const Card& rhs);
	bool operator==(const Card& rhs);
	bool operator!=(const Card& rhs);

private:
	int suit;
	int rank;

};
