#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include "Weapon.h"
#include "Sword.h"
#include "Player.h"


enum Pistol { GLOCK, COLT45, DESERT_EAGLE, RAGING_BULL };
enum Grenade { FRAG_GRENADE, FLASHBANG, SMOKE, MALOTOV };


struct PickupsStruct {
	enum  Health { FULL_HEALTH, HALF_HEALTH, QUARTER_HEALTH };
	enum  AMMO { GLOCK_AMMO, COLT45_AMMO, DESERT_EAGLE_AMMO, RAGING_BULL_AMMO};
	enum  ARMOR { LITE, MEDIUM, HEAVY };

};


struct Attacks {

	enum Pistol { SINGLE_SHOT, MULTIPLE_SHOT, PISTOL_WHIP, THROW_PISTOL };
	enum Sword { QUICK, STRONG, COMBO };
	enum Grenade { THROW, COOK, SMACK_WITH_GRENADE };

};

class Character {

	public:

		int health;

		void setShield()
		{

		}

		void getShield()
		{

		}

	private:

		int shield;

};


struct PlayerStruct {
	int rank = 3;
	//std::vector<std::string> RankType = {"You're not too bad", "Getting Better", "Wow, look out!", "You need to touch grass"};
	std::string Ranks[4] = { "You're not too bad", "Getting Better", "Wow, look out!", "You need to touch grass" };
	const int RanksSize = 4;
	std::string name = "";
	float health = 100.0f;
	float stamina = 50.0f;
	int pickupType;
	int pickupTypeMax = 2;
	const int pickupSize = 3;
	const int pickupTypeSize = 4;
	
	std::string Pickup;

	float* healthPointer = &health;

	int weaponChoice = 0;

	Sword sword;

	Pistol Pistol;
	Grenade Grenade;

	Attacks attacks;
	std::string CurrentRank = Ranks[3];

	std::string Pickups[3][4] = {""};

	std::string HealthPickups[3] = { "QuaterHealth", "HalfHealth", "FullHealth" };

	std::string HealthPickip;


};

struct Enemy {
	std::string name = "";
	float health = 100.0f;
	float stamina = 50.0f;
	
	Attacks attacks;
	int experience = 0;

	bool isArmed = true;

};



float takeDamage(Enemy enemy, int damageAmount)
{
	enemy.health -= damageAmount;
	return enemy.health;
}

void firstLevel()
{
	Enemy enemy1;
	std::ofstream outStream;

	std::vector<int> playerWeapons = { 0, 1, 2, 3 };

	int score = 0;

	srand((unsigned)time(NULL));
	int enemyWeapon = rand() % 4 + 0;

	std::cout << "Welcome to level one\n";
	std::cout << "Here's one point!\n";
	score++;

	std::cout << "Enemy's weapon is a level " << enemyWeapon << std::endl;

	for (int i = 0; i < playerWeapons.size(); i++)
	{
		if (enemyWeapon == i)
		{
			std::cout << "Player and Enemy weapons match! It's a draw!";
			std::cout << "No points awarded!";

		}
	}

	outStream.open("LevelOneData.txt");

	outStream << score;
	
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


void PlayerSetup()
{
	
	int playerRank = 0;
	int pickupChoice = 0;
	bool pickupChoiceIsValid = false;
	//Pickups pickup;
	const int PickupsSize = 3;
	std::string Pickups[3] = { "Health", "Armor", "Ammo" };
	std::string PickupMessages[3] = { "Health is wealth!", "Stay strong.", "Shots about to be fired"};
	std::string RankMessages[4] = { "Just getting started!", "You're getting better.", "Wow, you need to touch grass." };
	std::cout << "Name your character: " << std::endl;
	


	//PickupChoice
	do {
		
		std::cout << "Health(0), Armor(1) or Ammo(2)?" << std::endl;
		std::cin >> pickupChoice;
		/*
		for (int i = 0; i < Player1.RanksSize; i++)
		{
			if (Player1.rank == i)
			{
				for (int j = 0; j < PickupsSize; j++)
				{
					if (pickupChoice == j)
					{
						Player1.Pickup = Pickups[j];
						std::cout << PickupMessages[j] << std::endl;
						pickupChoiceIsValid = true;
					}
				}
			}
		}
		*/

	} while (!pickupChoiceIsValid);
	

	/* add more stuff add more stuff*/
}


int main()
{
	Player player;

	player.Damage(15);


	

	return 0;
}