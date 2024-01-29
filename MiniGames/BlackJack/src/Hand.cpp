#include "../lib/Hand.h"

Hand::Hand()
{
	m_Cards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::Clear()
{
	// iterate through the vector, freeing all mem on the heap
	for (auto* card : m_Cards)
	{
		delete card;
		card = 0;
	}

	// clear empty vector of pointers
	m_Cards.clear();
}

int Hand::GetTotal() const
{
    // if no cards in hand, return 0
    if (m_Cards.empty())
    {
		return 0;
    }

	// if a first card has a value of 0, then card is face down; return 0
	if(m_Cards[0]->GetValue() == 0)
	{
		return 0;
	}

	// add up card values, treat each as 1
	int total = 0;
    for (const Card* m_card : m_Cards)
    {
		total += (m_card)->GetValue();
    }

	// determine if hand has ace
	bool containsAce = false;
    for (const auto* card : m_Cards)
    {
	    if((card)->GetValue() == Card::ACE)
	    {
			containsAce = true;
	    }
    }

	// if hand contains an ace and total is low enough, treat ace as 11
	if(containsAce && total <= 11)
	{
		// add only 10, ACE is already a value of 1
		total += 10;
	}

	return total;
}