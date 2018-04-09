#pragma once
#include <string>
#include <ostream>

class Card
{
public:
	enum Suit
	{
		SUIT_BEGIN = 0,
		SPADES = 0,
		DIAMONDS,
		CLUBS,
		HEARTS,
		SUIT_END, // 4
		SUIT_BLANK = -1,
	};
	enum Rank
	{
		RANK_BEGIN = 1,
		RANK_A = 1,
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_T,
		RANK_J,
		RANK_Q,
		RANK_K,
		RANK_END,	// 14
		RANK_BLANK = -1,
	};
public:
	Card();
	~Card();
	Card(const int suit, const int rank);
public:
	std::string toString();
	bool operator==(const Card &x);
	bool operator<(const Card &right);
public:
	int m_rank;
	int m_suit;
//private:
	int m_index;
};

