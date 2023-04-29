#include <iostream>
#include <string>
#include <time.h>
#include <vector>

struct Pickups {
	enum  Health { FULL_HEALTH, HALF_HEALTH, QUARTER_HEALTH };
	enum  AMMO { GLOCK_AMMO, COLT45_AMMO, DESERT_EAGLE_AMMO, RAGING_BULL_AMMO};
	enum  ARMOR { LITE, MEDIUM, HEAVY };

};

struct Weapons {
	enum Sword {LONGSWORD, DAGGER, LEGOLAS_SWORDS, EXCALIBUR };
	enum Pistol {GLOCK, COLT45, DESERT_EAGLE, RAGING_BULL};
	enum Grenade {FRAG_GRENADE, FLASHBANG, SMOKE, MALOTOV};


};

struct Attacks {

	enum Pistol { SINGLE_SHOT, MULTIPLE_SHOT, PISTOL_WHIP, THROW_PISTOL };
	enum Sword { QUICK, STRONG, COMBO };
	enum Grenade { THROW, COOK, SMACK_WITH_GRENADE };

};


struct Player {
	int rank = 0;
	//std::vector<std::string> RankType = {"You're not too bad", "Getting Better", "Wow, look out!", "You need to touch grass"};
	std::string RankType[4] = { "You're not too bad", "Getting Better", "Wow, look out!", "You need to touch grass" };
	std::string name = "";
	float health = 100.0f;
	float stamina = 50.0f;

	int weaponChoice = 0; 

	Pickups pickup;
	Weapons weapon;
	Attacks attacks;
	std::string CurrentRank = RankType[3];
};

struct Enemy {
	std::string name = "";
	float health = 100.0f;
	float stamina = 50.0f;
	Weapons weapon;
	Attacks attacks;
	int experience = 0;

	bool isArmed = true;

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
	int enemyWeaponType = rand() % 4 + 0;
	enemy1.experience = rand() % 2 + 0;

	std::cout << "Welcome to level one\n";
	std::cout << "Enemy has arrived with a ";

	switch (enemyWeapon)
	{
	case 0:
		switch (enemyWeaponType)
		{
		case 0:
			enemy1.weapon.Sword::DAGGER;
			break;
		case 1:
			enemy1.weapon.Sword::LONGSWORD;
			break;
		case 2:
			enemy1.weapon.Sword::LEGOLAS_SWORDS;
			break;
		case 3:
			enemy1.weapon.Sword::EXCALIBUR;
			break;
		}
		break;
	case 1:
		switch (enemyWeaponType) {
		case 0:
			enemy1.weapon.Pistol::GLOCK;
			break;
		case 1:
			enemy1.weapon.Pistol::COLT45;
			break;
		case 2:
			enemy1.weapon.Pistol::DESERT_EAGLE;
			break;
		case 3:
			enemy1.weapon.Pistol::RAGING_BULL;
			break;
		}
		break;
	case 2:
		switch (enemyWeaponType) {
		case 0:
			enemy1.weapon.Grenade::FRAG_GRENADE;
			break;
		case 1:
			enemy1.weapon.Grenade::SMOKE;
			break;
		case 2:
			enemy1.weapon.Grenade::FLASHBANG;
			break;
		case 3:
			enemy1.weapon.Grenade::MALOTOV;
			break;
		}
		break;
	}

