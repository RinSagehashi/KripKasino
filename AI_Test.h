#pragma once
#include "Player.h"
class AI_Test :
	public Player
{
public:
	AI_Test();
	~AI_Test();
	unsigned runAI(vector<Card> const& table, vector<Card> const& hand,
		vector<LegalMove> const& legalMoves, vector<Card> const& myPile,
		vector<Card> const& opPile, unsigned myTabbe, unsigned opTabbe)
	{
		return 0;
	}
	std::string getName()
	{
		return "AI_Test";
	}
};

