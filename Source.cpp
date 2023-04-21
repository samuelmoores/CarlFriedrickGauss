#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

enum  Health { FULL_HEALTH, HALF_HEALTH, QUARTER_HEALTH };
enum  Ammo { GLOCK_AMMO, COLT45_AMMO, DESERT_EAGLE_AMMO, RAGING_BULL_AMMO };
enum  Armor { LITE, MEDIUM, HEAVY };

enum Sword { DAGGER, LONGSWORD, LEGOLAS_SWORDS, EXCALIBUR };
enum Pistol { GLOCK, COLT45, DESERT_EAGLE, RAGING_BULL };
enum Grenade { FRAG_GRENADE, FLASHBANG, SMOKE, MALOTOV };

enum PistolAttacks { SINGLE_SHOT, MULTIPLE_SHOT, PISTOL_WHIP, THROW_PISTOL };
enum SwordAttacks { QUICK, STRONG, COMBO };
enum GrenadeAttacks { THROW, COOK, SMACK_WITH_GRENADE };


struct Player {
	int rank = 0;
	//std::vector<std::string> RankType = {"You're not too bad", "Getting Better", "Wow, look out!", "You need to touch grass"};
	std::string RankType[4] = { "You're not too bad", "Getting Better", "Wow, look out!", "You need to touch grass" };
	std::string name = "";
	float health = 100.0f;
	float stamina = 50.0f;
	int strength = 50;
	bool isDead;

	int totalScore = 0;
	int scores[3] = { 0, 0, 0 };

	int weaponChoice = 0; 

	Health healthPickup;
	Ammo ammoPickup;
	Armor armorPickup;
	Sword sword;
	Pistol pistol;
	Grenade grenade;
	std::string CurrentRank = RankType[0];
};

struct Enemy {
	std::string name = "";
	float health = 100.0f;
	float stamina = 50.0f;
	int experience = 0;
	Sword sword;
	bool isDead;

	bool isArmed = true;
	int strength = 50;

};

void takeDamage(Player player, int damageAmount)
{
	
}

float takeDamage(Enemy enemy, int damageAmount)
{
	enemy.health -= damageAmount;
	return enemy.health;
}