	if (enemy1.experience == 0)
	{

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

void PlayerSetup(Player Player1)
{
	int playerRank = 0;
	int pickupChoice = 0;
	bool pickupChoiceIsValid = true;
	Pickups pickup;

	std::cout << "Name your character: " << std::endl;
	std::cin >> Player1.name;

	//PickupChoice
	do {

		std::cout << "Health(0), Armor(1) or Ammo(2)?" << std::endl;
		std::cin >> pickupChoice;

		switch (pickupChoice)
		{
		case 0:
			if (Player1.CurrentRank == Player1.RankType[0]) {
				Player1.pickup.Pickups::QUARTER_HEALTH;
				std::cout << "You're not too bad, so you only get quarter health\n";
				pickupChoiceIsValid = true;
			}
			else if (Player1.CurrentRank == Player1.RankType[1]) {
				Player1.pickup.Pickups::HALF_HEALTH;
				std::cout << "You're Getting better, as in life apparently the rich get richer." <<
					" Medium Health selected.\n";
				pickupChoiceIsValid = true;
			}
			else {
				Player1.pickup.Pickups::FULL_HEALTH;
				std::cout << "Wow look out or Go touch some grass, Full Health for you I guess.\n";
				pickupChoiceIsValid = true;
			}
			break;
		case 1:
			if (Player1.CurrentRank == Player1.RankType[0]) {
				Player1.pickup.Pickups::GLOCK_AMMO;
				std::cout << "You don't really have a choice here I guess. Glock Ammo\n";
				pickupChoiceIsValid = true;
			}
			else if (Player1.CurrentRank == Player1.RankType[1]) {
				int AmmoChoice{};
				std::cout << "Pick ammo type for your weapon. 0) Glock 1) Colt45 Ammo";
				std::cin >> AmmoChoice;
				switch (AmmoChoice) {
				case 0:
					std::cout << "You have the ability to choose a better gun and you choose the" <<
						" Glock ammo. Interesting\n";
					Player1.pickup.Pickups::GLOCK_AMMO;
					pickupChoiceIsValid = true;
					break;
				case 1:
					std::cout << "You're getting better, especially in your decision making. Colt45 ammo selceted\n";
					Player1.pickup.Pickups::COLT45_AMMO;
					pickupChoiceIsValid = true;
					break;
				default:
					std::cout << "Invalid Input please try again";
				}
			}
			else if (Player1.CurrentRank == Player1.RankType[2]) {
				int AmmoChoice{};
				std::cout << "Pick ammo type for your weapon. 0) Glock 1) Colt45 Ammo 2) Desert Eagle Ammo";
				std::cin >> AmmoChoice;
				switch (AmmoChoice) {
				case 0:
					std::cout << "Seriously? Glock ammo at this juncture? \n";
					Player1.pickup.Pickups::GLOCK_AMMO;
					pickupChoiceIsValid = true;
					break;
				case 1:
					std::cout << "Going against the meta, how commendable. Colt 45 ammo selected\n";
					Player1.pickup.Pickups::COLT45_AMMO;
					pickupChoiceIsValid = true;
					break;
				case 2:
					std::cout << "Meta slave here we go. Desert Eagle ammo selected\n";
					Player1.pickup.Pickups::DESERT_EAGLE_AMMO;
					pickupChoiceIsValid = true;
					break;
				default:
					std::cout << "Invalid Input please try again";
				}
			}
			else {
				int AmmoChoice{ Player1.CurrentRank == Player1.RankType[3] };
				std::cout << "Pick ammo type for your weapon. 0) Glock 1) Colt45 Ammo 2) Desert Eagle Ammo";
				std::cin >> AmmoChoice;
				switch (AmmoChoice) {
				case 0:
					std::cout << "All these choices, and you decide to pick a glock. \n";
					Player1.pickup.Pickups::GLOCK_AMMO;
					pickupChoiceIsValid = true;
					break;
				case 1:
					std::cout << "Either you're really good at this game or have some screws loose. Colt 45 selected\n";
					Player1.pickup.Pickups::COLT45_AMMO;
					pickupChoiceIsValid = true;
					break;
				case 2:
					std::cout << "Somewhat logical. Desert Eagle ammo Selected.\n";
					Player1.pickup.Pickups::DESERT_EAGLE_AMMO;
					pickupChoiceIsValid = true;
					break;
				case 3:
					std::cout << "Meta slave meta slave meta slave. Raging Bull ammo Selected\n";
					Player1.pickup.Pickups::RAGING_BULL_AMMO;
					pickupChoiceIsValid = true;
					break;
				default:
					std::cout << "Invalid Input please try again";
				}
			}
			break;
		case 2:
			if (Player1.CurrentRank == Player1.RankType[0]) {
				std::cout << "Light Armor granted.\n";
				Player1.pickup.Pickups::LITE;
				pickupChoiceIsValid = true;
			}
			else if (Player1.CurrentRank == Player1.RankType[1]) {
				std::cout << "Medium Armor selected.\n";
				Player1.pickup.Pickups::MEDIUM;
				pickupChoiceIsValid = true;
			}
			else {
				std::cout << "Heavy armor selected. Congrats\n";
				Player1.pickup.Pickups::HEAVY;
				pickupChoiceIsValid = true;
			}
			break;
		default:
			std::cout << "Invalid Number, pick 0, 1 or 2\n";
			pickupChoiceIsValid = false;
		}
	} while (!pickupChoiceIsValid);

	int playerChoice = 0;

	bool weaponSlected = false;

	//Weapon Choice
	do {
		std::cout << "Pick a weapon!\n";
		std::cout << "(0)Sword (1)Pistol (2)Grenade\n";
		std::cin >> playerChoice;
		int playerChoice2{ 0 };

		if (Player1.CurrentRank == Player1.RankType[0])
		{
			switch (playerChoice)
			{
			case 0:
				Player1.weapon.Sword::DAGGER;
				//
			}
		}

	} while (!weaponSlected);

	/* add more stuff add more stuff*/
}

int main()
{
	bool isPlaying = false;
	int totalScore = 0;
	Player Player1;


	int keepPlaying = 0;

	int scores[3] = {0, 0, 0};

	std::cout << "Welcome to the Game\n";
	isPlaying = true;

	PlayerSetup(Player1);

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