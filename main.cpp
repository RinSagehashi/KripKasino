
#include "stdafx.h"
#include <Windows.h>
#include "Kasino.h"
#include "AI_Test.h"
#include "HumanPlayer.h"
#include <iostream>
#include "AI_Random.h"
#include "AI_PlayHighest.h"
#include <string>
#include <algorithm>
#include "AI_Template.h"
// AI_Test : Only return 0
// HumanPlayer : Human select Legal Move
// AI_Random : Random select

int main()
{
	Player *AI_1 = new AI_Template();
	Player *AI_2 = new AI_Random();

	Kasino kasino(AI_1, AI_2);
	
	std::cout << "Number of matches =";
	int gameCnt = 0;
	while (gameCnt <= 0)
	{
		std::string str;
		std::cin >> str;
		if (std::all_of(str.cbegin(), str.cend(), isdigit))
		{
			try
			{
				gameCnt = std::stoi(str);
			}
			catch (std::out_of_range& oor)
			{
				gameCnt = 0;
				continue;
			}
		}
	}

	int winCnt = 0;
	for (int i = 0; i < gameCnt/2; ++i)
	{
		if (kasino.game(0) == 0)
			winCnt++;
		if (kasino.game(1) == 0)
			winCnt++;
	}
	std::cout << "[1] " << AI_1->getName() << " : " << winCnt << " WIN" << std::endl;
	std::cout << "[2] " << AI_2->getName() << " : " << gameCnt - winCnt << " WIN" << std::endl;
	
	Sleep(5000);
	system("PAUSE");
	return 0;
}