void firstLevel(Player& Player1)
{
	Enemy enemy1;
	int score = 0;
	std::ofstream outFile;
	std::ifstream inFile;
	int attackChoice;
	bool validAttackChoice = false;

	srand((unsigned)time(NULL));
	int enemyWeapon = rand() % 2 + 0;
	int enemyWeaponType = rand() % 3 + 0;
	enemy1.experience = rand() % 2 + 0;

	std::cout << "-----------------------------------Welcome to level one-----------------------------------------\n\n";
	std::cout << "Enemy has arrived!\n";


	switch (enemyWeapon)
	{
	case 0:
		switch (enemyWeaponType)
		{
		case 0:
			std::cout << "With a dagger!\n";
			enemy1.sword = Sword::DAGGER;

			break;
		case 1:
			std::cout << "With a longsword!\n";
			enemy1.sword = Sword::LONGSWORD;


			break;
		case 2:
			std::cout << "With a legolas swords!\n";
			enemy1.sword = Sword::LEGOLAS_SWORDS;

			break;
		case 3:
			std::cout << "With a excalibur!\n";
			enemy1.sword = Sword::EXCALIBUR;

			break;
		}
		break;
	case 1:
		switch (enemyWeaponType) {
		case 0:
			std::cout << "With a glock!\n";

			break;
		case 1:
			std::cout << "With a colt 45!\n";

			break;
		case 2:
			std::cout << "With a desert eagle!\n";

			break;
		case 3:
			std::cout << "With a raging bull!\n";

			break;
		}
		break;
	case 2:
		switch (enemyWeaponType) {
		case 0:
			std::cout << "With a frag grenade!\n";

			break;
		case 1:
			std::cout << "With a smoke grenade!\n";

			break;
		case 2:
			std::cout << "With a flash bang!\n";

			break;
		case 3:
			std::cout << "With a malotov!\n";

			break;
		}
		break;
	}

	//check enemy experience
	if (enemy1.experience == 0)
	{
		enemy1.strength = 25;

	}
	else if (enemy1.experience == 1)
	{
		enemy1.strength = 50;
	}
	else
	{
		enemy1.strength = 75;
	}

	//player attack choice
	if (Player1.weaponChoice == 0)
	{
		std::cout << "Choose a sword attack!\n (0) Strong (1) Quick";
		std::cin >> attackChoice;

	}

	do {
		if (attackChoice == 1)
		{
			std::cout << "Quick attack!\n";
			enemy1.health -= 10;
			validAttackChoice = true;
		}
		else if (attackChoice == 0)
		{
			std::cout << "Strong Attack!\n";
			enemy1.health -= 100;
			Player1.stamina -= 25;
			enemy1.stamina -= 15;
			validAttackChoice = true;

		}

	} while (!validAttackChoice);
	
	if (enemy1.health <= 0)
	{
		std::cout << "enemy dead!\n";
	}

	if (Player1.isDead)
	{
		firstLevel(Player1)
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

void PlayerSetup(Player& Player1)
{
	int pickupChoice = 0;
	bool pickupChoiceIsValid = true;

	std::cout << "Name your character: " << std::endl;
	std::cin >> Player1.name;
	std::cout << "Your rank: " << Player1.rank << std::endl;

	//PickupChoice
	do {

		std::cout << "Choose a starting pickup: Health(0), Armor(1) or Ammo(2)" << std::endl;
		std::cin >> pickupChoice;

		switch (pickupChoice)
		{
		case 0:
			if (Player1.CurrentRank == Player1.RankType[0]) {
				Player1.healthPickup = Health::QUARTER_HEALTH;
				std::cout << "You're not too bad, so you only get quarter health\n";
				pickupChoiceIsValid = true;
			}
			else if (Player1.CurrentRank == Player1.RankType[1]) {
				std::cout << "You're Getting better, don't have to worry about quarter health anymore." <<
					" Medium Health selected.\n";
				Player1.healthPickup = Health::HALF_HEALTH;

				pickupChoiceIsValid = true;
			}
			else {
				std::cout << "Wow look out or Go touch some grass, you're a high rank and you get full health. As in life apparently the rich get richer.\n";
				Player1.healthPickup = Health::FULL_HEALTH;

				pickupChoiceIsValid = true;
			}
			break;
		case 1:
			if (Player1.CurrentRank == Player1.RankType[0]) {
				std::cout << "You don't really have a choice here I guess. Glock Ammo\n";
				Player1.ammoPickup = Ammo::GLOCK_AMMO;

				pickupChoiceIsValid = true;
			}
			else if (Player1.CurrentRank == Player1.RankType[1]) {
				int AmmoChoice{};
				bool validAmmoChoice;
				do {
					std::cout << "Since you're not rank zero, pick an ammo type for your weapon.\n (0)Glock (1)Colt45 Ammo";

					std::cin >> AmmoChoice;
					switch (AmmoChoice) {
					case 0:
						std::cout << "You have the ability to choose a better gun and you choose the" <<
							" Glock ammo. Interesting\n";
						Player1.ammoPickup = Ammo::GLOCK_AMMO;

						pickupChoiceIsValid = true;
						validAmmoChoice = true;

						break;
					case 1:
						std::cout << "You're getting better, especially in your decision making. Colt45 ammo selceted\n";
						Player1.ammoPickup = Ammo::COLT45_AMMO;

						pickupChoiceIsValid = true;
						validAmmoChoice = true;

						break;
					default:
						std::cout << "Invalid Input please try again";
						validAmmoChoice = false;

					}//switch ammo choice
				} while (!validAmmoChoice);
				

			}// else if - rank 1
			else if (Player1.CurrentRank == Player1.RankType[2]) {
				int AmmoChoice{};
				bool ammoChoiceValid;

				do {
					std::cout << "Since you're rank 2, you have one more chocice\n Pick ammo type for your weapon. (0)Glock (1)Colt45 Ammo (2)Desert Eagle Ammo";
					std::cin >> AmmoChoice;
					switch (AmmoChoice) {
					case 0:
						std::cout << "Seriously? Glock ammo at this juncture? \n";
						Player1.ammoPickup = Ammo::GLOCK_AMMO;

						pickupChoiceIsValid = true;
						ammoChoiceValid = true;
						break;
					case 1:
						std::cout << "Going against the meta, how commendable. Colt 45 ammo selected\n";
						Player1.ammoPickup = Ammo::COLT45_AMMO;

						pickupChoiceIsValid = true;
						ammoChoiceValid = true;
						break;
					case 2:
						std::cout << "Meta slave here we go. Desert Eagle ammo selected\n";
						Player1.ammoPickup = Ammo::DESERT_EAGLE_AMMO;

						pickupChoiceIsValid = true;
						ammoChoiceValid = true;
						break;
					default:
						std::cout << "Invalid Input please try again";
						ammoChoiceValid = false;
					}//switch ammoChoice
				} while (!ammoChoiceValid);

			}//else if - rank 2
			else {
				int AmmoChoice{};
				bool validAmmoChoice;
				do {
					std::cout << "Pick ammo type for your weapon. (0)Glock (1)Colt45 Ammo (2)Desert Eagle Ammo (3)Raging Bull Ammo";

					std::cin >> AmmoChoice;
					switch (AmmoChoice) {
					case 0:
						std::cout << "All these choices, and you decide to pick a glock. \n";
						Player1.ammoPickup = Ammo::GLOCK_AMMO;


						pickupChoiceIsValid = true;
						validAmmoChoice = true;
						break;
					case 1:
						std::cout << "Either you're really good at this game or have some screws loose. Colt 45 selected\n";
						Player1.ammoPickup = Ammo::COLT45_AMMO;

						pickupChoiceIsValid = true;
						validAmmoChoice = true;

						break;
					case 2:
						std::cout << "Somewhat logical. Desert Eagle ammo Selected.\n";
						Player1.ammoPickup = Ammo::DESERT_EAGLE_AMMO;

						pickupChoiceIsValid = true;
						validAmmoChoice = true;

						break;
					case 3:
						std::cout << "Meta slave meta slave meta slave. Raging Bull ammo Selected\n";
						Player1.ammoPickup = Ammo::RAGING_BULL_AMMO;

						pickupChoiceIsValid = true;
						validAmmoChoice = true;

						break;
					default:
						std::cout << "Invalid Input please try again";
						validAmmoChoice = false;

					}
				} while (!validAmmoChoice);
				//switch ammoChoice

			}//else rank 3
			break;
		case 2:
			if (Player1.CurrentRank == Player1.RankType[0]) {
				std::cout << "Light Armor granted.\n";
				Player1.armorPickup = Armor::LITE;

				pickupChoiceIsValid = true;
			}
			else if (Player1.CurrentRank == Player1.RankType[1]) {
				std::cout << "Medium Armor selected.\n";
				pickupChoiceIsValid = true;
			}
			else {
				std::cout << "Heavy armor selected.\n";
				pickupChoiceIsValid = true;
			}
			break;
		default:
			std::cout << "Invalid Number, pick 0, 1 or 2\n";
			pickupChoiceIsValid = false;
		}
	} while (!pickupChoiceIsValid);

	//WeaponChoice
	do {
		

		std::cout << "Choose a weapon: Sword(0), Pistol(1) or Grenade(2)" << std::endl;
		std::cin >> Player1.weaponChoice;

		switch (Player1.weaponChoice)
		{
		case 0:
			if (Player1.CurrentRank == Player1.RankType[0])
			{
				std::cout << "Welcome young padawan! :) You get to start with a dagger!" << std::endl;
				Player1.sword = Sword::DAGGER;
			}
			else if (Player1.CurrentRank == Player1.RankType[1])
			{
				int swordType;
				bool isValid_SwordType = false;
				std::cout << "I see you have moved up in the world, Choose between a Dagger(0) or a Longsword(1)\n";
				std::cin >> swordType;

				do {
					switch (swordType)
					{
					case 0:
						std::cout << "Interesting choice, I assume your depending on skill...\n";
						isValid_SwordType = true;
						break;
					case 1:
						std::cout << "A new weapon! The Longsword... with great power comes great responsibility\n";
						isValid_SwordType = true;
						break;
					default:
						std::cout << "Invalid Sword Type, please choose 0 or 1\n";
					}
				} while (!isValid_SwordType);
			}
			else if (Player1.CurrentRank == Player1.RankType[2])
			{

			}
		//case 1:

		}

	} while (!pickupChoiceIsValid);

	int playerChoice = 0;

	bool weaponSlected = false;



	
}

void MainMenu(Player Player1)
{
	PlayerSetup(Player1);
	bool validInput = false;
	int levelOnePlayChoice;

	do {

		std::cout << "Start Level 1? (1) yes (0) no: ";
		std::cin >> levelOnePlayChoice;

		if (levelOnePlayChoice == 1)
		{
			firstLevel(Player1);
			validInput = true;
		}
		else if (levelOnePlayChoice == 0)
		{
			validInput = true;
		}
		else
		{
			std::cout << "Invalid Input, choose 1 or 0\n";
		}

	} while (!validInput);



}

int main()
{
	Player Player1;
	bool isPlaying = false;
	
	MainMenu(Player1);


	return 0;

}