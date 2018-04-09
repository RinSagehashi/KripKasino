#pragma once

#include <array>
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();
private:
	void shuffle();
public:
	Card deal();
	void reset();
private:
	std::array<Card, 52> m_cards;
	int m_nDealt;
	int m_nRemaining;
};

