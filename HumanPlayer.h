#pragma once
#include "Player.h"
class HumanPlayer :
	public Player
{
public:
	HumanPlayer();
	~HumanPlayer();
	unsigned runAI(vector<Card> const& table, vector<Card> const& hand,
		vector<LegalMove> const& legalMoves, vector<Card> const& myPile,
		vector<Card> const& opPile, unsigned myTabbe, unsigned opTabbe);
	std::string getName()
	{
		return "HumanPlayer";
	}
};

