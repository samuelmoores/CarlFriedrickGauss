#include "Player.h"

void Player::SetDifficulty(Player& player1)
{
	int difficulty{};
	std::cout << "Choose your rank 0) You're not bad 1)  2)Getting Better 3) Wow look out 4) Touch Grass\n";
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
				std::cout << "Heavy armor selected.\n";
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
					weaponSlected = true;
				}
				else if (playerChoice2 == 1) {
					std::cout << "Colt45. Logical gun choice as it's not great but its not the glock either.\n";
					Player1.weapon.Pistol::COLT45;
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
	} while (!weaponSlected);
}

void Player::Battle()
{
	if (weapon.Pistol::GLOCK || weapon.Pistol::COLT45 || weapon.Pistol::DESERT_EAGLE || weapon.Pistol::RAGING_BULL)
		std::cout << "Choose your attack 0) Single Shot 1)Multiple Shot 2) Pistol Whip 3) Throw Pistol\n";
	else if (weapon.Sword::DAGGER || weapon.Sword::LONGSWORD || weapon.Sword::LEGOLAS_SWORDS || weapon.Sword::EXCALIBUR)
		std::cout << "Choose your attack 0) Quick Attack 1) Strong Attack 2) Combo attack\n";
	else if (weapon.Grenade::FRAG_GRENADE || weapon.Grenade::FLASHBANG || weapon.Grenade::SMOKE || weapon.Grenade::MALOTOV)
		std::cout << "Choose your attack 0) Throw 1) Cook Grenade 2) Smack with Grenade\n";

}
