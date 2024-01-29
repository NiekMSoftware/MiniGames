#include "../lib/Card.h"

Card::Card(rank r, suit s, bool ifu):
	m_Rank(r),
	m_Suit(s),
	m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
    // if a face card is down, its value is 0
    int value = 0;
    if (m_IsFaceUp)
    {
        // value is number showing on card
        value = m_Rank;

        // value is 10 for face cards
        if (value > 10)
        {
            value = 10;
        }
    }

    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

// overloads << operator so Card object can be sent to cout
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "ACE", "2", "3", "4", "5", "6", "7",
                            "8", "9", "10", "JOKER", "QUEEN", "KING" };
    const string SUITS[] = { "clubs", "diamonds", "hearts", "spades" };

    if (aCard.m_IsFaceUp)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}