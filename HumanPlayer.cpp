#include "stdafx.h"
#include "HumanPlayer.h"
#include <iostream>
#include "LegalMove.h"
#include "Card.h"
#include <vector>


HumanPlayer::HumanPlayer()
{
}


HumanPlayer::~HumanPlayer()
{
}

unsigned HumanPlayer::runAI(vector<Card> const& table, vector<Card> const& hand,
	vector<LegalMove> const& legalMoves, vector<Card> const& myPile,
	vector<Card> const& opPile, unsigned myTabbe, unsigned opTabbe)
{
	std::cout << "Table : ";
	for (auto c : table)
	{
		std::cout << c.toString() << ",";
	}
	std::cout << std::endl;
	int i = 0;
	for (auto lm : legalMoves)
	{
		std::cout << "[" << i++ << "] " << lm.toString() << std::endl;
	}
	int select = -1;
	while (select < 0 || select >= i)
	{
		std::cin >> select;
	}
	
	return select;
}