#include "Player.h"
#include "Enemy.h"
#include <random>


auto const seed = std::random_device ()();
std::mt19937 rng(seed);


void Player::SetDifficulty(Player& player1)
{
	int difficulty{};
	std::cout << "Choose your rank 0) You're not bad 1)Getting Better 2) Wow look out 3) Touch Grass\n";
	std::cin >> difficulty;
	switch (difficulty) {
	case 0:
		player1.CurrentRank = player1.RankType[0];
		std::cout << "You're not too bad\n";
		break;
	case 1:
		player1.CurrentRank = player1.RankType[1];
		std::cout << "Getting Better\n";
		break;
	case 2:
		player1.CurrentRank = player1.RankType[2];
		std::cout << "Wow you're good.\n";
		break;
	case 3:
		player1.CurrentRank = player1.RankType[3];
		std::cout << "Go touch some grass\n";
		break;
	default:
		std::cout << "Enter a valid input you sap.\n";
	}

}

void Player::PlayerSetup(Player& Player1)
{
	int playerRank = 0;
	int pickupChoice = 0;
	bool pickupChoiceIsValid = true;


	std::cout << "Name your character: " << std::endl;
	std::cin >> Player1.name;

	//PickupChoice
	do {

		std::cout << "Health(0), Ammo (1) or Armor (2)?" << std::endl;
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
				Player1.glockammo += 20;
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
					Player1.glockammo = { 20 };
					pickupChoiceIsValid = true;
					break;
				case 1:
					std::cout << "You're getting better, especially in your decision making. Colt45 ammo selceted\n";
					Player1.pickup.Pickups::COLT45_AMMO;
					Player1.colt45ammo =  20;
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
					Player1.glockammo += 20;
					pickupChoiceIsValid = true;
					break;
				case 1:
					std::cout << "Going against the meta, how commendable. Colt 45 ammo selected\n";
					Player1.pickup.Pickups::COLT45_AMMO;
					Player1.colt45ammo += 20;
					pickupChoiceIsValid = true;
					break;
				case 2:
					std::cout << "Meta slave here we go. Desert Eagle ammo selected\n";
					Player1.pickup.Pickups::DESERT_EAGLE_AMMO;
					Player1.DEammo += 12;
					pickupChoiceIsValid = true;
					break;
				default:
					std::cout << "Invalid Input please try again";
				}
			}
			else {
				int AmmoChoice{ Player1.CurrentRank == Player1.RankType[3] };
				std::cout << "Pick ammo type for your weapon. 0) Glock 1) Colt45 Ammo 2) Desert Eagle Ammo 3) Raging Bull Ammo";
				std::cin >> AmmoChoice;
				switch (AmmoChoice) {
				case 0:
					std::cout << "All these choices, and you decide to pick a glock. \n";
					Player1.pickup.Pickups::GLOCK_AMMO;
					Player1.glockammo += 20;
					pickupChoiceIsValid = true;
					break;
				case 1:
					std::cout << "Either you're really good at this game or have some screws loose. Colt 45 selected\n";
					Player1.pickup.Pickups::COLT45_AMMO;
					Player1.colt45ammo += 20;
					pickupChoiceIsValid = true;
					break;
				case 2:
					std::cout << "Somewhat logical. Desert Eagle ammo Selected.\n";
					Player1.pickup.Pickups::DESERT_EAGLE_AMMO;
					Player1.DEammo += 12;
					pickupChoiceIsValid = true;
					break;
				case 3:
					std::cout << "Meta slave meta slave meta slave. Raging Bull ammo Selected\n";
					Player1.pickup.Pickups::RAGING_BULL_AMMO;
					Player1.ragingammo += 12;
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
				Player1.defense += 10;
				Player1.pickup.Pickups::LITE;
				pickupChoiceIsValid = true;
			}
			else if (Player1.CurrentRank == Player1.RankType[1]) {
				std::cout << "Medium Armor selected.\n";
				Player1.defense += 20;
				Player1.pickup.Pickups::MEDIUM;
				pickupChoiceIsValid = true;
			}
			else {
				std::cout << "Heavy armor selected.\n";
				Player1.defense += 40;
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
				std::cout << "You don't really have a choice here a dagger for you! " <<
					"Keep the pointed end at your enemy and not at yourself.\n";
				weaponSlected = true;
				break;

			case 1:
				Player1.weapon.Pistol::GLOCK;
				std::cout << "You really don't have a choice here, you selected glock." <<
					"Beats using a knife or does it?\n";
				weaponSlected = true;
				break;
			case 2:
				Player1.weapon.Grenade::FRAG_GRENADE;
				std::cout << " I really hope you don't blow yourself up with this. But " <<
					"here you go a frag grenade. Doesn't explode like it does in the movies.\n";
				weaponSlected = true;
			}

		}
		else if (Player1.CurrentRank == Player1.RankType[1]) {

			switch (playerChoice) {
			case 0:
				std::cout << "You went with the melee pointy metal stick archetype. Interesting...\n " <<
					" This isn't Kill Bill though, but press 0) Dagger 1) Longsword\n";
				std::cin >> playerChoice2;
				if (playerChoice2 == 0) {
					std::cout << "You do realize there is a choice here? Alright screw it dagger it is. \n";
					Player1.weapon.Sword::DAGGER;
					weaponSlected = true;
				}
				else if (playerChoice2 == 1)
				{
					std::cout << "There was a better choice here believe it or not and you picked it. Heres a longsword and a cookie.\n";
					Player1.weapon.Sword::LONGSWORD;
					weaponSlected = true;
				}
				break;
			case 1:
				std::cout << "Probably the most sensible choices. In a world where a gun exists would you pick a stick or a grenade.\n" <<
					" You'd pick gun right? 0) Glock 1) Colt45\n";
				std::cin >> playerChoice2;
				if (playerChoice2 == 0) {
					std::cout << "Okay... Weird Pick, however, you do you glock selected.\n";
					Player1.weapon.Pistol::GLOCK;
					Player1.weaponChoice = 0;
					weaponSlected = true;
				}
				else if (playerChoice2 == 1) {
					std::cout << "Colt45. Logical gun choice as it's not great but its not the glock either.\n";
					Player1.weapon.Pistol::COLT45;
					Player1.weaponChoice = 1;
					weaponSlected = true;
				}
				break;
			case 2:
				std::cout << "Pointy stick, gun, and you choose grenade. Oh whelp maybe you can do something with it."
					<< "Don't blow yourself up now\n 0) Frag Grenade 1) Flash Bang";
				std::cin >> playerChoice2;
				if (playerChoice2 == 0)
				{
					std::cout << "I don't know what's better here, frag or flash? you do you. Frag Grenade selected.\n";
					Player1.weapon.Grenade::FRAG_GRENADE;
					weaponSlected = true;
				}
				else if (playerChoice2 == 1)
				{
					std::cout << "Flashbang, yeah, either way I mean, atleast with the frag you'd have some lethality.\n";
					Player1.weapon.Grenade::FLASHBANG;
					weaponSlected = true;
				}
				break;
			}
		}
		else if (Player1.CurrentRank == Player1.RankType[2]) {
			switch (playerChoice) {
			case 0:
				std::cin >> playerChoice2;
				std::cout << "I thought you would know better by now. But what do I know, you're the one beating this game.\n " <<
					" 0) Dagger 1) Longsword 2) Legolas Sword\n";
				if (playerChoice2 == 0) {
					std::cout << "You seem to enjoy the dagger experience. Dagger selected.\n";
					Player1.weapon.Sword::DAGGER;
					weaponSlected = true;
				}
				else if (playerChoice2 == 1)
				{
					std::cout << "This wasn't the better choice this time around. Longsword selected.\n";
					Player1.weapon.Sword::LONGSWORD;
					weaponSlected = true;
				}
				else if (playerChoice2 == 2)
				{
					std::cout << "Ah a cultured Tolkien fan I see, or are you a fan of the movies? Or both?\n Legolas Sword selected.\n";
					Player1.weapon.Sword::LEGOLAS_SWORDS;
					weaponSlected = true;
				}
				break;

			case 1:
				std::cout << "Ah the perennial gun conosieur or is this the first time? You're going to be in for a great time.\n" <<
					" 0) Glock 1) Colt45 2) Desert Eagle\n";
				std::cin >> playerChoice2;
				if (playerChoice2 == 0) {
					std::cout << "Uh... You really hate the meta huh. Glock selected.\n";
					Player1.weapon.Pistol::GLOCK;
					Player1.weaponChoice = 0;
					weaponSlected = true;
				}
				else if (playerChoice2 == 1) {
					std::cout << "Colt45 was great like a rank ago...Colt45 selected\n";
					Player1.weapon.Pistol::COLT45;
					Player1.weaponChoice = 1;
					weaponSlected = true;
				}
				else if (playerChoice2 == 2) {
					std::cout << "Rational decision. Desert Eagle selected.\n";
					Player1.weapon.Pistol::DESERT_EAGLE;
					Player1.weaponChoice = 2;
					weaponSlected = true;
				}
				break;
			case 2:
				std::cout << "You know you picked grenade and you probably thought to yourself we're going to give you better stuff.\n" <<
					"\n. Its Funny of you to think that but you're wrong.\n 0) Frag Grenade 1) Flash Bang 2) Smoke Grenade";
				std::cin >> playerChoice2;
				if (playerChoice2 == 0)
				{
					std::cout << "I don't know what's better here, frag or flash? you do you. Frag Grenade selected.\n";
					Player1.weapon.Grenade::FRAG_GRENADE;
					weaponSlected = true;
				}
				else if (playerChoice2 == 1)
				{
					std::cout << "Flashbang, yeah, either way I mean, atleast with the frag you'd have some lethality.\n";
					Player1.weapon.Grenade::FLASHBANG;
					weaponSlected = true;
				}
				else if (playerChoice2 == 2)
				{
					std::cout << "Smoke Grenade huh. What are you going to do chuck it at them and suffocate them?\n";
					Player1.weapon.Grenade::SMOKE;
					weaponSlected = true;
				}
				break;

			}
		}
		else if (Player1.CurrentRank == Player1.RankType[3])
		{
			switch (playerChoice) {
			case 0:
				std::cin >> playerChoice2;
				std::cout << "I thought you would know better by now. But what do I know, you're the one beating this game.\n " <<
					" 0) Dagger 1) Longsword 2) Legolas Sword 3) Excalibur\n";
				if (playerChoice2 == 0) {
					std::cout << "There was only one real choice here. Dagger selected.\n";
					Player1.weapon.Sword::DAGGER;
					weaponSlected = true;
				}
				else if (playerChoice2 == 1)
				{
					std::cout << "I uh... Okay.. Longsword selected.\n";
					Player1.weapon.Sword::LONGSWORD;
					weaponSlected = true;
				}
				else if (playerChoice2 == 2)
				{
					std::cout << "This wasn't the best choice this time around, but I'll allow it. Legolas Swords selected\n";
					Player1.weapon.Sword::LEGOLAS_SWORDS;
					weaponSlected = true;
				}
				else if (playerChoice2 == 3)
				{
					std::cout << "Excalibur selected. Need I say more?\n";
					Player1.weapon.Sword::EXCALIBUR;
					weaponSlected = true;
				}
				else
				{
					std::cout << "You forgot to enter a valid input. \n";
				}

				break;

			case 1:
				std::cout << "Ah the perennial gun conosieur or is this the first time? You're going to be in for a great time.\n" <<
					" 0) Glock 1) Colt45 2) Desert Eagle 3) Raging Bull\n";
				std::cin >> playerChoice2;
				if (playerChoice2 == 0) {
					std::cout << "Uh... You really hate the meta huh. Glock selected.\n";
					Player1.weapon.Pistol::GLOCK;
					weaponSlected = true;
				}
				else if (playerChoice2 == 1) {
					std::cout << "Colt45 was great like a rank ago...Colt45 selected\n";
					Player1.weapon.Pistol::COLT45;
					weaponSlected = true;
				}
				else if (playerChoice2 == 2) {
					std::cout << "Rational decision. Desert Eagle selected.\n";
					Player1.weapon.Pistol::DESERT_EAGLE;
					Player1.weaponChoice = 2;
					weaponSlected = true;
				}
				else if (playerChoice2 == 3) {
					std::cout << "The most meta decision you can make. Raging bull selected\n";
					Player1.weapon.Pistol::RAGING_BULL;
					Player1.weaponChoice = 3;
					weaponSlected = true;
				}
				else {
					std::cout << "Enter a valid number you nit\n";
				}
				break;
			case 2:
				std::cout << "You know you picked grenade and you probably thought to yourself we're going to give you better stuff.\n" <<
					"\n. Its Funny of you to think that but you're wrong.\n 0) Frag Grenade 1) Flash Bang 2) Smoke Grenade 3) Molotov";
				std::cin >> playerChoice2;
				if (playerChoice2 == 0)
				{
					std::cout << "I don't know what's better here, frag or flash? you do you. Frag Grenade selected.\n";
					Player1.weapon.Grenade::FRAG_GRENADE;
					weaponSlected = true;
				}
				else if (playerChoice2 == 1)
				{
					std::cout << "Flashbang, yeah, either way I mean, atleast with the frag you'd have some lethality.\n";
					Player1.weapon.Grenade::FLASHBANG;
					weaponSlected = true;
				}
				else if (playerChoice2 == 2)
				{
					std::cout << "Smoke Grenade huh. What are you going to do chuck it at them and suffocate them?\n";
					Player1.weapon.Grenade::SMOKE;
					weaponSlected = true;
				}
				else if (playerChoice == 3)
				{
					std::cout << "Molotov. Don't burn yourself.\n";
					Player1.weapon.Grenade::MALOTOV;
					weaponSlected = true;
				}
				break;

			}
		}
	} while (!weaponSlected);
}

