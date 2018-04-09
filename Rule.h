#pragma once
#include "LegalMove.h"
#include "Card.h"
#include <vector>
#include <bitset>

class Rule
{
public:
	static std::vector<LegalMove> getLegalMoves(const std::vector<Card> table, const std::vector<Card> hand);
	static unsigned evalCardPoint(Card card);
	static unsigned evalPilePoint(std::vector<Card> cards);
	bool isCapturable(const std::vector<Card> capturedCards, const Card playedCard);
private:
	static std::vector<std::bitset<16>> getCombineBits(std::vector<std::bitset<16>> bitsets);
	static std::vector<Card> bits2Cards(std::bitset<16> bs, std::vector<Card> table);
};

