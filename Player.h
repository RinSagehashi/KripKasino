#pragma once
#include "LegalMove.h"
#include <vector>
#include "Card.h"
#include <iostream>
#include <string>
#include <algorithm>
using std::vector;
class Player
{
public:
	//Player();
	virtual ~Player();
	virtual unsigned runAI(vector<Card> const& table, vector<Card> const& hand,
							vector<LegalMove> const& legalMoves, vector<Card> const& myPile,
							vector<Card> const& opPile, unsigned myTabbe, unsigned opTabbe)
	{
		std::cout << "I am Virtual" << std::endl;
		return 0;
	};
	virtual std::string getName()
	{
		return "Virtual Name";
	}
};

