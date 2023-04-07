#include <iostream>
#include <string>
#include <time.h>

enum class Pickups { HEALTH, AMMO, ARMOR };
enum class SpecialPickups{SHIELD, SUPERHEALTH, AMMO};

struct Player {
	int rank = 0;
	std::string name = "";
	float health = 100.0f;
	Pickups pickup;
};

struct Enemy {
	std::string name = "";
	float health = 100.0f;

	enum class Weapons { SWORD, PISTOL, GRENADE};


};

void firstLevel(int& totalScore)
{
	int score = 0;
	std::cout << "Welcome to level one\n";
	int playerChoice = 0;
	srand((unsigned)time(NULL));

	//gameplay
	//get a random number
	
	int random = rand() % 15 + 1;

	std::cout << "A random number from 1-15 has been choosen\n";
	std::cout << "Try to guess it\n";

	bool numberFound = false;


	do {
		//check random number against player's number

		std::cout << "Enter a number(1-15): ";
		std::cin >> playerChoice;

		if (random == playerChoice)
		{
			std::cout << "You win! The number was: " << random;
			numberFound = true;
		}
		else if (playerChoice > random)
		{
			std::cout << "You're above, try going lower\n";
		}
		else //check player's number for less than or greater than random 
		{
			std::cout << "You're below, try going higher\n";
		}

		//give hint's based on the size of the difference
		std::cout << "The difference is: " << (random - playerChoice) << std::endl;

	} while (!numberFound);
	
	//do math operations with random number and only tell user 2 out of the 3 numbers used

	std::cout << "I heard that 2+2=4, very interesting I would like to know more\n";

	//no return
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
	int playerRank = 0;
	int totalScore = 0;
	int pickupChoice = 0;
	bool pickupChoiceIsValid = true;
	int keepPlaying = 0;


	int scores[3] = {0, 0, 0};

	Player Player1;
	Pickups pickup;

	

	std::cout << "Welcome to the Game\n";
	isPlaying = true;

	std::cout << "Name your character: " << std::endl;
	std::cin >> Player1.name;

	do{

	std::cout << "Health(0), Armor(1) or Ammo(2)?" << std::endl;
	std::cin >> pickupChoice;

	switch (pickupChoice)
	{
	case 0:
		pickup = Pickups::HEALTH;
		pickupChoiceIsValid = true;

		break;
	case 1:
		pickup = Pickups::ARMOR;
		pickupChoiceIsValid = true;

		break;
	case 2:
		pickup = Pickups::ARMOR;
		pickupChoiceIsValid = true;

		break;
	default:
		std::cout << "Invalid Number, pick 0, 1 or 2\n";
		pickupChoiceIsValid = false;
	}
	} while (!pickupChoiceIsValid);

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
		firstLevel(totalScore);

		//output game data to a file
	}
	else if (keepPlaying == 2)
	{
		
	}

	return 0;

}