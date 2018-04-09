#include "stdafx.h"
#include "Kasino.h"
#include <iostream>
#include "Rule.h"
#include <algorithm>
#include "LegalMove.h"
#include "AI_Test.h"
#include "HumanPlayer.h"

using std::cout;
using std::endl;
using std::vector;

Kasino::Kasino()
{
}

Kasino::Kasino(Player * AI_1, Player * AI_2)
{
	m_AI.push_back(AI_1);
	m_AI.push_back(AI_2);
}


Kasino::~Kasino()
{
}

unsigned Kasino::game(unsigned dealer)
{
	m_point[PL1] = 0;
	m_point[PL2] = 0;
	unsigned dlr = dealer;
	while ((m_point[PL1] < 16 && m_point[PL2] < 16) || m_point[PL1]==m_point[PL2])
	{
		initializeGame();
		for (auto turn = 0u; turn < 6; ++turn)
		{
			beginTurn();
			for (auto phase = 0u; phase < 4; ++phase)
			{
				//for (int pl = PL1; pl < N_PL; ++pl)
				auto pl = dlr;
				do
				{
					//cout << m_AI[pl]->getName() << endl;
					vector<LegalMove> LMs = Rule::getLegalMoves(m_table, m_hand[pl]);
					auto myPile = m_pile[pl];
					auto opPile = m_pile[pl ^ 1u];
					auto myTabbe = m_tabbe[pl];
					auto opTabbe = m_tabbe[pl ^ 1u];
					int LM_index = m_AI[pl]->runAI(m_table, m_hand[pl], LMs, myPile, opPile, myTabbe, opTabbe);
					auto lm = LMs[LM_index];
					//cout << lm.toString() << endl;
					playLegalMove(lm, pl);
					if (m_table.size() == 0)
					{
						m_tabbe[pl]++;
					}
					pl = pl ^ 1u;
				} while (pl != dlr);
			}
		}
		finalizeGame();
		dlr = dlr ^ 1u;
		/*
		for (int i = PL1; i < N_PL; ++i)
		{
			cout << "PL" << i << ": " << m_AI[i]->getName() << endl;
			cout << "PILE: " << m_pile[i].size() << endl;
			cout << "TABBE: " << m_tabbe[i] << endl;
			cout << "POINT: " << m_point[i] << endl;
		}
		*/
	}

	return (m_point[PL1] > m_point[PL2]) ? PL2 : PL1;
}

void Kasino::initializeGame()
{
	m_table.clear();
	m_deck.reset();
	
	for (int i = 0; i < 4; ++i)
	{
		m_table.push_back(m_deck.deal());
	}
	for (int pl = PL1; pl < N_PL; ++pl)
	{
		m_hand[pl].clear();
		m_pile[pl].clear();
		m_tabbe[pl] = 0;
	}
}

void Kasino::finalizeGame()
{
	for (auto c : m_table)
	{
		m_pile[m_lastCapturePlayer].push_back(c);
	}
	m_table.clear();
	for (unsigned pl = PL1; pl < N_PL; ++pl)
	{
		m_point[pl] += Rule::evalPilePoint(m_pile[pl]);
		m_point[pl] += m_tabbe[pl];
	}

}

void Kasino::beginTurn()
{
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 0; i < N_PL; ++i)
		{
			m_hand[i].push_back(m_deck.deal());
		}
	}
}

void Kasino::print()
{
	cout << "Table : ";
	for (auto c : m_table)
	{
		cout << c.toString() << ",";
	}
	cout << endl;
	for (auto i = 0; i < static_cast<int>(N_PL); ++i)
	{
		cout << "PL[" << i << "] : ";
		for (auto c : m_hand[i])
		{
			cout << c.toString() << ",";
		}
		cout << endl;
	}
}

void Kasino::playLegalMove(LegalMove const legalMove, unsigned playerNumber)
{
	Card playedCard = legalMove.m_playedCard;
	auto capturedCards = legalMove.m_capturedCards;

	std::remove(m_hand[playerNumber].begin(), m_hand[playerNumber].end(), playedCard);
	m_hand[playerNumber].pop_back();
	if (capturedCards.size() == 0)
	{
		m_table.push_back(playedCard);
		return;
	}
	m_lastCapturePlayer = playerNumber;
	m_pile[playerNumber].push_back(playedCard);
	for (auto const c : capturedCards)
	{
		std::remove(m_table.begin(), m_table.end(), c);
		m_table.pop_back();
		m_pile[playerNumber].push_back(c);
	}
}
