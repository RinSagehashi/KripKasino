#pragma once
#include "Player.h"

class AI_Random :
	public Player
{
public:
	AI_Random();
	~AI_Random();
	unsigned runAI(vector<Card> const& table, vector<Card> const& hand,
		vector<LegalMove> const& legalMoves, vector<Card> const& myPile,
		vector<Card> const& opPile, unsigned myTabbe, unsigned opTabbe);
	std::string getName()
	{
		return "AI_Random";
	}
};

