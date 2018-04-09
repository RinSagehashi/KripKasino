#pragma once
#include "Player.h"
#include <vector>
#include <algorithm>
class AI_PlayHighest :
	public Player
{
public:
	AI_PlayHighest();
	~AI_PlayHighest();
	unsigned runAI(vector<Card> const& table, vector<Card> const& hand,
		vector<LegalMove> const& legalMoves, vector<Card> const& myPile,
		vector<Card> const& opPile, unsigned myTabbe, unsigned opTabbe)
	{
		std::vector<double> vec;
		for (auto lm : legalMoves)
		{
			vec.push_back(evalLM(lm));
		}
		auto itr = std::max_element(vec.begin(), vec.end());
		unsigned idx = std::distance(vec.begin(), itr);
		return idx;

	}
	std::string getName()
	{
		return "AI_PlayHighest";
	}

	double evalLM(LegalMove lm)
	{
		double r = 0.0;
		r += (double)lm.m_playedCard.m_rank;
		r += lm.m_playedCard.m_suit*0.1;
		return r;
	}
};

