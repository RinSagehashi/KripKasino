#include "stdafx.h"
#include "Rule.h"
#include <vector>
#include "LegalMove.h"
#include "Card.h"
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <utility>
#include <iostream>
#include <array>
#include <algorithm>

using std::bitset;
using std::vector;
using std::unordered_map;
using std::array;

std::vector<LegalMove> Rule::getLegalMoves(const std::vector<Card> table, const std::vector<Card> hand)
{
	vector<LegalMove> LegalMoves;
	//unordered_multimap<int, bitset<16>> hash{};
	unordered_map<int, vector<bitset<16>>> hash;
	vector<int> hand_numbers;
	for (auto i = 0u; i < hand.size(); ++i)
	{
		hand_numbers.push_back(hand[i].m_rank);
	}
	std::sort(hand_numbers.begin(), hand_numbers.end());
	auto itr = std::unique(hand_numbers.begin(), hand_numbers.end());
	hand_numbers.erase(itr, hand_numbers.end());
	for (auto i : hand_numbers)
	{
		hash.insert({ i, vector<bitset<16>>() });
	}
	for (int i = 0; i < pow(2, table.size()); ++i)
	{
		bitset<16> bs(i);
		int sum = 0;
		vector<Card> capturedCards;
		
		for (auto j = 0u; j < table.size(); ++j)
		{
			if (bs[j])
			{
				sum += table[j].m_rank;
			}
		}
		for (const auto n : hand_numbers)
		{
			if (n == static_cast<int>(Card::RANK_A))
			{
				if (sum == 14)
					hash[1].push_back(bs);
				if (sum == 1)
					hash[1].push_back(bs);
			}
			else
			{
				if (sum == n)
					hash[n].push_back(bs);
			}
		}
	}
	bool tabbe = false;
	for (auto n : hand_numbers)
	{
		vector<bitset<16>> v = getCombineBits(hash.at(n));
		hash[n] = v;
		for (auto bs : hash[n])
		{
			if (bs.count() == table.size())
				tabbe = true;
		}
	}
	for (auto n : hand_numbers)
	{
		for (auto c : hand)
		{
			if (c.m_rank == n)
			{
				if (hash[n].size() == 0)
				{
					if (tabbe == false)
						LegalMoves.push_back(LegalMove(c, vector<Card>()));
					continue;
				}
				for (auto bs : hash[n])
				{
					vector<Card> capturedCards;
					if (tabbe)
					{
						if (bs.count() == table.size())
						{
							capturedCards = bits2Cards(bs, table);
							LegalMoves.push_back(LegalMove(c, capturedCards));
						}
					}
					else
					{
						capturedCards = bits2Cards(bs, table);
						LegalMoves.push_back(LegalMove(c, capturedCards));
					}
				}
			}
		}
	}
	return LegalMoves;
}

unsigned Rule::evalCardPoint(Card card)
{
	if (card == Card(Card::DIAMONDS, Card::RANK_T))
	{
		return 2;
	}
	if (	card == Card(Card::SPADES, Card::RANK_2)
		||	card.m_rank == Card::RANK_A)
	{
		return 1;
	}
	return 0;
}

unsigned Rule::evalPilePoint(std::vector<Card> cards)
{
	unsigned sum = 0;
	unsigned spadeCount = 0;
	for (auto c : cards)
	{
		if (c.m_suit == Card::SPADES)
		{
			spadeCount++;
		}
		sum += evalCardPoint(c);
	}
	if (spadeCount >= 7)
	{
		sum += 2;
	}
	if (cards.size() >= 27)
	{
		sum += 1;
	}
	return sum;
}

bool Rule::isCapturable(const std::vector<Card> capturedCards, const Card playedCard)
{
	int pRank = playedCard.m_rank;
	if (pRank == static_cast<int>(Card::RANK_A))
	{
		pRank = 14;
	}

	return false;
}

std::vector<bitset<16>> Rule::getCombineBits(std::vector<bitset<16>> bitsets)
{
	vector<bitset<16>> vec;
	for (auto i = 0u; i < bitsets.size(); ++i)
	{
		bool flg = true;
		for (auto j = 0u; j < bitsets.size(); ++j)
		{
			if ((bitsets[i] & bitsets[j]).none())
			{
				if (i <= j)
				{
					vec.push_back(bitsets[i] | bitsets[j]);
				}
					
				flg = false;
			}
		}
		if (flg)
		{
			vec.push_back(bitsets[i]);
		}
	}
	if (bitsets.size() == vec.size())
		return vec;
	else
		return getCombineBits(vec);
}

std::vector<Card> Rule::bits2Cards(std::bitset<16> bs, std::vector<Card> table)
{
	vector<Card> vec;
	for (auto i = 0u; i < table.size(); ++i)
	{
		if (bs[i])
		{
			vec.push_back(table[i]);
		}
	}
	return vec;
}
