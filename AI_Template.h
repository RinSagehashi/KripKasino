#pragma once
#include "Player.h"

class AI_Template :
	public Player
{
public:
	AI_Template();
	~AI_Template();
	unsigned runAI(vector<Card> const& table, vector<Card> const& hand,
		vector<LegalMove> const& legalMoves, vector<Card> const& myPile,
		vector<Card> const& opPile, unsigned myTabbe, unsigned opTabbe)
	{
		std::vector<double> vec;
		for (auto lm : legalMoves)
		{
			vec.push_back(eval(lm, table, hand, myPile, opPile, myTabbe, opTabbe));
		}
		auto itr = std::max_element(vec.begin(), vec.end());
		unsigned idx = std::distance(vec.begin(), itr);
		return idx;

	}
	std::string getName()
	{
		return "AI_Template";
	}

	double eval(LegalMove const& legalMove, vector<Card> const& table, vector<Card> const& hand,
				vector<Card> const& myPile, vector<Card> const& opPile, unsigned myTabbe, unsigned opTabbe)
	{
		double val = 0.0;
		val += legalMove.m_playedCard.m_rank;
		return val;
	}
};

