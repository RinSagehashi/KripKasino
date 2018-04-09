#include "stdafx.h"
#include "Card.h"
#include <string>

Card::Card()
{
	this->m_rank = RANK_BLANK;
	this->m_suit = SUIT_BLANK;
	this->m_index = -1;
}


Card::~Card()
{
}

Card::Card(int suit, int rank)
{
	this->m_rank = rank;
	this->m_suit = suit;
	this->m_index = rank + suit * 13; //
}

std::string Card::toString()
{
	if (m_rank < RANK_BEGIN || m_rank >= RANK_END || m_suit < SUIT_BEGIN || m_suit >= SUIT_END)
		return std::string("??");
	
	std::string str(1, "SDCH"[m_suit]);
	str += "?A23456789TJQK"[m_rank];
	return str;
}

bool Card::operator==(const Card & x)
{
	return this->m_index == x.m_index;
}

bool Card::operator<(const Card & right)
{
	return this->m_index>right.m_index;
}