void Player::PistolSingleShot(Player& player)
{
	std::uniform_int_distribution<int> singleshot(0, 10);
	double chance = singleshot(rng) * .50 + player.accuracy;
	if (player.glockammo > 0) {
		if (chance > 12)
		{
			std::cout << "Hit the enemy for " << player.glockDamage[1];
		}
		player.glockammo -= 1;
	}
	else {
		std::cout << "Not enough ammo.";
	}
}

void Player::PistolMultiShot(Player& player)
{
	std::uniform_int_distribution<int> ShotAttempts(2, 6);
	std::uniform_int_distribution<int> shotaccuracy(0, 10);
	int shots = ShotAttempts(rng);
	if (player.glockammo - shots >= 0)
	{
		for (int i = 0; i < shots; i++)
		{
			double chance = shotaccuracy(rng) * .20 + player.accuracy;
			if (chance > 10) {
				std::cout << "Hit for " << player.glockDamage[2] << '\n';
				player.glockammo--;
			}
			else {
				std::cout << "Miss\n";
			}
		}
	}
}

void Player::PistolThrow(Player& player)
{
	std::uniform_int_distribution<> ThrowChance(1, 5);
	int throwing = ThrowChance(rng);
}

void Player::PistolWhip(Player& player)
{
}



void Player::AttackEnemy(Player &player, const class Enemy& enemy)
{
	if (weaponChoice == 0 || weaponChoice == 1 || weaponChoice == 2 || weaponChoice == 3)
		std::cout << "0) SingleShot 1) Multshot 2) Pistol Whip 3) Throw weapon \n";
	int playerAttack{};
	std::cin >> playerAttack;
	if(playerAttack == 0){
		PistolSingleShot(player);
	}
	else if (playerAttack == 1) {
		PistolMultiShot(player);
	}
	else if (playerAttack == 2) {
		PistolWhip(player);
	}
	else if (playerAttack == 3) {
		PistolThrow(player);
	}
}

