#include "stdafx.h"
#include "Deck.h"
#include "Card.h"
#include <array>
#include <random>
#include <algorithm>

Deck::Deck()
{
}


Deck::~Deck()
{
}

void Deck::shuffle()
{
	std::random_device seed_gen;
	std::mt19937_64 mt(seed_gen());
	std::shuffle(m_cards.begin(), m_cards.end(), mt);
}

Card Deck::deal()
{
	m_nRemaining--;
	return Card(m_cards[m_nDealt++]);
}

void Deck::reset()
{
	m_nRemaining = 0;
	m_nDealt = 0;
	for (int i = Card::SUIT_BEGIN; i < Card::SUIT_END; i++)
	{
		for (int j = Card::RANK_BEGIN; j < Card::RANK_END; j++)
		{
			m_cards[m_nRemaining++] = Card(i, j);
		}
	}
	shuffle();
}
