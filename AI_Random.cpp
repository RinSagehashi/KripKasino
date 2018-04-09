#include "stdafx.h"
#include "AI_Random.h"
#include <random>


AI_Random::AI_Random()
{
}


AI_Random::~AI_Random()
{
}


unsigned AI_Random::runAI(vector<Card> const& table, vector<Card> const& hand,
	vector<LegalMove> const& legalMoves, vector<Card> const& myPile,
	vector<Card> const& opPile, unsigned myTabbe, unsigned opTabbe)
{
	std::random_device rnd;
	return rnd()%legalMoves.size();
}