void Player::CheckAmmoType(){
	if (weaponChoice == 0)
	{
		if (glockammo == 0)
		{
			std::cout << "You seem to have picked the wrong ammunition for the job. I don't know why, but you did.\n" <<
				"Shall I switch ammo for you and do you own job for you? 0) yes 1) no \n";
			int user_input{};
			std::cin >> user_input;
			if (user_input == 0)
			{	
				glockammo = 20;
				colt45ammo = 0;
				DEammo = 0;
				ragingammo = 0;
			}
			else{
				std::cout << "It's your funeral\n";
			}
		}
	}
	else if (weaponChoice == 1) {
		if (colt45ammo == 0)
		{
			std::cout << "You seem to have picked the wrong ammunition for the job. I don't know why, but you did.\n" <<
				"Shall I switch ammo for you and do you own job for you? 0) yes 1) no \n";
			int user_input{};
			std::cin >> user_input;
			if (user_input == 0)
			{
				glockammo = 0;
				colt45ammo = 20;
				DEammo = 0;
				ragingammo = 0;
			}
			else {
				std::cout << "It's your funeral\n";
			}
		}
	}
	else if (weaponChoice == 2) {
		if (glockammo == 0)
		{
			std::cout << "You seem to have picked the wrong ammunition for the job. I don't know why, but you did.\n" <<
				"Shall I switch ammo for you and do you own job for you? 0) yes 1) no \n";
			int user_input{};
			std::cin >> user_input;
			if (user_input == 0)
			{
				glockammo = 0;
				colt45ammo = 0;
				DEammo = 12;
				ragingammo = 0;
			}
			else {
				std::cout << "It's your funeral.\n";
			}
		}
	}
	else if (weaponChoice == 3) {
		if (glockammo == 0)
		{
			std::cout << "You seem to have picked the wrong ammunition for the job. I don't know why, but you did.\n" <<
				"Shall I switch ammo for you and do you own job for you? 0) yes 1) no \n";
			int user_input{};
			std::cin >> user_input;
			if (user_input == 0)
			{
				glockammo = 0;
				colt45ammo = 0;
				DEammo = 0;
				ragingammo = 12;
			}
			else {
				std::cout << "It's your funeral\n";
			}
		}
	}
}


