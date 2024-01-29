#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Card
{
public:
	enum rank
	{
		ACE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING
	};

	enum suit
	{
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES
	};

	// overloading << operator so can send Card object to std
	friend ostream& operator<<(ostream& os, const Card& aCard);

	Card(rank r = ACE, suit s = SPADES, bool ifu = true);

	// returns  the value of a card, 1-11
	int GetValue() const;

	// flips a card; if face up, becomes face down and vise versa
	void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};