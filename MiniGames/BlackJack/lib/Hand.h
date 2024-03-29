﻿#pragma once

#include "Card.h"

#include <algorithm>
#include <vector>

using std::vector;

class Hand
{
public:
	Hand();
	virtual ~Hand();

	// adds a card to the hand
	void Add(Card* pCard);

	// clears hand of all cards
	void Clear();

	// gets hand total value, intelligently treats as 1 or 11
	int GetTotal() const;

protected:
	vector<Card*> m_Cards;
};
