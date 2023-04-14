#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "CombatLogic.h"

void firstLevel(int& totalScore, Player Player1)
{
	Enemy enemy1;
	int score = 0;



	std::cout << "Welcome to level one\n";
	std::cout << "Enemy has arrived with a ";
	enemy1.ArmEnemy(enemy1);
	Resolution(Player1, enemy1);

}

void secondLevel(int& totalScore, int scores[])
{
	int score = 0;

	std::cout << "welcome to level two\n";

	//gameplay
	//get a random number

	//check random number against player's number

	//check player's number for less than or greater than random

	//give hint's based on the size of the difference

	//do math operations with random number and only tell user 2 out of the 3 numbers used

	scores[1] = score;


}

int thirdLevel(int& totalScore, int scores[])
{
	int score = 0;

	std::cout << "welcome to level one\n";

	for (int i = 0; i < 10; i++)
	{
		score++;
		totalScore++;

	}

	return score;
}

int main()
{
	bool isPlaying = false;
	int totalScore = 0;
	Player Player1;


	int keepPlaying = 0;

	int scores[3] = { 0, 0, 0 };
	std::cout << "Welcome to the Game\n";
	isPlaying = true;

	Player1.SetDifficulty(Player1);
	Player1.PlayerSetup(Player1);
	
	do
	{
		std::cout << "Are you ready to start playing? (1)yes or (2)no";
		std::cin >> keepPlaying;

		if (keepPlaying == 1)
		{
			isPlaying = true;
		}
		else if (keepPlaying == 2)
		{
			isPlaying = true;
		}
		else
		{
			isPlaying = false;
		}

	} while (!isPlaying);

	//
	if (keepPlaying == 1)
	{
		//play levels
		firstLevel(totalScore, Player1);

		//output game data to a file
	}
	else if (keepPlaying == 2)
	{

	}

	return 0;

}