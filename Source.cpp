#include <iostream>
#include <string>
#include <time.h>

enum class Pickups { HEALTH, AMMO, ARMOR };
enum class SpecialPickups{SHIELD, SUPERHEALTH, AMMO};
enum class Weapons { SWORD, PISTOL, GRENADE };


struct Player {
	int rank = 0;
	std::string name = "";
	float health = 100.0f;
	Pickups pickup;
	Weapons weapon;
};

struct Enemy {
	std::string name = "";
	float health = 100.0f;

	Weapons weapon;

};

float takeDamage(Player player, int damageAmount)
{
	player.health -= damageAmount;
	return player.health;
}

float takeDamage(Enemy enemy, int damageAmount)
{
	enemy.health -= damageAmount;
	return enemy.health;
}

void firstLevel(int& totalScore, Player Player1)
{
	Enemy enemy1;
	int score = 0;
	srand((unsigned)time(NULL));
	int enemyWeapon = rand() % 4 + 0;

	std::cout << "Welcome to level one\n";
	std::cout << "Enemy has arrived with a ";

	switch (enemyWeapon)
	{
	case 0:
		enemy1.weapon = Weapons::SWORD;
		std::cout << "Sword!\n";
		break;
	case 1:
		enemy1.weapon = Weapons::PISTOL;
		std::cout << "Pistol!\n";
		break;
	case 2:
		enemy1.weapon = Weapons::GRENADE;
		std::cout << "Grenade!\n";
		break;
	}

	
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

	int playerChoice = 0;

	bool weaponSlected = false;

	do {
		std::cout << "An enemy has arrived! Pick a weapon!\n";
		std::cout << "(0)Sword (1)Pistol (2)Grenade\n";
		std::cin >> playerChoice;

		if (0 == playerChoice)
		{
			Player1.weapon = Weapons::SWORD;
			weaponSlected = true;
			std::cout << "You chose a sword!\n";
		}
		else if (1 == playerChoice)
		{
			Player1.weapon = Weapons::PISTOL;
			weaponSlected = true;
			std::cout << "You chose a Pistol!\n";

		}
		else //check player's number for less than or greater than random 
		{
			Player1.weapon = Weapons::GRENADE;
			weaponSlected = true;
			std::cout << "You chose a Grenade!\n";

		}

	} while (!weaponSlected);


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