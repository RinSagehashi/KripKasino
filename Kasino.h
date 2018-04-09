#pragma once
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "LegalMove.h"
#include "Player.h"
#include "AI_Test.h"
#include <array>
#include <memory>
class Kasino
{
public:
	enum player
	{
		PL1,
		PL2,
		N_PL, // 2
	};
public:
	Kasino();
	Kasino(Player* AI_1, Player* AI_2);
	~Kasino();
public:
	unsigned game(unsigned dealer);
private:
	void initializeGame();
	void finalizeGame();
	void beginTurn();
	void print();
	void playLegalMove(LegalMove const legalMove, unsigned const playerNumber);
private:
	std::vector<Card> m_table;
	std::vector<Card> m_hand[N_PL];
	std::vector<Card> m_pile[N_PL];
	unsigned m_tabbe[N_PL];
	Deck m_deck;
	std::vector<Player*> m_AI;
	unsigned m_lastCapturePlayer;
	unsigned m_point[N_PL];
};

