#include "stdafx.h"
#include "LegalMove.h"
#include <vector>
#include "Card.h"
#include <string>

LegalMove::LegalMove()
{
}


LegalMove::~LegalMove()
{
}

LegalMove::LegalMove(Card playedCard)
{
	this->m_playedCard = playedCard;
}

LegalMove::LegalMove(Card playedCard, std::vector<Card> capturedCards)
{
	this->m_playedCard = playedCard;
	this->m_capturedCards.insert(this->m_capturedCards.end(), capturedCards.begin(), capturedCards.end());
}

void LegalMove::addCapturedCards(Card card)
{
	this->m_capturedCards.push_back(card);
}

void LegalMove::addCapturedCards(std::vector<Card> cards)
{
	this->m_capturedCards.insert(m_capturedCards.end(), cards.begin(), cards.end());
}

std::string LegalMove::toString()
{
	std::string str(m_playedCard.toString() + " : ");
	for (auto c : m_capturedCards)
	{
		str += c.toString() + " ";
	}
	return str;
}
