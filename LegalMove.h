#pragma once

#include <vector>
#include "Card.h"
#include <string>

class LegalMove
{
public:
	LegalMove();
	~LegalMove();
	LegalMove(Card playedCard);
	LegalMove(Card playedCard, std::vector<Card> capturedCards);
	void addCapturedCards(Card card);
	void addCapturedCards(std::vector<Card> cards);
	std::string toString();
public:
	std::vector<Card> m_capturedCards;
	Card m_playedCard;

};

